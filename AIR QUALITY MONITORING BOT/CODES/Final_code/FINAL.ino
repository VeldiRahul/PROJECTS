#define BLYNK_TEMPLATE_ID "TMPL3xAjCoRGQ"
#define BLYNK_TEMPLATE_NAME "CN"
#define BLYNK_AUTH_TOKEN "1gmvWdu1A2bLHwQH0G0fR-8ja9Q6_qE5"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// Wi-Fi credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Vivo T3";
char pass[] = "86882125";

// Sensor pins
#define DHTPIN D1
#define DHTTYPE DHT11
#define MQ2_PIN A0

BlynkTimer timer;

// Motor pins
#define EN1 D1
#define IN1 D2
#define IN2 D3
#define EN2 D4
#define IN3 D5
#define IN4 D6

// Blynk virtual pins
#define FORWARD_BUTTON V3
#define BACK_BUTTON V4
#define LEFT_BUTTON V5
#define RIGHT_BUTTON V6

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  
void readSensors() {
  // Read temperature and humidity
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (!isnan(h) && !isnan(t)) {
    Blynk.virtualWrite(V0, t);
    Blynk.virtualWrite(V1, h);
    Serial.print("Temperature: "); Serial.print(t); Serial.println("°C");
    Serial.print("Humidity: "); Serial.print(h); Serial.println("%");
  }

  // Read gas sensor
  int gasValue = analogRead(MQ2_PIN);
  Blynk.virtualWrite(V2, gasValue);
  Serial.print("Gas Value: "); Serial.println(gasValue);
}

void motorControl(int en, int in1, int in2, int speed) {
  analogWrite(en, speed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

oid motorControl(int en, int in1, int in2, int speed) {
  analogWrite(en, speed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  timer.setInterval(2000L, readSensors);
}

// ====================== Movement Functions ======================
void moveForward() {
  analogWrite(EN1, 255);
  analogWrite(EN2, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBack() {
  analogWrite(EN1, 255);
  analogWrite(EN2, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void moveLeft() {
  analogWrite(EN1, 255);
  analogWrite(EN2, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveRight() {
  analogWrite(EN1, 255);
  analogWrite(EN2, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// ====================== Blynk Control ======================
BLYNK_WRITE(V2) {
  int value = param.asInt();
  if (value == 1) moveForward();
  else stopMotors();
}

BLYNK_WRITE(V3) {
  int value = param.asInt();
  if (value == 1) moveBack();
  else stopMotors();
}

BLYNK_WRITE(V4) {
  int value = param.asInt();
  if (value == 1) moveLeft();
  else stopMotors();
}

BLYNK_WRITE(V5) {
  int value = param.asInt();
  if (value == 1) moveRight();
  else stopMotors();
}
}

void loop() {
  Blynk.run();
  timer.run();

}


