#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const int trigPin = 2;
const int echoPin = 3;
float distance = 0;
int score = 0;
int game = 0;


void setup() {

  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.begin(16,2);
  lcd.clear();

  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
}

void loop() {
  distance = getDistance();
  Serial.print(distance);
  Serial.println("in");
  if (distance <= 5) {
    score += 1;
    delay(1000);
  }

  lcd.setCursor(7, 0);
  lcd.print(score);
  lcd.setCursor(7, 1);
  lcd.print(game);

  if(digitalRead(7) == LOW) {
    game = 1;
  }
  if(digitalRead(6) == LOW) {
    game = 0;
  }
}

float getDistance ()
{
  float echoTime;
  float calculatedDistance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  echoTime = pulseIn(echoPin, HIGH);
  calculatedDistance = echoTime / 148.0;
  return calculatedDistance;
}
