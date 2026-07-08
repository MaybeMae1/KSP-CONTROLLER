# Keyboard-Substitution-Program
A custom Kerbal Space Program Controller made for the Hack Club Stardance event!

# Overview
This project aims to create a custom controller for the game Kerbal Space Program which allows complete control of the game without the keyboard, shooting for a more immersive experience in game. 
This repository contains all code files for each arduino board in the controller, files for all 3d printed parts, a list of components needed to purchase, and instructions for how to build your own!

<img width="1408" height="1008" alt="Screenshot 2026-06-04 054627" src="https://github.com/user-attachments/assets/091b7b62-f863-48ef-9968-fe734054d668" />

# Specifics
This project is based around the Kerbal Simpit Revamped Mod for Kerbal Space Program 1 (the code might work for KSP 2 as well but I dont own a copy so I cant ensure it)

It is built off of 4 Arduino Uno R4 Minima boards, providing enough inputs and outputs to control:

  - All 10 SAS modes
  - All 13 action groups 
  - Staging (with safety switch)
  - Abort (with safety switch)
  - Attitude and translation (including fine control)
  - Throttle & RCS
  - Quick save/load
  - 3 lines of alphanumerical data output with several modes avalible to view on demand
    
The main body and frame of the controller is built from 3D printed PETG sections, screwed together using M3 fasteners and heat set inserts

The top cover is one monolithic black ABS sheet. Holes for the buttons and switches are cut out using a CNC mill, and then the sheet is spray painted white. Finally, a laser cutter is used to burn away the spray paint to create black text.

All code is written in C++ and the PlatformIO extension in VScode is used to upload the code onto the Arduinos.
