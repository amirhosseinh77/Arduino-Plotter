# Arduino Plotter : A Simple DIY Project
This project is a guide to make a simple Arduino-based plotter. You can use this repo for your  DIY plotter or get inspired by the idea of this project for your other works.
Images and gifs of how to make and connect the parts is placed in the [extra](extra/) folder. Final software is also in the [arduino_plotter](arduino_plotter/) folder, but it needs to be tuned depending on your plotter characteristics.

![plotter in action](extra/drawing.gif)

## Hardware
- Arduino Uno (or any other one)
- Mini servo motor (e.g., MG90S Metal Gear Mini Servo)
- 2 small stepper motors (e.g., 5V 24BYJ48 stepper motor)
- SD card reader
- Plotter body parts (Board, Pulley & Thread)

It should be noted that it is better to use the stepper motor drivers instead of directly connecting them to the board, but it worked for me!

## Software
- Arduino IDE ([arduino.cc](https://www.arduino.cc/en/Main/Software))
- Script in any language to treshold image and save binary pixels in a ```txt``` file as 0 or 1 ([sample text file](arduino_plotter/pixels.txt))

## Results

![sample1](extra/sample1.png)

