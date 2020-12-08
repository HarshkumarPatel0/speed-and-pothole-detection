#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

int timer1;
int timer2;

float Time;

int pole1 = 0;
int pole2 = 0;

float Distance = 5.0;
float speed;

int sensor1 = A0;
int sensor2 = A1;

int buzzer = 13;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");

}

void loop()
{
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance of the pothole: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance > 50)
  {
    Serial.println ("");
    Serial.println("Incoming pothole");
  }
  else {
    Serial.println ("");
    Serial.println("No pothole incoming");
  }


  if (digitalRead (sensor1) == LOW && pole1 == 0) {
    timer1 = millis();
    pole1 = 1;
  }

  if (digitalRead (sensor2) == LOW && pole2 == 0) {
    timer2 = millis();
    pole2 = 1;
  }

  if (pole1 == 1 && pole2 == 1) {
    if (timer1 > timer2) {
      Time = timer1 - timer2;
    }
    else if (timer2 > timer1) {
      Time = timer2 - timer1;
    }
    Time = Time / 1000; //convert millisecond to second
    speed = (Distance / Time); //v=d/t
    speed = speed * 3600; //multiply by seconds per hr
    speed = speed / 1000; //division by meters per Km
  }
  if (speed == 0) {

    if (pole1 == 0 && pole2 == 0) {
      Serial.println("No vehicle  detected");
    }
    else {
      Serial.println("Searching vehicle...    ");
    }
  }
  else {

    Serial.print("Speed:");
    Serial.print(speed, 1);
    Serial.println("Km/Hr  ");

    if (speed > 50) {
      Serial.println("  Over Speeding  ");
      digitalWrite(buzzer, HIGH);
    }
    else {
      Serial.println("  Normal Speed   ");
    }
    delay(3000);
    digitalWrite(buzzer, LOW);
    speed = 0;
    pole1 = 0;
    pole2 = 0;
  }
}
