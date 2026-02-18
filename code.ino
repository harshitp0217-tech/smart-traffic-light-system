// Smart Traffic Light System Using Traffic Density
// 2 Lane Adaptive Signal Control

const int sensorLane1 = 2;
const int sensorLane2 = 3;

const int red1 = 4;
const int yellow1 = 5;
const int green1 = 6;

const int red2 = 7;
const int yellow2 = 8;
const int green2 = 9;

void setup() {
  pinMode(sensorLane1, INPUT);
  pinMode(sensorLane2, INPUT);

  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);

  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);
}

void loop() {

  int lane1Traffic = digitalRead(sensorLane1);
  int lane2Traffic = digitalRead(sensorLane2);

  // If lane 1 has more traffic
  if (lane1Traffic == HIGH && lane2Traffic == LOW) {
    lane1Green(8000);  // 8 seconds
    lane2Green(4000);  // 4 seconds
  }
  // If lane 2 has more traffic
  else if (lane2Traffic == HIGH && lane1Traffic == LOW) {
    lane2Green(8000);
    lane1Green(4000);
  }
  // If both equal
  else {
    lane1Green(6000);
    lane2Green(6000);
  }
}

void lane1Green(int duration) {
  digitalWrite(red2, HIGH);
  digitalWrite(green1, HIGH);
  digitalWrite(red1, LOW);
  digitalWrite(green2, LOW);
  
  delay(duration);

  digitalWrite(green1, LOW);
  digitalWrite(yellow1, HIGH);
  delay(2000);
  digitalWrite(yellow1, LOW);
  digitalWrite(red1, HIGH);
}

void lane2Green(int duration) {
  digitalWrite(red1, HIGH);
  digitalWrite(green2, HIGH);
  digitalWrite(red2, LOW);
  digitalWrite(green1, LOW);

  delay(duration);

  digitalWrite(green2, LOW);
  digitalWrite(yellow2, HIGH);
  delay(2000);
  digitalWrite(yellow2, LOW);
  digitalWrite(red2, HIGH);
}
