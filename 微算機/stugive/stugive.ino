const byte LEFT1 = 10;  // IN1
const byte LEFT2 = 9;  // IN2
const byte LEFT_PWM = 11;
const byte RIGHT1 = 8;  // IN3
const byte RIGHT2 = 7;  // IN4
const byte RIGHT_PWM = 6;

byte motorspeed = 100;

int lastDirection = 0; // 0: 前進, -1: 左轉, 1: 右轉
void forward() {
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, 90);
  digitalWrite(RIGHT1, LOW);
  digitalWrite(RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, 95);

}

void backward() {
  digitalWrite(LEFT1, LOW);
  digitalWrite(LEFT2, HIGH);
  analogWrite(LEFT_PWM, motorspeed);
  digitalWrite(RIGHT1, HIGH);
  digitalWrite(RIGHT2, LOW);
  analogWrite(RIGHT_PWM, motorspeed);
}



void turnLeft() {
  analogWrite(LEFT_PWM, 0);
  digitalWrite(RIGHT1, LOW);
  digitalWrite(RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, 110);
}



void turnRight() {
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, 140);
  analogWrite(RIGHT_PWM, 0);
}



void stopMotor() {
  analogWrite(LEFT_PWM, 0);
  analogWrite(RIGHT_PWM, 0);
}



void setup() {
  pinMode(LEFT1, OUTPUT);
  pinMode(LEFT2, OUTPUT);
  pinMode(LEFT_PWM, OUTPUT);
  pinMode(RIGHT1, OUTPUT);
  pinMode(RIGHT2, OUTPUT);
  pinMode(RIGHT_PWM, OUTPUT);
  pinMode(12, INPUT); // 左側紅外線感測器
  pinMode(4, INPUT);  // 右側紅外線感測器

}



void loop() {
  int rightSensor = digitalRead(4);   // 右感測器
  int leftSensor = digitalRead(12);  // 左感測器
  if (rightSensor == 0 && leftSensor == 1) {

    turnLeft();

    lastDirection = -1;

    delay(1);

  }

  else if (rightSensor == 1 && leftSensor == 0) {

    turnRight();

    lastDirection = 1;

    delay(1);

  }

  else if (rightSensor == 0 && leftSensor == 0) {

    // 記憶式循跡 — 根據前一次方向繼續轉

    if (lastDirection == -1) {

      turnLeft();

    }
  }
}
    