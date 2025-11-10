// Motor Driver L293D Pins
#define EN1 D7  // Enable Motor 1
#define IN1 D5  // Motor 1 Direction
#define IN2 D6

#define EN2 D8  // Enable Motor 2
#define IN3 D3
#define IN4 D4

void setup() {
  Serial.begin(115200);

  // Set motor pins as outputs
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(EN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Run movement sequence
  moveForward();
  delay(5000);

  moveRight();
  delay(5000);

  moveLeft();
  delay(5000);

  moveBackward();
  delay(5000);

  stopMotors(); // Stop at the end
}

void loop() {
  // Nothing needed in loop
}

// Movement functions
void moveForward() {
  analogWrite(EN1, 255);
  analogWrite(EN2, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("🚗 Moving Forward");
}

void moveBackward() {
  analogWrite(EN1, 255);
  analogWrite(EN2, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("↩ Moving Backward");
}

void moveRight() {
  analogWrite(EN1, 255);
  analogWrite(EN2, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("↪ Turning Right");
}

void moveLeft() {
  analogWrite(EN1, 255);
  analogWrite(EN2, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("↩ Turning Left");
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("🛑 Motors Stopped");

}
