void setup() {
  delay(100);

  if (initialization() == 0) { //  Wifi,  Redis, NTP Time, I/O, checkSystemReady
    pubSubText = "initialization returned 0";
    pubLog("pub", "ESP_log", pubSubText.c_str());    // log error
  }

}

void loop() {
  checkMsgs("Ready for Tasks/Steps");
  runStep();
  delay(10);
  currentStep = "";

}