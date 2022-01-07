/**
   This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
*/
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
  pinMode(0, INPUT);
  pinMode (2, OUTPUT);

}

void loop() {
  if (bleKeyboard.isConnected()) {
    digitalWrite(2, HIGH);

    if (digitalRead(0) == LOW) {
      delay(500);

      if (digitalRead(0) == LOW) {
        bleKeyboard.press(KEY_RIGHT_ARROW);
        delay(50);
        bleKeyboard.releaseAll();
      }
      else {
        bleKeyboard.press(KEY_LEFT_ARROW);
        delay(50);
        bleKeyboard.releaseAll();
      }
      delay(500);

    }
  }
  else {
    digitalWrite(2, LOW);

  }
}
