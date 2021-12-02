
// Declaring Pins for UltraSonic Sensors.

int  trigPinA = 2, echoPinA = 3;
long durationA, distanceA;

int  trigPinA1 = 5, echoPinA1 = 6;
long durationA1, distanceA1;

int  differenceA;                    // Measures the distance of object between two parallel sensors. 

int  trigPinB = 8, echoPinB = 9;
long durationB, distanceB;

int  trigPinB1 = 11, echoPinB1 = 12;
long durationB1, distanceB1;

int  differenceB;                    // Measures the distance of object between two parallel sensors. 



void setup()                         // Run the code at the begining of the program for one iteration.
{
  Serial.begin(9600);                // To view data in the serial monitor.

  pinMode(trigPinA,  OUTPUT);        // Makes the corresponding pin to act as an output.
  pinMode(echoPinA,  INPUT);         // Makes the corresponding pin to act as an input.

  pinMode(trigPinA1, OUTPUT);
  pinMode(echoPinA1, INPUT);
  
  pinMode(trigPinB,  OUTPUT);
  pinMode(echoPinB,  INPUT);

  pinMode(trigPinB1, OUTPUT);
  pinMode(echoPinB1, INPUT);
}



void loop()                            
{

  // First set of parallel ultrasonic sensors.

  digitalWrite(trigPinA,HIGH);           // Sets the trigPinA high (active) i.e send ultrasonic sound wave.
  delay(1000);                           // High for 1000 milliseconds i.e. 1 second.
  digitalWrite(trigPinA, LOW);           // Resets trigPinA.
  
  durationA = pulseIn(echoPinA, HIGH);   // Returns the sound travel time in milliseconds i.e receive ultrasonic sound wave.
  distanceA = durationA *0.034 /2;       // Calulates the distance.

  Serial.print(distanceA);               // Displays distanceA in the serial monitor.
  Serial.println(" CM DistanceA");

  delay(1000);


  digitalWrite(trigPinA1,HIGH);          // Same as trigPinA.
  delay(1000);
  digitalWrite(trigPinA1, LOW);
  
  durationA1 = pulseIn(echoPinA1, HIGH);
  distanceA1 = durationA1 *0.034 /2;

  Serial.print(distanceA1);
  Serial.println(" CM DistanceA1");

  delay(1000);


  differenceA = distanceA - distanceA1;   // The width of the object between the parallel ultrasonic sensors.
  Serial.print("DifferenceA: ");
  Serial.println(differenceA);
  Serial.println("      ");


  // Second set of parallel ultrasonic sensors.


  digitalWrite(trigPinB,HIGH);           // Same as trigPinA.
  delay(1000);
  digitalWrite(trigPinB, LOW);
  
  durationB = pulseIn(echoPinB, HIGH);
  distanceB = durationB *0.034 /2;

  Serial.print(distanceB);
  Serial.println(" CM DistanceB");

  delay(1000);


  digitalWrite(trigPinB1,HIGH);         // Same as trigPinA.
  delay(1000);
  digitalWrite(trigPinB1, LOW);
  
  durationB1 = pulseIn(echoPinB1, HIGH);
  distanceB1 = durationB1 *0.034 /2;

  Serial.print(distanceB1);
  Serial.println(" CM DistanceB1");

  delay(1000);


  differenceB = distanceB - distanceB1;
  Serial.print("DifferenceB: ");
  Serial.println(differenceB);
  Serial.println("      ");
  
}
