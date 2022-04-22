// defines pins numbers
const int trigPin = 9; // pin on the arduinowhere the trigger pin is connected
const int echoPin = 10;// pin on the arduino where the echo pin is connected
const int led1 = 2; // water level indicator 1
const int led2 = 3; // water level indicator 2
const int led3 = 4; // water level indicator 3
const int led4 = 5; // water level indicator 4
const int PUMP = 12;

// defines variables
int duration, distance;


void setup()
{
  pinMode (led1, OUTPUT);// sets as output
  pinMode (led2, OUTPUT);//sets as output
  pinMode (led3, OUTPUT);//sets as output
  pinMode (led4, OUTPUT);//sets as output
  pinMode (PUMP, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
 }
     
     void loop()
 {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
     
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delay(1000);
digitalWrite(trigPin, LOW);
     
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
   
// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.println("");
Serial.print("Distance: ");
Serial.println(distance);
Serial.println("");
delay (1000);

 if (distance <= 11)
 {
  digitalWrite (PUMP, HIGH);
  Serial.println(" WATER 100% full!!");
  Serial.println("TURN OFF PUMP");
  digitalWrite (led1, HIGH);
  digitalWrite (led2, HIGH);
  digitalWrite (led3, HIGH);
  digitalWrite (led4, HIGH);
 }else
  if( (distance >= 16) && (distance <= 20) )
  {
   Serial.println(" WATER IS 50% full");
   digitalWrite (led1, HIGH);
   digitalWrite (led2, HIGH);
   digitalWrite (led3, HIGH);
   digitalWrite (led4, LOW);
  }
  else
  if( (distance >= 21) && (distance <=27 ) )
  {
   Serial.println(" WATER IS 50% full");
   digitalWrite (led1, HIGH);
   digitalWrite (led2, HIGH);
   digitalWrite (led3, LOW);
   digitalWrite (led4, LOW);
  }
   else
   if (distance >= 28)
   {
   digitalWrite(PUMP, LOW);
   Serial.println (" WATER IS less than 10% full");
   Serial.println ("TURN ON THE PUMP");
   digitalWrite (led1, HIGH);
   digitalWrite (led2, LOW);
   digitalWrite (led3, LOW);
   digitalWrite (led4, LOW);
  }
   
}
