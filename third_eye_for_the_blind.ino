#define trigPin1 13
#define echoPin1 12
#define trigPin2 11
#define echoPin2 10
#define trigPin3 9
#define echoPin3 8
#define buzzer 6
#define motor 7
long sensorOneDuration, sensorTwoDuration, sensorThreeDuration;
long sensorOne, sensorTwo, sensorThree;

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  //For sensor 1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(4);
  sensorOneDuration = pulseIn(echoPin1, HIGH);
  sensorOne = (sensorOneDuration/2)/29.1;

  //For sensor 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(4);
  sensorTwoDuration = pulseIn(echoPin2, HIGH);
  sensorTwo = (sensorTwoDuration/2)/29.1;

  //For sensor 3
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(4);
  sensorThreeDuration = pulseIn(echoPin3, HIGH);
  sensorThree = (sensorThreeDuration/2)/29.1;

  if(sensorOne < 60){
    digitalWrite(buzzer, HIGH);
    digitalWrite(motor, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    digitalWrite(motor, LOW);
    delay(500);
  }
  else if(sensorTwo < 30){
    digitalWrite(buzzer, HIGH);
    digitalWrite(motor, HIGH);
    delay(250);
    digitalWrite(buzzer, LOW);
    digitalWrite(motor, LOW);
    delay(250);
  }
  else if(sensorThree > 65){
    digitalWrite(buzzer, HIGH);
    digitalWrite(motor, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    digitalWrite(motor, LOW);
    delay(300);
  }
  else if(sensorOne <=60 && sensorOne>= 30){
    digitalWrite(buzzer, HIGH);
    digitalWrite(motor, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    digitalWrite(motor, LOW);
    delay(500);
  }
  else if(sensorTwo <=30 && sensorTwo >= 15){
    digitalWrite(buzzer, HIGH);
    digitalWrite(motor, HIGH);
    delay(250);
    digitalWrite(buzzer, LOW);
    digitalWrite(motor, LOW);
    delay(250);
  }
  else if(sensorTwo <= 75 && sensorThree>= 56){
    digitalWrite(buzzer, HIGH);
    digitalWrite(motor, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    digitalWrite(motor, LOW);
    delay(300);
  }
  else{
    digitalWrite(buzzer, LOW);
    digitalWrite(motor, LOW);
  }
}
