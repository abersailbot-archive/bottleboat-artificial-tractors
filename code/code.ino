#include <Wire.h>
int HMC6352Address = 0x42;
// This is calculated in the setup() function
int slaveAddress;
byte headingData[2];
int i, headingValue;
void setup()
{
// Shift the device's documented slave address (0x42) 1 bit right
// This compensates for how the TWI library only wants the
// 7 most significant bits (with the high bit padded with 0)
slaveAddress = HMC6352Address >> 1;   // This results in 0x21 as the address to pass to TWI
Serial.begin(9600);
Wire.begin();
}
void loop()
{
  // Send a "A" command to the HMC6352
  // This requests the current heading data
  Wire.beginTransmission(slaveAddress);
  Wire.write("A");              // The "Get Data" command
  Wire.endTransmission();
  delay(10);                   // The HMC6352 needs at least a 70us (microsecond) delay
  // after this command.  Using 10ms just makes it safe
  // Read the 2 heading bytes, MSB first
  // The resulting 16bit word is the compass heading in 10th's of a degree
  // For example: a heading of 1345 would be 134.5 degrees
  Wire.requestFrom(slaveAddress, 2);        // Request the 2 byte heading (MSB comes first)
  i = 0;
  while(Wire.available() && i < 2)
  { 
    headingData[i] = Wire.read();
    i++;
  }
  headingValue = headingData[0]*256 + headingData[1];  // Put the MSB and LSB together //headingValue comes out as 0 to 3600 
  Serial.print("Current heading: ");
 // Serial.print(int (headingValue / 10));     // The whole number part of the heading
  //Serial.print(".");
  //Serial.print(int (headingValue % 10));     // The fractional part of the heading
  //Serial.println(" degrees");
  Serial.println(headingValue);
  delay(500);
} 
//Calibrate compass for North. 

//IMPORTANT NOTE A5 is Yellow wire, SCL
//IMPORTANT NOTE A4 is green, SDA
//Make sure wires for compass come out of pot up - greep bottle cap on bottom, red on top.

//Input from compass (hmc6352)

//Read input from compass on the arduino
    /* pseudocode 
 PID:
 Error = Setpoint - Actual
 Integral = Integral + (Error*dt)
 Derivative = (Error - Previous_error)/dt
 Drive = (Error*kP) + (Integral*kI) + (Derivative*kD)
 Previous_error = Error
 wait(dt)
GOTO PID 
     */
    

//If at 0 degrees, no change in propeller direction









  


