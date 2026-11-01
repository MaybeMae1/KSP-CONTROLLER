# Keyboard-Substitution-Program
A custom Kerbal Space Program Controller made for the Hack Club Stardance event!

# Overview
This project aims to create a custom controller for the game Kerbal Space Program which allows complete control of the game without the keyboard, shooting for a more immersive experience in game. 
This repository contains all code files for each arduino board in the controller, files for all 3d printed parts, a list of components needed to purchase, and instructions for how to build your own!

<img width="1408" height="1008" alt="Screenshot 2026-06-04 054627" src="https://github.com/user-attachments/assets/091b7b62-f863-48ef-9968-fe734054d668" />

# Specifics
 <a href="https://docs.google.com/document/d/1xSK9mFhKcA0diG72t0lU2Y3A8E2znB5cS-Skv4FzVgU">Parts List</a> 
<a href="https://cad.onshape.com/documents/f623b2689f20fb0d288adf48/w/e5e7af8b431c1f25b27c2839/e/9daf789d907df18f4bb0781c">CAD Files (hosted on Onshape)</a>

This project is based around the Kerbal Simpit Revamped Mod for Kerbal Space Program 1 (the code might work for KSP 2 as well but I dont own a copy so I cant ensure it)

It is built off of 2 Arduino Uno R4 Minima boards, providing enough inputs and outputs to control:
 
  - Staging (with safety switch)
  - Abort (with safety switch)
  - Attitude control (including fine control)
  - Throttle & RCS
  - 1 lines of alphanumerical data output with several modes avalible to view on demand
    
The main body and frame of the controller is built from 3D printed PETG sections glued together, with hardware attached via m3 fasteners and heat set inserts.

To build the top cover
1. Spraypaint one ABS Sheet white
2. Use a cnc router and the included top cover file to cut the holes
2a. If you do not have a cnc router, print out some to scale engineering drawing of the cover. Place them on the cover and mark all of the holes, then hand cut and sand to the proper dimention
3. 3D print the files for all of the key switch holders
4. Line up the key switch holders on the part and drill out the holes for the fasteners (this is done now to make sure holes line up with the actual parts even if they are printed or cut weird)
5. Insert the heat set inserts into the holes in the parts

To build the rest of the case
1. Take one ABS sheet and cut it into 4 pieces 16 in by 3 in
2. Cut 2 of those pieces down to 12in by 3 in
3. Cut a rectangular hole on one of the 12 inch pieces, roughly an inch long and .5 in tall (this is where the wires come into)
4. Glue the 4 sides vertically onto another piece of ABS
5. Take the leftovers from cutting down the side pieces and cut them into smaller chunks, about 1.5 inches by 1.5 inches
6. Glue 4 of these chunks into the top corners of the case, and glue the rest wherever elsew you would like along the top perimeter (these are where the top cover rests.

All code is written in C++ and the PlatformIO extension in VScode is used to upload the code onto the Arduinos.
