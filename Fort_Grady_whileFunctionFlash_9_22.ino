/***************************************************|
 *Grady Fort 9/22/17                                |
 *Flash Without Delay Function                      |
 *Test in arduino IDE robot c code syntax for vex.  |
 *Purpose: flash LED without using wait function,   |
 *allowing for the function to be used whithin other|
 *programs without delay                            |
                                                    |
 *To be made a function:                            |
   *-void?                                          |
   *-include variables                              |
 ***************************************************/ 

unsigned long previousMillis = 0;   //store
int interval = 1000;
unsigned long currentMillis = 0;    //(repeated)for convenience
int ledState = 0

task main()
{  
 unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == 0) {
      ledState = 1;
    } else {
      ledState = 0;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(flashlight, ledState);     //??motor function for flashlight;
  }

