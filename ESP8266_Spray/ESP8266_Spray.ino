// Wifi Start..................................................
// this sketch will build for the ESP8266 or ESP32 platform
#ifdef HAL_ESP32_HAL_H_ // ESP32
#include <WiFiClient.h>
#include <WiFi.h>
#else
#ifdef CORE_ESP8266_FEATURES_H // ESP8266
#include <ESP8266WiFi.h> // <Wifi.h> for ESP32CAM <ESP8266WiFi.h> for ESP8266
#endif
#endif

#define WIFI_SSID "????"
#define WIFI_PASSWORD "????"

#include <Esp.h> // common header for ESP 
#include <string>
#include<iostream>
const char* ssid = "????";     //replace this with your WiFi network name
const char* password = "????";  //replace this with your WiFi network password
// Wifi End....................................................

// Redis Start...............................................................
#include <Redis.h> // a small fast database with pubsub. needs wifi

#define REDIS_ADDR "192.168.1.209" // static IP on router
#define REDIS_PORT 6379
#define REDIS_PASSWORD ""

WiFiClient redisConn;
Redis redis(redisConn);
// Redis End...................................................

// GPIO Start.................................................
// IO definitions - pins
const int pumPin = 14; //Safe
// GPIO End.................................................

// IO definitions - NotON flags
bool pumON=false;

// Incoming and executable task definitions
String pubSubText = "";
String currentTask = "";
String currentStep = "";

// Function Prototypes Start..................................
// msging
void checkRedis();
void redisDisConnect();
String pubSub(const char*, const char*, const char*);
String pubLog(const char*, const char*, const char*);
void checkMsgs(String);
// initialization
void connectToWifi();
void connectToRedis();
void configureIO();
int initialization();
// gpio
void runPump();

// Steps
void runStep();

// Function Prototypes End..................................