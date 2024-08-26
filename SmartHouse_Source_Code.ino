#include <Servo.h>

// Smart House Project

Servo servo;

int servo_pin = 9;
int led_pin = 7;  // Renamed to avoid conflict
char data; 

void controlGarage(int value) {  
  if (value == 0) {
    servo.write(180);
    Serial.print("Closing Garage. Received Data: ");
    Serial.println(data);
  } else {
    servo.write(90);
    Serial.print("Opening Garage. Received Data: ");
    Serial.println(data);
  }
}

void controlLED(int value) {  // Renamed to avoid conflict
  if (value == 1) {
      digitalWrite(led_pin, HIGH);
      Serial.print("LED ON. Received Data: ");
      Serial.println(data);
  } else {
      digitalWrite(led_pin, LOW);
      Serial.print("LED OFF. Received Data: ");
      Serial.println(data);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT); 
  servo.attach(servo_pin);
}

void loop() {
  while (Serial.available() > 0) {
    data = Serial.read();

    if (data == '1') {
      controlLED(1);  
    } 
    
    else if (data == '2') {
      controlLED(0);  
    } 
    
    else if (data == '8') {
      controlGarage(1);  
    } 
    
    else if (data == '9') {
      controlGarage(0); 
    } 
    
    else {
      Serial.print("Undefined Output: ");
      Serial.println(data);
    }
  }
}
