//左馬達控制設定
const byte LEFT1 = 9; //IN1
const byte LEFT2 = 8; //IN2
const byte LEFT_PWM = 11;
//右馬達控制設定
const byte RIGHT1 = 7; //IN3
const byte RIGHT2 = 6; //IN4
const byte RIGHT_PWM = 5;
//設定PWM輸出值(代表的是車子的速度)
byte motorspeed = 255;

void forward(){
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, 255);//158 180
  //右輪·因在小車上馬達安装方向左右兩個是相
  digitalWrite(RIGHT1, LOW);
  digitalWrite (RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, 255);//190 
}

void backward(){ //後退
  digitalWrite(LEFT1, LOW);
  digitalWrite (LEFT2, HIGH);
  analogWrite(LEFT_PWM, motorspeed);
  digitalWrite(RIGHT1, HIGH);
  digitalWrite(RIGHT2, LOW);
  analogWrite(RIGHT_PWM, motorspeed);
}

void turnLeft(){//左轉
  //左輪不動,右輪動(速度為0)
  //analogWrite(LEFT_PWM, 0);
  digitalWrite(RIGHT1, LOW);
  digitalWrite (RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, motorspeed);
  analogWrite(LEFT_PWM, 100);

}

void turnLeft_1(){//左轉，微調

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
  analogWrite(LEFT_PWM, motorspeed);
  analogWrite(RIGHT_PWM, 100);
}


void search_left(){//找路_左

  digitalWrite(RIGHT1, LOW);
  digitalWrite (RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, 150);
  analogWrite(LEFT_PWM, 0);

}
void search_right(){//找路_右
  digitalWrite(RIGHT1, HIGH);
  digitalWrite (RIGHT2, LOW);
  analogWrite(RIGHT_PWM, 0);
  analogWrite(LEFT_PWM, 1500);

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

  pinMode(13,INPUT);//中
  pinMode(12,INPUT); //右側红外線威測器
  pinMode(1,INPUT);//左側红外線威測器
  int a=0;
}
void loop() {
  while (digitalRead(12)==LOW and digitalRead(1)==LOW and digitalRead(13)==HIGH){//中黑
    forward();
    delay(5);
    stopMotor();
    delay(5);
  }
  if (digitalRead(12)==HIGH and digitalRead(1)==LOW ){//左轉
    if(digitalRead(13)==HIGH){
      turnLeft();
    delay(5);
    stopMotor();
    delay(20);
    }
    else{
      search_left();
    }
    
   
  }else if(digitalRead(1)==HIGH and digitalRead(12)==LOW ){//右轉
    if(digitalRead(13)==HIGH){
      turnRight();
    delay(5);
    stopMotor();
    delay(10);
    }
    else{
      search_right();
    }
    
  }
  delay(5);
}
