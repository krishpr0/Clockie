#pragma once


//Display
#define TFT_MOSI_PIN 13
#define TFT_SCK_PIN 12
#define TFT_CS_PIN 11
#define TFT_DC_PIN 10
#define TFT_RST_PIN 16
#define TFT_BL_PIN 3


//I2C
#define I2C_SDA 17
#define I2C_SCL 18


//Encoder
#define ENC_A 36
#define ENC_B 35
#define ENC_SW 37


//Buttons
#define BTN_HOME 4
#define BTN_BACK 6
#define BTN_EXTRA 15


// AMPs (MAX98357A)
#define I2S_BCLK 26
#define I2S_LRCLK 27
#define I2S_DOUT 25


//Mic (ICS-43434)
#define MIC_SCK 47
#define MIC_WS 48
#define MIC_SD 45


//LED (SK6812MINI-E) 10*10 grid
#define LED_DATA_PIN 42
#define LED_COUNT 100
#define LED_BRIGHTNESS 64 //its the 25% default


//Buzzwer
#define BUZZER_PIN 7


//SD_CARD
#define SD_CS_PIN 5
#define BQ25895_INT_PIN 38
#define USB_DN_PIN 19
#define USB_DP_PIN 20



//WIFI
#define WIFI_SSID "...."
#define WIFI_PASS "...."


//APIs
#define OPENWEATHER_API "...."
#define WEATHER_CITY "Kathmandu"
#define WEATHER_COUNTRY "Nepal"
#define WEATHER_UNIT "Metrics"


//Google Calendar Auth
#define GCAL_CLIENT_ID "..." //replace with your client id
#define GCAL_CLIENT_SECRET "..."
#define GCAL_REFRESH_TOKEN "..." 


//Time
#define NTP_SERVER  "https://www.ntppool.org/en/"
#define NTP_OFFSET 20700 // Nepal UTC+5:45 in sec make sure to replace with ur
#define  TIME_24H true


//POMODORO TIMER (all in minutes)
#define POMODORO_WORK 25 
#define POMODORO_SHORT 5 //this is the short break 
#define POMODORO_LONG 15// this is the long break


//Display Brightness
#define BL_DAY 200
#define BL_NIGHT 30
#define NIGHT_HOUR 22 // 10pm in 12 hr clock format
#define MORNING_HOUR 6 //am


//Dimension
#define SCREEN_H 320
#define SCREEN_W 240




#define PRAYER_LAT .....
#define PRAYER_LON .....
#define PRAYER_METHOD 1

