//左馬達控制設定
const byte LEFT1 = 10; //IN1
const byte LEFT2 = 9; //IN2
const byte LEFT_PWM = 11;
//右馬達控制設定
const byte RIGHT1 = 8; //IN3
const byte RIGHT2 = 7; //IN4
const byte RIGHT_PWM = 6;
//設定PWM輸出值(代表的是車子的速度)
byte motorspeed = 255;

void forward(){
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, 180);//158 180
  //右輪·因在小車上馬達安装方向左右兩個是相
  digitalWrite(RIGHT1, LOW);
  digitalWrite (RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, 190);//190 
}

void turnLeft(){//左轉
  //左輪不動,右輪動(速度為0)
  //analogWrite(LEFT_PWM, 0);
  digitalWrite(RIGHT1, LOW);
  digitalWrite (RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, 255);
  analogWrite(LEFT_PWM, 0);

}

void turnRight(){//右轉
  //右輪不動,左輪動(速度為0)
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, 255);
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

  pinMode(5,INPUT);//中
  pinMode(12,INPUT); //左側红外線威測器
  pinMode(4,INPUT);//左側红外線威測器

}
void loop() {
  if (digitalRead(12)==HIGH and digitalRead(4)==LOW ){//左轉
    turnLeft();
    delay(5);
  }else if(digitalRead(4)==HIGH and digitalRead(12)==LOW ){//右轉
    turnRight();
    delay(5);
  }
  else if(digitalRead(5)==HIGH){
    forward();
    delay(5);
    stopMotor();
    delay(5);
  }
  else if(digitalRead(12)==LOW and digitalRead(4)==LOW and digitalRead(5)==LOW){
    stopMotor();
    delay(10);  
    }
}