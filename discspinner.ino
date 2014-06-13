int analogIn = A2;
int analogIn2 = A3;
int analogIn3 = A4;
int analogIn4 = A5;
int pot = 0;
int pot2 = 0;
int pot3 = 0;
int pot4 = 0;
int sensor = 0;
int sensor2 = 0;
int sensor3 = 0;
int sesnor4 = 0;
const int ledPin = 10;
const int ledPin2 = 6;
long previousMillis = 0;
long previousMillis2 = 0;
long interval = 1000;
int ledState = LOW;
int ledState2 = LOW;

void setup() {
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
 pinMode(13, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
}

void loop(){
 
  sensor = analogRead(A2);
  sensor2 = analogRead(A3);
  sensor3 = analogRead(A4);
  int sensor4 = analogRead(A5);
  pot = map(sensor, 0, 1023, 0, 255);
  pot2 = map(sensor2, 0, 1023, 0, 3000);
  pot3 = map(sensor3, 0, 1023, 0, 3000);
  pot4 = map(sensor4, 0, 1023, 0, 255);
  
  digitalWrite(13, HIGH);
  digitalWrite(8, LOW);
  analogWrite(11, pot4);
  
  digitalWrite(12, HIGH);
  digitalWrite(9, LOW);
  analogWrite(3, pot);
  
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > pot2) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
    
  }
  if(currentMillis - previousMillis2 > pot3) {
    // save the last time you blinked the LED 
    previousMillis2 = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledState2 == LOW)
      ledState2 = HIGH;
    else
      ledState2 = LOW;
  digitalWrite(ledPin2, ledState2);
  }
}
