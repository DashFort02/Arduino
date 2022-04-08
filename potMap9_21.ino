/*Grady Fort 9/21/17                                |
Potentiometer Map                                   |
Test in arduino IDE robot c code syntax for vex.    |
Purpose (pseudo): use map function to turn servo the|
same degrees; inverts servo and turns on left motor |
when the bump switch is pressed                     |
 ***************************************************/ 

/*code to add whe base code is tested (after set servo):
    if(SensorValue(bumpSwitch) == 1){
    startMotor(rightMotor, 127);
    sDegrees = -1 * sDegrees;                 // invert servo
   }
   if(SensorValue(bumpSwitch) == 1 && SensorValue(limitSwitch) == 0){
    startMotor(rightMotor, -127);
    startMotor(rightMotor, -127);     
   }
   else
     {
      startMotor(port4, 0);
     }
 */

int sDegrees = 0;                // servo degrees
int potRaw = 0;                  // potentiometer raw data
const int miliS = 2000;          // !wait time for servo to invert will not change

task main()
{
   SensorValue(potentiometer) = potRaw
   sDegrees = map(potRaw, 0, 1023, -127, 127); // calculate raw data from potentiometer to 
    setServo(port2,sDegrees);
    if(sDegrees <= 0){                        // servo degrees will be negative if bumper switch is pressed 
   wait1Msec(miliS);                          // wait for servo to invert
   }                                          //curly brackets surounding if and else function
    else {
    wait1Msec(10);                            // continuity
    }
}

