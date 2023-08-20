#include <AFMotor.h>

 
AF_DCMotor motor(2, MOTOR12_64KHZ);

int  sensorAnalogPin = A8;    // Select the Arduino input pin to accept the Sound Sensor's analog output 
int  sensorDigitalPin = 22;    // Select the Arduino input pin to accept the Sound Sensor's digital output
int  analogValue = 0;         // Define variable to store the analog value coming from the Sound Sensor
int  digitalValue;            // Define variable to store the digital value coming from the Sound Sensor
int  Led13 = 30;              // Define LED port; this is the LED built in to the Arduino (labled L)
                              // When D0 from the Sound Sensor (connnected to pin 3 on the
                              // Arduino) sends High (voltage present), L will light. In practice, you
                              // should see LED13 on the Arduino blink when LED2 on the Sensor is 100% lit.
                              

void setup()
{
  Serial.begin(9600);               // The IDE settings for Serial Monitor/Plotter (preferred) must match this speed
  pinMode(sensorDigitalPin,INPUT);  // Define pin 3 as an input port, to accept digital input
  pinMode(Led13,OUTPUT);            // Define LED13 as an output port, to indicate digital trigger reached
  motor.setSpeed(200);
}

void loop(){
  analogValue = analogRead(sensorAnalogPin); // Read the value of the analog interface A0 assigned to digitalValue 
  digitalValue=digitalRead(sensorDigitalPin); // Read the value of the digital interface 3 assigned to digitalValue 
  Serial.println(analogValue); // Send the analog value to the serial transmit interface
  
  if(digitalValue==HIGH)      // When the Sound Sensor sends signla, via voltage present, light LED13 (L)
  {
    digitalWrite(Led13,HIGH);
    motor.run(FORWARD);
  }
  else
  {
    digitalWrite(Led13,LOW);
    motor.run(RELEASE);
  }
  
  delay(50);                  // Slight pause so that we don't overwhelm the serial interface
}