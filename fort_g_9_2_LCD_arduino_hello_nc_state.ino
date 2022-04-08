/*
  Hello NC State LCD (Crystal Ball template)

  This sketch is written to accompany Project 11 in the Arduino Starter Kit

  Parts required:
  - 220 ohm resistor
  - 10 kilohm resistor
  - 10 kilohm potentiometer
  - 16x2 LCD screen
  - tilt switch

  created 1 August 2020
  By Grady Fort

  http://www.arduino.cc/starterKit
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// set up a constant for the tilt switch pin
const int switchPin = 6;

// variable to hold the value of the switch pin
int switchState = 0;

// variable to hold previous value of the switch pin
int prevSwitchState = 0;

// a variable to choose which reply from the crystal ball
int count = 0;

void setup() {
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);

  // set up the switch pin as an input
  pinMode(switchPin, INPUT);

  // Print a message to the LCD.
  lcd.print("----------------");
  // set the cursor to column 0, line 1
  // line 1 is the second row, since counting begins with 0
  lcd.setCursor(0, 1);
  // print to the second line
  lcd.print("----------------");
}

void loop() {
  // check the status of the switch
  switchState = digitalRead(switchPin);

  // compare the switchState to its previous state
  if (switchState != prevSwitchState) {
    // if the state has changed from HIGH to LOW you know that the ball has been
    // tilted from one direction to the other
    if (switchState == LOW) {
      // add 1
      count = count + 1;
      // reset if 8 numbers (2*8=16)
      if (count == 8){
        count = 0;
      }
      // clean up the screen before printing a new reply
      lcd.clear();
      // set the cursor to column 0, line 1
      lcd.setCursor(0, 1);
      // print some text
      lcd.print(" ");
      // move the cursor to the first line
      lcd.setCursor(0, 0);

      // choose a saying to print based on the value in reply
      switch (count) {
        case 0:
          //do not print anything
          break;
  
        case 1:
          lcd.print("He");
          break;

        case 2:
          lcd.print("Hell");
          break;

        case 3:
          lcd.print("Hello ");
          break;

        case 4:
          lcd.print("Hello NC");
          break;

        case 5:
          lcd.print("Hello NC St");
          break;

        case 6:
          lcd.print("Hello NC State");
          break;

        case 7:
          lcd.print("Hello NC State!!");
          lcd.setCursor(0, 1);
          lcd.print("!!!!!!!!!!!!!!!!");
          break;
      }
    }
  }
  // save the current switch state as the last state
  prevSwitchState = switchState;
}
