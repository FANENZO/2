const byte LEFT1 = 9; //IN1
const byte LEFT2 = 8; //IN2
const byte LEFT_PWM = 11;
//右馬達控制設定
const byte RIGHT1 = 7; //IN3
const byte RIGHT2 = 6; //IN4
const byte RIGHT_PWM = 5;
//設定PWM輸出值(代表的是車子的速度)
byte motorspeed = 110;

void forward(){
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, 95);
  digitalWrite(RIGHT1, LOW);
  digitalWrite (RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, 128);
  //右輪
}

void turnLeft(){//左轉
  //左輪不動,右輪動(速度為0)
  analogWrite(LEFT_PWM, 0);
  digitalWrite(RIGHT1, LOW);
  digitalWrite (RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, motorspeed);
}

void turnRight(){//右轉
  //右輪不動,左輪動(速度為0)
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, motorspeed);
  analogWrite(RIGHT_PWM, 0);
}

void stopMotor() {
  analogWrite(LEFT_PWM, 0);
  analogWrite(RIGHT_PWM, 0);
}

void setup(){ 
  //設定每一個PIN的模式
  pinMode(LEFT1, OUTPUT);
  pinMode(LEFT2, OUTPUT);
  pinMode(LEFT_PWM, OUTPUT);
  pinMode(RIGHT1, OUTPUT);
  pinMode(RIGHT2, OUTPUT);
  pinMode(RIGHT_PWM, OUTPUT);
}

void loop() {
  forward();
  delay(2000); //前進2秒
  turnRight();
  delay(500); //右轉2秒
  turnLeft();
  delay(1400); //左轉2秒
  
  forward();
  delay(3000); //前進2秒
  stopMotor();
  delay(2000); //停止2秒
}
