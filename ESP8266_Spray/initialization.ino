void connectToWifi() { //Standard functions to start the wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to the WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
      delay(250);
      Serial.print(".");
  }
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void connectToRedis() {
  if (!redisConn.connect(REDIS_ADDR, REDIS_PORT)) // to connect to Redis
  {
      Serial.println("Failed to connect to the Redis server!");
      return;
  }

  auto connRet = redis.authenticate(REDIS_PASSWORD); // to connect to Redis with auto reconnect
  if (connRet == RedisSuccess)
  {
      Serial.println("Connected to the Redis server!");
      pubSubText = "IP Address: " + WiFi.localIP().toString();
      pubLog("pub", "ESP_log", pubSubText.c_str()); // ESP_LOG logs running status
      pubSubText = "Connected to the Redis server!";
      pubLog("pub", "ESP_log", pubSubText.c_str());
  }
  else
  {
      Serial.printf("Failed to authenticate to the Redis server! Errno: %d\n", (int)connRet);
      pubSubText = "Failed to authenticate to the Redis server!";
      pubLog("pub", "ESP_log", pubSubText.c_str());
      return;
  }
}

void configureIO() {

  // setting Output pins
  pinMode(pumPin, OUTPUT); // set to 14 in ESP_spray

  digitalWrite(pumPin, HIGH);  // set high for Relay OFF
  delay(1);
}

int initialization() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  // Wifi
  connectToWifi();
  // Redis
  connectToRedis();
  // IO
  configureIO();

  return 1;
   
}