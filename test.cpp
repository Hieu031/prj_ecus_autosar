#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <ArduinoJson.h>

// CONFIG
const char* ssid = "WifiFree_2";
const char* password = "88888888";

#define API_KEY         "AIzaSyBdYfutaORWiNzbZccND8Rhh0kTIeuj1SQ"
#define DATABASE_URL    "https://autosar01-default-rtdb.asia-southeast1.firebasedatabase.app"
#define USER_EMAIL      "nth280102@gmail.com"
#define USER_PASSWORD   "Matkhau0123@"

// Firebase objects
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
Firebase_ESP_Client firebase;

void setup() {
  // Bật Serial để log
  Serial.begin(115200);
  delay(1000);
  Serial.println("Bắt đầu khởi động ESP32...");

  // Kết nối WiFi
  WiFi.begin(ssid, password);
  Serial.print("Đang kết nối WiFi: ");
  Serial.println(ssid);

  int wifiTries = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
    wifiTries++;
    if (wifiTries > 30) {
      Serial.println("\Không thể kết nối WiFi. Kiểm tra lại SSID/Password.");
      return;
    }
  }
  Serial.println("\nWiFi đã kết nối thành công!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  // Cấu hình Firebase
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  firebase.begin(&config, &auth);
  firebase.reconnectWiFi(true);
  Serial.println("🔧 Đang khởi tạo kết nối Firebase...");

  int firebaseTries = 0;
  while (!Firebase.ready()) {
    delay(100);
    Serial.print("#");
    firebaseTries++;
    if (firebaseTries > 100) {
      Serial.println("\nFirebase chưa sẵn sàng. Kiểm tra cấu hình.");
      return;
    }
  }
  Serial.println("\nFirebase đã sẵn sàng!");
}

void loop() {
  Serial.println("\nVòng lặp mới bắt đầu...");

  // Sinh giá trị mô phỏng
  float temp = random(250, 350) / 10.0;  // 25.0 - 35.0 °C
  float hum = random(400, 800) / 10.0;   // 40.0 - 80.0 %

  Serial.printf("Dữ liệu mô phỏng: Temp = %.2f °C, Hum = %.2f %%\n", temp, hum);

  // Gửi dữ liệu lên Firebase
  Serial.println("Đang gửi dữ liệu lên Firebase...");
  bool ok1 = firebase.RTDB.setFloat(&fbdo, "/SHT31/Temperature", temp);
  bool ok2 = firebase.RTDB.setFloat(&fbdo, "/SHT31/Humidity", hum);

  if (ok1 && ok2) {
    Serial.println("Dữ liệu đã gửi thành công!");
  } else {
    Serial.println("Lỗi khi gửi Firebase:");
    Serial.println("    " + fbdo.errorReason());
  }

  delay(5000);  // Chờ 5 giây để gửi vòng tiếp theo
}
