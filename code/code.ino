
void setup() {

Serial.begin(9600); 

//Calibrate compass for North. 

//Input from compass

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
    
//If compass is between 1 and 1800 degrees, rotate propeller direction

//If at 0 degrees, no change in propeller direction




}


void loop() {


  
}

