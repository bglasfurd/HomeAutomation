#include "time.h"

unsigned long intervalShort, previousMillisShort;

void setup() {
  Serial.begin(9600);
  pinMode(A2, OUTPUT);

  digitalWrite(A2, HIGH);  //Pump OFF - using Blue Relay

  // nextStart init
  intervalShort = 60l * 1000l;  // 1 min
  previousMillisShort = (unsigned long)millis();
  Serial.println("ARD is ready - in 1 min interval at startup");
}

void loop() {
  if (((unsigned long)millis() - previousMillisShort) >= intervalShort) {
    Serial.println("Pump ON");
    digitalWrite(A2, LOW);  //Pump ON
    delay(240000); // 4 mins pumping time

    digitalWrite(A2, HIGH);  //Pump OFF
    delay(1000);
    Serial.println("Pump OFF");

    intervalShort = 3l * 3600l * 1000l;  // 3 hours
    Serial.println("ARD is ready - in 3 hour intervalShort");
    previousMillisShort = (unsigned long)millis();
  }
}