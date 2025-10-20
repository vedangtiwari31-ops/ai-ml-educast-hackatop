#include <Servo.h>

Servo horizontalServo;
Servo verticalServo;

int ldrTopLeft = A2;
int ldrTopRight = A1;
int ldrBottomLeft = A3;
int ldrBottomRight = A0;

int horizontalPos = 90;
int verticalPos = 90;

int tolerance = 50;

void setup() {
  horizontalServo.attach(2);
  verticalServo.attach(9);

  horizontalServo.write(horizontalPos);
  verticalServo.write(verticalPos);

  Serial.begin(9600);
  delay(1000);
}

void loop() {
  int topLeft = analogRead(ldrTopLeft);
  int topRight = analogRead(ldrTopRight);
  int bottomLeft = analogRead(ldrBottomLeft);
  int bottomRight = analogRead(ldrBottomRight);

  int avgTop = (topLeft + topRight) / 2;
  int avgBottom = (bottomLeft + bottomRight) / 2;
  int avgLeft = (topLeft + bottomLeft) / 2;
  int avgRight = (topRight + bottomRight) / 2;

  int verticalDifference = avgTop - avgBottom;
  int horizontalDifference = avgLeft - avgRight;

  if (abs(horizontalDifference) > tolerance) {
    horizontalPos += (horizontalDifference > 0) ? 1 : -1;
  }

  if (abs(verticalDifference) > tolerance) {
    verticalPos += (verticalDifference > 0) ? 1 : -1;
  }

  horizontalPos = constrain(horizontalPos, 0, 180);
  verticalPos = constrain(verticalPos, 0, 180);

  horizontalServo.write(horizontalPos);
  verticalServo.write(verticalPos);

  Serial.print("TL: "); Serial.print(topLeft);
  Serial.print(" TR: "); Serial.print(topRight);
  Serial.print(" BL: "); Serial.print(bottomLeft);
  Serial.print(" BR: "); Serial.print(bottomRight);
  Serial.print(" | H: "); Serial.print(horizontalPos);
  Serial.print(" V: "); Serial.println(verticalPos);

  delay(50);
}
