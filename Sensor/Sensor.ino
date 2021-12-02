#include <Servo.h>

// Declaring Pins for UltraSonic Sensors.

int  trigPinA = 2, echoPinA = 3;     // Connect the trigger pin of ultrasonic sensor to pin2 & echo to pin3 of Arduino.
long durationA, distanceA;

int  trigPinA1 = 5, echoPinA1 = 6;
long durationA1, distanceA1;

long  differenceA;                    // Measures the distance of object between two parallel sensors. 

int  trigPinB = 8, echoPinB = 9;
long durationB, distanceB;

int  trigPinB1 = 11, echoPinB1 = 12;
long durationB1, distanceB1;

long  differenceB;                    // Measures the distance of object between two parallel sensors. 

Servo servoA;                        // Initialize the servo.  
Servo servoB; 

void setup()                         // Run the code at the begining of the program for one iteration.
{
  Serial.begin(9600);                // To view data in the serial monitor.

  // First set of sensors.

  pinMode(trigPinA,  OUTPUT);        // Makes the corresponding pin to act as an output.
  pinMode(echoPinA,  INPUT);         // Makes the corresponding pin to act as an input.

  pinMode(trigPinA1, OUTPUT);
  pinMode(echoPinA1, INPUT);
  
  servoA.attach(4);                  // Connect the signal pin of servo to pin4 of Arduino.
  servoA.write(90);                  // The position at 90 degrees is the base.
  delay(100);

  //Second set of sensors.
  
  pinMode(trigPinB,  OUTPUT);
  pinMode(echoPinB,  INPUT);

  pinMode(trigPinB1, OUTPUT);
  pinMode(echoPinB1, INPUT);

  servoB.attach(10);                    
  servoB.write(90);
  delay(100);

}



void loop()                              // The code is excuted continuosly.           
{

  // First set of parallel ultrasonic sensors.

  digitalWrite(trigPinA,HIGH);           // Sets the trigPinA high (active) i.e send ultrasonic sound wave.
  delay(500);                           // High for 1000 milliseconds i.e. 1 second.
  digitalWrite(trigPinA, LOW);           // Resets trigPinA.
  
  durationA = pulseIn(echoPinA, HIGH);   // Returns the sound travel time in milliseconds i.e receive ultrasonic sound wave.
  distanceA = durationA *0.034 /2;       // Calulates the distance.

  Serial.print(distanceA);               // Displays distanceA in the serial monitor.
  Serial.println(" CM DistanceA");

  delay(500);


  digitalWrite(trigPinA1,HIGH);          // Same as trigPinA.
  delay(500);
  digitalWrite(trigPinA1, LOW);
  
  durationA1 = pulseIn(echoPinA1, HIGH);
  distanceA1 = durationA1 *0.034 /2;

  Serial.print(distanceA1);
  Serial.println(" CM DistanceA1");

  delay(500);


  differenceA = distanceA - distanceA1;   // The width of the object between the parallel ultrasonic sensors.
  Serial.print("DifferenceA: ");
  Serial.println(differenceA);
  Serial.println("      ");


  
  if(differenceA < 20.000)
  {
   servoA.write(180);                   // Moves the servo clockwise i.e towards right side.
   delay(500);
  }


  // Second set of parallel ultrasonic sensors.


  digitalWrite(trigPinB,HIGH);           // Same as trigPinA.
  delay(500);
  digitalWrite(trigPinB, LOW);
  
  durationB = pulseIn(echoPinB, HIGH);
  distanceB = durationB *0.034 /2;

  Serial.print(distanceB);
  Serial.println(" CM DistanceB");

  delay(500);


  digitalWrite(trigPinB1,HIGH);         // Same as trigPinA.
  delay(500);
  digitalWrite(trigPinB1, LOW);
  
  durationB1 = pulseIn(echoPinB1, HIGH);
  distanceB1 = durationB1 *0.034 /2;

  Serial.print(distanceB1);
  Serial.println(" CM DistanceB1");

  delay(500);


  differenceB = distanceB - distanceB1;
  Serial.print("DifferenceB: ");
  Serial.println(differenceB);
  Serial.println("      ");

   if(differenceB < 20.00)
  {
   servoB.write(180);
   delay(500);
  }

  servoA.write(90);                      // To reset the base position of the servo motors.
  servoB.write(90);
  delay(500);
  
}
