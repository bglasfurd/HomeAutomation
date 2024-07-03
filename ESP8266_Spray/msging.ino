void redisDisConnect() {
  redisConn.stop();
  Serial.print("Connection closed!");
}

String pubSub(const char* pubsub, const char* feed, const char* text) {
  String retVal = "";
  bool redisSet;
// sub
  if (pubsub == "sub") {
    retVal = redis.get(feed);
    redis.set(feed, "");
  } else if (pubsub == "pub") {
    redisSet = redis.set(feed, text);
  }
  if (redisSet) {
      retVal = redisSet ? "True" : "False";
  }  
  return retVal;
}

String pubLog(const char* pubsub, const char* feed, const char* text) {
  String retVal = "";
  bool redisSet;
  pubSubText = "ESP.pub: " + String(text);
  redisSet = redis.lpush("ESP_log", pubSubText.c_str());
  if (redisSet) {
      retVal = redisSet ? "True" : "False";
  }  
  return retVal;
}

void checkMsgs(String psText) {
  pubSub("pub", "SCH", psText.c_str());
  psText = "";
  psText = pubSub ("sub", "ESP", "");
  delay(10);

  if (psText == "Pump ON") {
    currentStep = "pumpon";
    Serial.println(currentStep);
  }
}