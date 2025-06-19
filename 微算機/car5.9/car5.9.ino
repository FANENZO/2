//左馬達控制設定
const byte LEFT1 = 10; //IN1
const byte LEFT2 = 9; //IN2
const byte LEFT_PWM = 11;
//右馬達控制設定
const byte RIGHT1 = 8; //IN3
const byte RIGHT2 = 7; //IN4
const byte RIGHT_PWM = 6;
//設定PWM輸出值(代表的是車子的速度)

void forward(){
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, 120);//158 180
  //右輪·因在小車上馬達安装方向左右兩個是相
  digitalWrite(RIGHT1, LOW);
  digitalWrite (RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, 150);//190 
}
void backward(){
  digitalWrite(LEFT1,LOW );
  digitalWrite(LEFT2, HIGH);
  analogWrite(LEFT_PWM, 120);//158 180
  //右輪·因在小車上馬達安装方向左右兩個是相
  digitalWrite(RIGHT1, HIGH);
  digitalWrite (RIGHT2, LOW);
  analogWrite(RIGHT_PWM, 150);//190 
}


void turnLeft(){//左轉
  //左輪不動,右輪動(速度為0)
  //analogWrite(LEFT_PWM, 0);
  digitalWrite(RIGHT1, LOW);
  digitalWrite (RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, 180);
  analogWrite(LEFT_PWM, 100);

}

void turnLeft1(){//左轉
  //左輪不動,右輪動(速度為0)
  //analogWrite(LEFT_PWM, 0);
  digitalWrite(RIGHT1, LOW);
  digitalWrite (RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, 180);
  analogWrite(LEFT_PWM, 0);

}


void turnRight(){//右轉
  //右輪不動,左輪動(速度為0)
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, 180);
  analogWrite(RIGHT_PWM, 100);
}
void turnRight1(){//右轉
  //右輪不動,左輪動(速度為0)
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, 180);
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

  pinMode(2,INPUT);//中
  pinMode(12,INPUT); //左側红外線威測器
  pinMode(4,INPUT);//右側红外線威測器
}

void loop() {
  bool midSensor = digitalRead(2);
  bool leftSensor = digitalRead(12);
  bool rightSensor = digitalRead(4);

  if (midSensor == 1) {
    if (leftSensor == 1 && rightSensor == 0){
      turnLeft(); // 只有左邊在黑線上，向左轉
      delay(5);}
    if (rightSensor == 1 && leftSensor == 0) {
      turnRight(); // 只有右邊在黑線上，向右轉
      delay(5);  }
    if (rightSensor == 1 && leftSensor == 1) {
      forward(); // 中間在黑線上，直行
      delay(5);  }
    if (rightSensor == 0 && leftSensor == 0) {
      forward(); // 中間在黑線上，直行
      delay(5);   } 
   }
   else {
    if (leftSensor == 1 && rightSensor == 0){
      turnLeft1(); // 只有左邊在黑線上，向左轉
      delay(5);}
    if (rightSensor == 1 && leftSensor == 0) {
      turnRight1(); // 只有右邊在黑線上，向右轉
      delay(5);  }
    if (leftSensor == 0 && rightSensor == 0 ) {
      stopMotor(); }// 三個都不在黑線上，後退 (或停止、尋找)
  }
}