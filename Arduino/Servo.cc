#include <Servo.h>

Servo myservo;
int pos = 90;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char signal = Serial.read();
    if (signal == '0') {
      for (int i = 0; i <= 180; i += 1) {
        myservo.write(i);
        delay(15);
      }
      for (int i = 180; i >= 0; i -= 1) {
        myservo.write(i);
        delay(15);
      }
      Serial.write("0");
    }
    else if (signal == '1' && pos > 0) {
      pos -= 5;
      myservo.write(pos);
      delay(15);
      Serial.write("1");
    }
    else if (signal == '2' && pos < 180) {
      pos += 5;
      myservo.write(pos);
      delay(15);
      Serial.write("2");
    }
  }
}
