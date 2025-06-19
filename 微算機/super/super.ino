const byte LEFT1 = 10;  // IN1
const byte LEFT2 = 9;  // IN2
const byte LEFT_PWM = 11;
const byte RIGHT1 = 8;  // IN3
const byte RIGHT2 = 7;  // IN4
const byte RIGHT_PWM = 6;

const byte trigPin = 3;  // 超音波觸發腳位
const byte echoPin = 5;  // 超音波接收腳位

byte motorspeed = 100;
long duration;
int distance;

int lastDirection = 0; // 0: 前進, -1: 左轉, 1: 右轉
int douge = 0;//1避障中
// 避障相關設定
const int OBSTACLE_THRESHOLD_CM = 20; // 障礙物偵測距離閾值 (公分)

void setup() {
  // 設定馬達控制腳位為 OUTPUT
  pinMode(LEFT1, OUTPUT);
  pinMode(LEFT2, OUTPUT);
  pinMode(LEFT_PWM, OUTPUT);
  pinMode(RIGHT1, OUTPUT);
  pinMode(RIGHT2, OUTPUT);
  pinMode(RIGHT_PWM, OUTPUT);

  // 設定超音波感測器腳位
  pinMode(trigPin, OUTPUT); // Trig 腳位為輸出
  pinMode(echoPin, INPUT);  // Echo 腳位為輸入

  // 初始化序列埠用於除錯 (可選)
  Serial.begin(19200);
  Serial.println("Ultrasonic Obstacle Avoidance Started!");
}

// 測量距離的函數 (回傳公分)
long getDistanceCm() {
  // 清除 trigPin 上的高電平
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // 發送 10 微秒的超音波脈衝
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 測量 echoPin 接收到高電平的持續時間
  long duration = pulseIn(echoPin, HIGH);

  // 將時間轉換為距離 (公分)
  // 聲音在空氣中傳播速度約為 340 公尺/秒 或 0.034 公分/微秒
  // 距離 = (時間 * 聲音速度) / 2 (因為是來回距離)
  long distanceCm = duration * 0.034 / 2;

  // 避免無效讀數 (例如感測器範圍外)
  if (distanceCm == 0 || distanceCm > 100) { // HC-SR04 通常最大範圍約 400cm
    return 100; // 返回最大值表示沒有偵測到障礙物 (或太遠)
  }
  return distanceCm;
}

// 馬達控制函數
void forward() {
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, 100); // 設定左馬達速度

  digitalWrite(RIGHT1, LOW);
  digitalWrite(RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, 120); // 設定右馬達速度 (可能需要微調以確保直行)
}

void stopMotor() {
  analogWrite(LEFT_PWM, 0);
  analogWrite(RIGHT_PWM, 0);
}

// 主循環
void loop() {
  long distance = getDistanceCm(); // 測量前方距離

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 25) {
    stopMotor();
    delay(1000);
    analogWrite(LEFT_PWM, 200);//右轉
    analogWrite(RIGHT_PWM, 0);
    delay(350);
    stopMotor();
    delay(1000);
    analogWrite(LEFT_PWM, 120);//直
    analogWrite(RIGHT_PWM, 200);
    delay(450);
    analogWrite(LEFT_PWM, 80);//左
    analogWrite(RIGHT_PWM, 170);
    delay(200);
    stopMotor();
    delay(1000);
    
    analogWrite(LEFT_PWM, 120);//直
    analogWrite(RIGHT_PWM, 180);
    delay(150);
    // analogWrite(LEFT_PWM, 120);//直
    // analogWrite(RIGHT_PWM, 100);
    // delay(50);
  } else {
    // 沒有偵測到障礙物，前進
    forward();
  }
  // 為了避免過於頻繁的動作，可以在每次迴圈結束時短暫延遲
  // 避免超音波感測器讀取頻率過高導致不穩定
  delay(50);
}