int timer1;
int timer2;

float Time;

int pole1 = 0;
int pole2 = 0;

float distance = 5.0;
float speed;

int sensor1 = A0;
int sensor22 = A1;

int buzzer = 13;

void setup(){
  pinMode(sensor1, INPUT);
  pinMode(sensor22, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

 
}

void loop() {
if(digitalRead (sensor1) == LOW && pole1==0){timer1 = millis(); pole1=1;}

if(digitalRead (sensor22) == LOW && pole2==0){timer2 = millis(); pole2=1;}

if (pole1==1 && pole2==1){
     if(timer1 > timer2){Time = timer1 - timer2;}
else if(timer2 > timer1){Time = timer2 - timer1;}
 Time=Time/1000;//convert millisecond to second
 speed=(distance/Time);//v=d/t
 speed=speed*3600;//multiply by seconds per hr
 speed=speed/1000;//division by meters per Km
}

if(speed==0){ 
 
if(pole1==0 && pole2==0){Serial.println("No car  detected");}
                    else{Serial.println("Searching...    ");} 
}
else{

    Serial.println("Speed:");
    Serial.println(speed,1);
    Serial.println("Km/Hr  ");

  if(speed > 50){Serial.print("  Over Speeding  "); digitalWrite(buzzer, HIGH);}
            else{Serial.print("  Normal Speed   "); }
    delay(3000);
    digitalWrite(buzzer, LOW);
    speed = 0;
    pole1 = 0;
    pole2 = 0;
 }
}
