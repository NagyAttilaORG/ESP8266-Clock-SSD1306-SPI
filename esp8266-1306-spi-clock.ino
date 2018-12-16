
/* 
 * Internet Clock for SSD1306 SPI 7pin based 128x64 OLED module using ESP8266 NodeMCU 
 */

//ido
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>               // include NTPClient library
#include <TimeLib.h>
//ido
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// If using software SPI (the default case):
#define OLED_MOSI  13   //D1
#define OLED_CLK   14   //D0
#define OLED_DC    2
#define OLED_CS    15
#define OLED_RESET 16

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

const char *ssid     = "YOUR WIRELESS NAME";
const char *password = "YOUR WIRELESS PASSWORD";

WiFiUDP ntpUDP;

// 'time.nist.gov' is used (default server) with +1 hour offset (3600 seconds) 60 seconds (60000 milliseconds) update interval
NTPClient timeClient(ntpUDP, "time.nist.gov", 3600, 60000);

void setup()   {                
//  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  //wifi
  WiFi.begin(ssid, password);

  Serial.print("Connecting.");
  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("connected");
  //Wifi

  timeClient.begin();
}

char Time[] = "     ";
//char Time2[] = "  ";
byte last_second, minute_, hour_, wday, day_, month_, year_;
byte second_ = 10;
byte kettospont = 1;

void loop()
{

  timeClient.update();
  unsigned long unix_epoch = timeClient.getEpochTime();  
  
  static unsigned long thisMicros = 0;
  static unsigned long lastMicros = 0;
  display.clearDisplay();
  display.setCursor(6,2);
  display.setTextSize(4);
  
  if (second_ % 30 == 0)
  {
    second_ = second(unix_epoch); 
    minute_ = minute(unix_epoch);      // get minutes (0 - 59)
    hour_   = hour(unix_epoch);        // get hours   (0 - 23)
  }

  Time[4] = minute_ % 10 + '0';
  Time[3] = minute_ / 10 + '0';
  Time[1] = hour_   % 10 + '0';
  Time[0] = hour_   / 10 + '0';

  Time[2] = ':';
  if (second_ % 2 == 0)
  {
    Time[2] = ' ';
  }
  display.print(Time);
  display.display();
  second_ = second_ + 1;
  
  delay(1000);
}
