

int trigPin = 8, echoPin = 9;
long duration, distance;

int trigPin1 = 4, echoPin1 = 5;
long duration1, distance1;

int difference;

void setup() 
{
  Serial.begin(9600); 

  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
}



void loop() 
{

  digitalWrite(trigPin,HIGH);
  delay(1000);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = duration *0.034 /2;

  Serial.print(distance);
  Serial.println(" CM Distance");


  delay(1000);



  digitalWrite(trigPin1,HIGH);
  delay(1000);

  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);

  distance1 = duration1 *0.034 /2;

  Serial.print(distance1);
  Serial.println(" CM Distance1");


  delay(1000);


  difference = distance - distance1;
  Serial.print("Difference: ");
  Serial.println(difference);

  Serial.println("      ");
  
}
