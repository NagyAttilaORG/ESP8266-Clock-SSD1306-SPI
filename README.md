
# ESP8266-Clock-SSD1306-SPI
![enter image description here](https://travis-ci.com/NagyAttilaORG/ESP8266-Clock-SSD1306-SPI.svg?branch=master)

![](https://github.com/NagyAttilaORG/ESP8266-Clock-SSD1306-SPI/blob/master/images/esp8266.gif)

This is a little clock code for the ESP8266 board and for the 7 pins SSD1306 SPI Oled display. You can check the actual time without any settings. The code always check the "time.nist.gov" for actual time. The clock is on full screen and the pulsing separator is showing the seconds.

# The Hardware

The project ist based on the famous ESP8266 microcontroller and the SSD1306 OLED Screen.
- ESP8266 NodeMCU
- SSD1306 SPI 7pin based 128x64 OLED Screen module

![](https://raw.githubusercontent.com/NagyAttilaORG/ESP8266-Clock-SSD1306-SPI/master/images/esp8266-ssd1306-spi-fritzing.jpg)

# Software

## Arduino Software (tested with 1.8.5)

Download and install the arduino software (IDE) at  [https://www.arduino.cc/en/Main/Software](https://www.arduino.cc/en/Main/Software)

## ESP8266 board support for arduino IDE

In the Arduino IDE open the preferences dialog and enter the following URL as "Additional Boards Manger URL":  [http://arduino.esp8266.com/stable/package_esp8266com_index.json](http://arduino.esp8266.com/stable/package_esp8266com_index.json)  ![Preferences](https://raw.githubusercontent.com/NagyAttilaORG/ESP8266-Clock-SSD1306-SPI/master/images/arduino-esp8266-additional-boards.png)

Go to "Tools" > "Board: " > "Boards Manager ...", search for "esp" and install the "esp8266 by ESP8266 Community" in version 2.4.1 ([https://github.com/esp8266/Arduino](https://github.com/esp8266/Arduino)):  ![Preferences](https://raw.githubusercontent.com/NagyAttilaORG/ESP8266-Clock-SSD1306-SPI/master/images/esp8266-board-manager.png)

Now go to "Tools" > "Board: " and choose "NodeMCU 1.0 (ESP-12E Module)", set CPU frequency to 80 MHz, and Flash size to "4M (1M SPIFFS)" leave upload speed at 115200 (you could try to set it higher if it makes no problems). Select the right COM port.  
Set "IwIP Variant" to "v2 Higher Bandwidth".

**Note for ESP-01 users (boards with only 512k of memory):**  
Have a look  [here](https://github.com/carlymx/SPIFFS-Mod-for-ESP8266). User @carlymx has provided detailed instructions.

![Board settings](https://raw.githubusercontent.com/NagyAttilaORG/ESP8266-Clock-SSD1306-SPI/master/images/bandwidth.png)

## Used Libraries

Go to "Sketch" > "Include Library" > "Manage Libraries ..." and install the following libraries by searching for them and installing:

- Adafruit_SSD1306 by @adafruit (tested with version 1.2.9)  
    [https://github.com/adafruit/Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
    
- Adafruit GFX Library @adafruit (tested with version 1.3.4)  
    [https://github.com/adafruit/Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library)
    
- Arduino Time Library by @PaulStoffregen (tested with 1.5.0)  
    [https://github.com/PaulStoffregen/Time](https://github.com/PaulStoffregen/Time)
    
- Arduino Time Library by @arduino-libraries (tested with 3.1.0)  
    [https://github.com/arduino-libraries/NTPClient](https://github.com/arduino-libraries/NTPClient)
    
## Software installation

Modify your "YOUR WIRELESS NAME" and the "YOUR WIRELESS PASSWORD" then compilate the file and upload to your ESP8266 module. Just wire it up and you can go with it.

For your time settings you have to change the line 32 options. There is some instructions on the line 31.

## FAQ

>**My clock is starting with 00:00.**

*It is normal, just wait a 30 seconds.*
