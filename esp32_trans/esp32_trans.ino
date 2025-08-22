#include <WiFi.h>
// #include <FirebaseESP32.h>
#include <Firebase_ESP_Client.h>
#include <ArduinoJson.h>
#include <time.h>

// CONFIG
#define RXD2 16 // Receive data from STM32F4
#define TXD2 17 // Unuse Transmit but need declaring

const char* ssid = "MyHieuB";
const char* password = "tamsotam";
// const char* ssid = "WifiFree_2";
// const char* password = "88888888";

// Define Firebase config
#define API_KEY         "AIzaSyBdYfutaORWiNzbZccND8Rhh0kTIeuj1SQ"
#define DATABASE_URL    "https://autosar01-default-rtdb.asia-southeast1.firebasedatabase.app" // URL project in Firebase Homepage 
#define USER_EMAIL      "nth280102@gmail.com"
#define USER_PASSWORD   "Matkhau0123@"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

Firebase_ESP_Client firebase;

void getTime(){
  // Set NTP, timezone of VietNam (UTC+7)
  configTime(7 * 3600, 0, "pool.ntp.org", "time.nist.gov");
  Serial.println("Sychronizing real time (NTP)...");

  // Wait until having real time
  time_t now = time(nullptr);
  int retry = 0;
  while(now < 8 * 3600 * 2 && retry < 30) {
    // Check time whether updated?
    delay(500);
    Serial.print(".");
    now = time(nullptr);
    retry++;
  }

  if (now < 8 * 3600 * 2){
    Serial.println("\nCan't sychronize NTP! Use millis() to get time.");
  }
  else
  {
    Serial.println("\nSychronize time NTP successfully!");
    struct tm timeinfo;
    localtime_r(&now, &timeinfo);
    Serial.printf("Timeline: %02d-%02d-%04d %02d:%02d:%02d\n",
    timeinfo.tm_mday, timeinfo.tm_mon + 1, timeinfo.tm_year + 1900,
    timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
  }
}

// void sendRandomDataToFB(){
//   float temp = random(200, 350) / 10.0;
//   float hum  = random(400, 900) / 10.0;
  
//   // Get real time
//   time_t now;
//   time(&now);

//   // Change format: YYYYMMDD_HHMMSS
//   struct tm timeinfo;
//   localtime_r(&now, &timeinfo);

//   char timeKey[32];
//   strftime(timeKey, sizeof(timeKey), "%Y%m%d_%H%M%S", &timeinfo);

//   // Gen path save as real time
//   String dataPath = "/SHT/history/" + String(timeKey);

//   FirebaseJson json;
//   json.set("Temperature", temp);
//   json.set("Humidity", hum);

//   Serial.printf("Sent data at: %s | temp: %.2f | hum: %.2f\n", timeKey, temp, hum);

//   bool ok = firebase.RTDB.setJSON(&fbdo, dataPath.c_str(), &json);

//   if (ok){
//     Serial.println("Simulation temp and hum oke!");
//   }
//   else
//   {
//     Serial.println("Firebase Error: " + fbdo.errorReason());
//   }
// }

void sendDataSensor(){
  static String uartData = "";
  
  while (Serial2.available()){
    char c = Serial2.read();
    if (c == '\n'){
      Serial.println("Recieve UART: " + uartData);

      // Parse JSON from STM32F4
      StaticJsonDocument<128> doc;
      DeserializationError error = deserializeJson(doc, uartData);

      if (!error) {
        float temp = doc["temp"];
        float hum = doc["hum"];

        // get real time
        time_t now;
        time(&now);

        // change format: YYYYMMDD_HHMMSS
        struct tm timeinfo;
        localtime_r(&now, &timeinfo);

        char timekey[32];
        strftime(timeKey, sizeof(timeKey), "%Y%m%d_%H%M%S", %timeinfo);

        // Gen path save as real time
        String dataPath = "/SHT31_test/history/" + String(timeKey);

        FirebaseJson json;
        json.set("Temperature", temp);
        json.set("Humidity", hum);


        Serial.printf("Sent data at: %s | Temp: %.2f | Hum: %.2f\n",timeKey, temp, hum);

        // Sent data up to Firebase
        bool ok = firebase.RTDB.setJSON(&fbdo, dataPath.c_str(), &json);

        if (ok){
          Serial.println("Upload OK!");
        }
        else
        {
          Serial.println("Firebase Error: " + fbdo.errorReason());
        }
      }
      else
      {
        Serial.println("JSON Parse Error: " + String(error.c_str()));
      }

      uartData = "";
    }
    else
    {
      uartData += c;
    }
  }
  // delay(100);
}

void setup() {
  // // Use to random when simulation temp and hum
  // randomSeed(millis());
  // getTime();

  // Init baudrate and serial uart 
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial.println("Start with ESP32!");
  
  // Config connect wifi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wifi: ");
  Serial.println(ssid);


  int wifiTries = 0;
  while(WiFi.status() != WL_CONNECTED){
    delay(300);
    Serial.print(".");
    wifiTries++;
    if(wifiTries > 30) {
      Serial.println("\n Can't connect to Wifi. Check SSID/Password again!");
      return;
    }

  }
  Serial.println("\nConnected to WiFi!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  // Sync NTP after connected Wifi
  getTime()

  // Config firebase
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;

  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  firebase.begin(&config, &auth);
  firebase.reconnectWiFi(true);
  Serial.println("Initializing connect to Firebase...");

  int firebaseTries = 0;
  while(!Firebase.ready()){
    delay(100);
    Serial.print('#');
    firebaseTries++;
    if(firebaseTries > 100){
      Serial.println("\nCant't connect! Check config agian!");
      return;
    }
  
  }
  Serial.println("\nFirebase is ready!");
}

void loop() {
  Serial.println("\nThe new loop start...");
  // sendRandomDataToFB();
  sendDataSensor();
  delay(5000);
}

