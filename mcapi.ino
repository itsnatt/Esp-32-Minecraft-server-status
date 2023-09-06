#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <LiquidCrystal_I2C.h>


const char* ssid = "JTM274A";
const char* password = "wismajtm";
const char* apiUrl = "https://api.mcstatus.io/v2/status/java/122.248.43.86:2013"; 
int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

 bool httpget;
 bool loops = 0;
 String oop;
    bool publicStatus;
    int onlinePlayers;
    String publichost;
    int port;
    String motd;
    JsonArray nameCleanArray;

void setup() {
  Serial.begin(115200);
  delay(1000);
    // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
   lcd.setCursor(0, 0);
  // Koneksi ke WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
     lcd.print("Connecting...   ");
  }
}

void loop() {
  getdata();

  lcd.clear();
  lcd.setCursor(0, 0);
   lcd.print("||| GPLB SMP |||");
  lcd.setCursor(0, 1);
 lcd.print("Status: ");
  lcd.print(publicStatus ? "Online" : "Offline");

  delay(3000); 
      lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IP ");
  lcd.print(publichost);
  lcd.setCursor(0, 1);
  lcd.print("Port ");
  lcd.print(port);

  delay(3000); 
      
   int numPlayers = nameCleanArray.size();
   int loop2 = onlinePlayers * 16;
   if(onlinePlayers > 0)
   {
     loops = 1;
   }
   else
   {
     loops = 0;
   }

  while (loops) {
    lcd.clear();
       lcd.setCursor(0, 0);
        lcd.print("Online Players:");
    for (int i = 0; i < onlinePlayers; i++) {
            const char* nameClean = nameCleanArray[i]["name_clean"];
            lcd.setCursor(0, 1); // Geser karakter ke kiri
            lcd.print(nameClean);
        delay(1000); 
         lcd.setCursor(0, 1);
         lcd.print("               ");
      }
     loops = 0;
  }
  lcd.clear();
  lcd.setCursor(0, 0);
   lcd.print("||| GPLB SMP |||");
  lcd.setCursor(0, 1);
   lcd.print(onlinePlayers);
   lcd.print(" / 100 online");
  delay(5000);
}



void getdata()
{
  // Mengirim permintaan HTTP GET
  HTTPClient http;
  http.begin(apiUrl);
  int httpCode = http.GET();

  if (httpCode > 0) {
    String payload = http.getString();
    DynamicJsonDocument jsonDoc(2048); // Sesuaikan dengan ukuran dokumen JSON Anda
    deserializeJson(jsonDoc, payload);

    oop = jsonDoc["host"];

     bool Status = jsonDoc["online"];
        publicStatus = Status;
     onlinePlayers = jsonDoc["players"]["online"];
     String host = jsonDoc["host"];
      publichost = host;
     port = jsonDoc["port"];
     String motd = jsonDoc["motd"]["clean"];
      // Mendapatkan daftar "name_clean"
     nameCleanArray = jsonDoc["players"]["list"];
    
    httpget = true;

  }
  else 
  {
    httpget = false;
  }

  http.end();
}

