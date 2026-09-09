#include "Arduino.h"
#include "KerbalSimpit.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include <EasyStringStream.h>


KerbalSimpit mySimpit(Serial);
Adafruit_AlphaNum4 display0 = Adafruit_AlphaNum4();
Adafruit_AlphaNum4 display1 = Adafruit_AlphaNum4();
Adafruit_AlphaNum4 display2 = Adafruit_AlphaNum4();


// VARIABLES

const int SAS_SWITCH_PIN = 1;
const int Alt_Warning_Pin = 2;
bool SAS_Switch_State;
bool Desired_SAS_State;
byte currentActionStatus;
// joystick variables
const int X_Potentiometer = A0;
const int Y_Potentiometer = A1;
const int Z_Potentiometer = A2;
const int joystickDeadzone = 4000;
// throttle variables
const int Throttle_Potentiometer = A3;
const int throttle_Deadzone = 3000;
// dbPress_Toggle variables
unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 50;   // the debounce time; increase if the output flickers
int outputState;                    // the current state of the output pin
int buttonState;                    // the current reading from the input pin
int lastButtonState;                // the previous reading from the input pin

//enum for all display states
enum displayStates {
  Auto,
  Orbit,
  Surface,
  Rendezvous,
  Maneuver
};

//Set display state to auto on startup
int displayState = Auto;

//situations the vessel can be in (used for auto display)
enum Situations{
  PreLaunch = 0,
  Flying = 3,
  SubOrbital = 4,
  Orbiting = 5
};

// GAME DATA


// flying and landing info
float currentAltitudeSeaLevel;
float currentAltitudeSurface;
float currentSurfaceVelocity;

// orbital info
float currentVelocity;
float currentPeriapsis;
float currentApoapsis;
float currentInclination;

// docking info
float currentDistanceToTarget;
float currentTargetRelativeVelocity;

// rendezvous info
float currentTimeToNextIntercept;
float currentDistanceAtNextIntercept;
float currentVelocityAtNextIntercept;

// maneuver info
float currentTimeToNextManeuver;
float currentDeltaVNextManeuver;
float currentDurationNextManeuver;

// situation info 
int currentSituation;
bool hasTarget;

// FUNCTIONS

// dbPress_Toggle is a debounced button reader (from the arduino docs) modified to output as a integer
int dbPress_Toggle(int input_pin)
{
  // "borrowed" from the arduino docs bc im not a good programmer

  int reading = digitalRead(input_pin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState)
  {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState)
    {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH)
      {
        outputState = !outputState;
      }
    }
  }
  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;

  return outputState;
}

// maps the yaw axis input bc it acts weirdly compared to pitch and roll
int yawMap(int x)
{
  if (x > 55)
  {
    return map(x, 55, 700, 0, INT16_MAX);
  };
  if (x < 55)
  {
    return map(x, 0, 55, INT16_MIN, 0);
  };
  return 0;
}

// handles joystick Rotational inputs
void joystickRotation(int potX, int potY, int potZ, int deadzoneRange)
{

  rotationMessage rot_msg;

  // read the input on analog pin A0:
  int reading_pitch = analogRead(potX);
  int reading_roll = analogRead(potY);
  int reading_yaw = analogRead(potZ);

  // Convert them in KerbalSimpit range
  int16_t pitch = map(reading_pitch, 0, 1023, INT16_MIN, INT16_MAX);
  int16_t yaw = map(reading_roll, 0, 1023, INT16_MIN, INT16_MAX);
  int16_t roll = yawMap(reading_yaw);

  // Add a deadzone for the axes
  if (-1 * deadzoneRange < pitch && pitch < deadzoneRange)
  {
    pitch = 0;
  };
  if (-1 * deadzoneRange < roll && roll < deadzoneRange)
  {
    roll = 0;
  };
  if (-1 * deadzoneRange < yaw && yaw < deadzoneRange)
  {
    yaw = 0;
  };

  // do some black magic to tell the game how we want to move
  rot_msg.setPitch(-pitch);
  rot_msg.setRoll(roll);
  rot_msg.setYaw(yaw);
  mySimpit.send(ROTATION_MESSAGE, rot_msg);
}

// handles joystick Translational inputs (basically identical to rotation, but now they can be tweaked individually)
void joystickTranslation(int potX, int potY, int potZ, int deadzoneRange)
{

  translationMessage trans_msg; // waow the message is just like me

  // read the input on analog pin A0:
  int reading_x = analogRead(potX);
  int reading_y = analogRead(potY);
  int reading_z = analogRead(potZ);

  // Convert them in KerbalSimpit range
  int16_t x = map(reading_x, 0, 1023, INT16_MIN, INT16_MAX);
  int16_t y = map(reading_y, 0, 1023, INT16_MIN, INT16_MAX);
  int16_t z = yawMap(reading_z);

  // Add a deadzone for the axes
  if (-1 * deadzoneRange < x && x < deadzoneRange)
  {
    x = 0;
  };
  if (-1 * deadzoneRange < y && y < deadzoneRange)
  {
    y = 0;
  };
  if (-1 * deadzoneRange < z && z < deadzoneRange)
  {
    z = 0;
  };

  // do some black magic to tell the game how we want to move
  trans_msg.setX(x);
  trans_msg.setY(y);
  trans_msg.setZ(z);
  mySimpit.send(TRANSLATION_MESSAGE, trans_msg);
}

// handles throttle inputs (its practically the joystick code, just with only one input lol)
void throttleHandler(int potT, int deadzoneRange)
{

  throttleMessage throttle_msg;

  // Read the value of the potentiometer
  int reading = analogRead(potT);

  /* DEPRECATED - the throttle slider is not linear, thus the curved mapping function gives more intuitive control over the throttle in game 
  // Convert it in KerbalSimpit range (only 0 -> INT16_MAX bc throttle cant be negative)
  int throttle = map(reading, 0, 1023, 0, INT16_MAX);
  */

  // Convert it into KerbalSimpit range, now with an exponential curve to account for non-linearity in the slider 
  int throttle = exp(.010163 * (-1 * reading));

  // Add a deadzone for the axis
  if (throttle < deadzoneRange)
  {
    throttle = 0;
  };

  // Send the message
  throttle_msg.throttle = throttle;
  mySimpit.send(THROTTLE_MESSAGE, throttle_msg);
}

// Handles the staging button :mind_blown:
void stagingButtonHandler(int pin){

  if(dbPress_Toggle(pin)){
    mySimpit.activateAction(STAGE_ACTION);
  }

}








// handles incoming messages (duh)
// dont even dare ask me how it works, im just looking at the docs for simpit lol
void messageHandler(byte messageType, byte message[], byte messageSize)
{
  switch (messageType)
  {

  case VELOCITY_MESSAGE:
    if (messageSize == sizeof(velocityMessage))
    {
      velocityMessage myVelocity;
      myVelocity = parseMessage<velocityMessage>(message);
      currentVelocity = myVelocity.orbital;
      currentSurfaceVelocity = myVelocity.surface;
    }
  break;
  
  case ORBIT_MESSAGE:
    if (messageSize == sizeof(orbitInfoMessage))
    {
      orbitInfoMessage myOrbit;
      myOrbit = parseMessage<orbitInfoMessage>(message);
      currentInclination = myOrbit.inclination;
    }
  break;

  case APSIDES_MESSAGE:
    if (messageSize == sizeof(apsidesMessage))
    {
      apsidesMessage myApsides;
      myApsides = parseMessage<apsidesMessage>(message);
      currentApoapsis = myApsides.apoapsis;
      currentPeriapsis = myApsides.periapsis;
    }
  break;

  case MANEUVER_MESSAGE:
    if (messageSize == sizeof(maneuverMessage))
    {
      maneuverMessage myManeuver;
      myManeuver = parseMessage<maneuverMessage>(message);
      currentTimeToNextManeuver = myManeuver.timeToNextManeuver;
      currentDeltaVNextManeuver = myManeuver.deltaVNextManeuver;
      currentDurationNextManeuver = myManeuver.durationNextManeuver;
    }
  break;

  case TARGETINFO_MESSAGE:
    if (messageSize == sizeof(targetMessage))
    {
      targetMessage myTarget;
      myTarget = parseMessage<targetMessage>(message);
      currentTargetRelativeVelocity = myTarget.velocity;
      currentDistanceToTarget = myTarget.distance;
    }
  break;

  case INTERSECTS_MESSAGE:
    if (messageSize == sizeof(intersectsMessage))
    {
      intersectsMessage myIntersect;
      myIntersect = parseMessage<intersectsMessage>(message);
      currentTimeToNextIntercept = myIntersect.timeToIntersect1;
      currentDistanceAtNextIntercept = myIntersect.distanceAtIntersect1;
      currentVelocityAtNextIntercept = myIntersect.velocityAtIntersect1;
    }
  break;

  case FLIGHT_STATUS_MESSAGE:
    if (messageSize == sizeof(flightStatusMessage))
    {
      flightStatusMessage myStatus;
      myStatus = parseMessage<flightStatusMessage>(message);
      currentSituation = myStatus.vesselSituation;
      hasTarget = myStatus.hasTarget();
    }
  break;

  case ALTITUDE_MESSAGE:
    // Checking if the message is the size we expect is a very basic
    // way to confirm if the message was received properly.
    if (messageSize == sizeof(altitudeMessage))
    {
      // Create a new Altitude struct
      altitudeMessage myAltitude;
      // Convert the message we received to an Altitude struct.
      myAltitude = parseMessage<altitudeMessage>(message);
      currentAltitudeSeaLevel = myAltitude.sealevel;
      currentAltitudeSurface = myAltitude.surface;
    }
  break;

  case ACTIONSTATUS_MESSAGE:
    if (messageSize == 1)
    {
      currentActionStatus = message[0];

      if (currentActionStatus & SAS_ACTION)
      {
        digitalWrite(LED_BUILTIN, HIGH);
      }
      else
      {
        digitalWrite(LED_BUILTIN, LOW);
      }
    }
    break;
  }
}

// STUFF THAT RUNS

void setup()
{
  // Open connection
  Serial.begin(115200);

  // set up pins
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SAS_SWITCH_PIN, INPUT);

  // setup displays
  display0.begin(0x70);  // pass in the address
  display1.begin(0x71);
  display2.begin(0x72);

  // handshake with plugin, prints message to screen and turns of led when connected
  digitalWrite(LED_BUILTIN, HIGH);
  while (!mySimpit.init())
  {
    delay(100);
  }
  mySimpit.printToKSP("Connected", PRINT_TO_SCREEN);
  digitalWrite(LED_BUILTIN, LOW);

  // tells the library to run the messageHandler function when receiving messages
  mySimpit.inboundHandler(messageHandler);

  // tells the plugin to send certain messages regularly when in flight
  mySimpit.registerChannel(ACTIONSTATUS_MESSAGE);
  mySimpit.registerChannel(ALTITUDE_MESSAGE);
}

void loop()
{
  // Check for new messages
  mySimpit.update();

  /*
  SAS_Switch_State = digitalRead(SAS_SWITCH_PIN);

  if(SAS_Switch_State){
    Desired_SAS_State = !Desired_SAS_State;
  }
  */

  /*
  Desired_SAS_State = dbPress_Toggle(SAS_SWITCH_PIN);

  // Update the SAS to match the state, only if a change is needed to avoid spamming commands.
  if(Desired_SAS_State){
    mySimpit.printToKSP("Activate SAS!");
    mySimpit.activateAction(SAS_ACTION);
  }
  if(!Desired_SAS_State){
    mySimpit.printToKSP("Desactivate SAS!");
    mySimpit.deactivateAction(SAS_ACTION);
  }
  */

  joystickRotation(X_Potentiometer, Y_Potentiometer, Z_Potentiometer, joystickDeadzone);

  throttleHandler(Throttle_Potentiometer, throttle_Deadzone);

  stagingButtonHandler(SAS_SWITCH_PIN);
}
