
# CLOCKIE 

Clockie, It is an Smart Bedside clock, It is an overall clock with all the necessary daily life data.
This project contains multiple sensors such as ambient light sensor, humditiy sensor, temperature sensor, buzzer, etc, and it also supports upto 2 speakers, which can be configurered as right and left.

<img width="1398" height="2000" alt="Add a heading (2)" src="https://github.com/user-attachments/assets/6e7a17d6-393a-4941-aeef-b16879f94f52" />



## What is this Project?
Clockie is an bed side smart clock that has the ability to also be controlled via a web broswer, why?
This unlocks the ability to change what the display is showing, according to what the user likes and also gives the ability to show notifictions, calls, etc also being able to add alarams.


- It contains a big 3.2 TFT display.
-  Also allows the user to insert SD Card to play what they like and also act as storage.
- Display auto adjust the brightness according to the surronding due to the protect the eyes T_T at night (*relatable*)
- Has a Led Matrix on the back for kwoolll light shows and also acts as a background light.



## How do we use clockie?
hmm

- THere are overall 3 buttons and a rotarty encoder and also a skude switch :)

    - The buttons are A, B, C respectively from left to the right when the display is facing toward you.
    - The encoder is on the most right side.
 
    - The Button A, is for START.
    - The Button B, is for STOP.
    - The Button C, is for RESET.
 
    - The Encoder acts as the scroll wheel which u can use to raom around the menu.
    - If you press the Encoder shaft the built-in switch will get activated and selectes an option from the menu which you currently are hovering onto.
 

That's all to the controls all other models wil be visible on the display.


## AHA Reason for building this
I needed an good alarm clock really really baddly beacuse we have classes from 5:45 am and its very strict soo havee to wake up sharp and reach there at 5:30 am. I would always wake up late lolll so I wanted to make this hoping it could help me.

Well starting from my everyday life, a normal alarm has been a hassel and a mess. First of all if u look at it at night the display would be soo freaking bright that the eyes woule evaporate. and also the display would be either too small or too big, The traditional alarm clock has always been boring, simple, and not fun; We would say alarm clock is just an alarm clock why make it advance? butt nahh we can make it morea advance to make our life easier.

and so yeah  the main reaons I built it wwas that i could wake up early in da mornig and also will be able to save my already bad eyes. YESz, also the time i wake up i could clearly see the time, weather, is it raning or not?, the temperature, etc. also set my notes and reminders for completeing task or anyting.
and also one of the biggest rason was beacuse of my friend, she wanted one really bad but couldnt get her hands on one.



## CAD
<img width="772" height="502" alt="Screenshot 2026-06-09 131551" src="https://github.com/user-attachments/assets/8d916c50-6c72-4193-84b3-5d2855a01fc4" />
<img width="1143" height="744" alt="Screenshot 2026-06-09 131614" src="https://github.com/user-attachments/assets/3da84a36-8e3c-4192-a7e8-2777250a3f8a" />





## Circuit Diagram:

<img width="784" height="555" alt="Screenshot 2026-06-07 234635" src="https://github.com/user-attachments/assets/fb090bf2-8a9b-43db-84c4-067ce5768a00" />
<img width="478" height="380" alt="Screenshot 2026-06-08 184027" src="https://github.com/user-attachments/assets/4eeff7ac-98aa-4476-88a3-6678cef68894" />


### PCB
<img width="580" height="347" alt="Screenshot 2026-06-09 150422" src="https://github.com/user-attachments/assets/fe17f057-ef24-4bab-bb5c-19081a1d6159" />


## PCB 3D 

<img width="1376" height="807" alt="Screenshot 2026-06-09 071740" src="https://github.com/user-attachments/assets/774acdb5-7a3e-43cc-8ea5-72968d6397e9" />
<img width="942" height="534" alt="Screenshot 2026-06-09 150400" src="https://github.com/user-attachments/assets/b574b1d0-979f-49e9-9d17-5bba56e53ec9" />



[tableConvert.com_hwvymt.md](https://github.com/user-attachments/files/28841613/tableConvert.com_hwvymt.md)
| #                      | Designator     | Footprint  | Description                                  | LCSC #    | Qty | Unit (USD) | Unit (NPR) | Total (NPR) | Link      |
|------------------------|----------------|------------|----------------------------------------------|-----------|-----|------------|------------|-------------|-----------|
| MCU & Wireless         |                |            |                                              |           |     |            |            |             |           |
| 1                      | U14            | MODULE     | ESP32-S3-WROOM-1U-N16  8MB Flash+PSRAM       | C2980298  | 1   | $5.6146    | Rs.749.55  | Rs.749.55   | LCSC Link |
| 2                      | U8             | QFN-24     | BQ25895RTWR  USB-C PD Charger IC             | C80200    | 1   | $2.0396    | Rs.272.29  | Rs.272.29   | LCSC Link |
| 3                      | U4             | ESOP-8     | MSMP2307DN-LF-Z  Buck Converter 5V to 3.3V   | C49375228 | 1   | $1.1372    | Rs.151.82  | Rs.151.82   | LCSC Link |
| 4                      | F1             | F1812      | Polyfuse 2.6A  SMD1812P260TF  Main rail      | C438899   | 1   | $0.1178    | Rs.15.73   | Rs.15.73    | LCSC Link |
| 5                      | F2             | F1812      | Polyfuse 3A  MF-R300  LED rail               | C17688    | 1   | $0.1500    | Rs.20.02   | Rs.20.02    | LCSC Link |
| 6                      | L1             | IND-SMD    | 4.7uH Inductor  CKCS5040  1A rated           | C354606   | 1   | $0.0503    | Rs.6.72    | Rs.6.72     | LCSC Link |
| 7                      | J1             | JST-PH2    | JST-PH 2.0mm 2-Pin  LiPo connector           | C157931   | 1   | $0.0500    | Rs.6.68    | Rs.6.68     | LCSC Link |
| 8                      | BT_HDR         | CR2032-TH  | CR2032 Coin Cell Holder  DS3231 backup       | C70377    | 1   | $0.1200    | Rs.16.02   | Rs.16.02    | LCSC Link |
| 9                      | LCD2           | LCD-TH     | 3.2in ST7789 TFT 240x320  HS32B01A           | C19632786 | 1   | $8.3381    | Rs.1113.14 | Rs.1113.14  | LCSC Link |
| 10                     | U6,U12         | WLP-9      | MAX98357AEWL+T  I2S Class-D Amp  x2 stereo   | C2682619  | 2   | $0.4656    | Rs.62.16   | Rs.124.32   | LCSC Link |
| 11                     | U1             | MIC-SMD6   | ICS-43434  MEMS I2S Microphone               | C5656610  | 1   | $6.5631    | Rs.876.17  | Rs.876.17   | LCSC Link |
| 12                     | BUZZER1        | BUZ-SMD4   | MLT-8530  2.7kHz Passive Buzzer              | C94598    | 1   | $0.2080    | Rs.27.77   | Rs.27.77    | LCSC Link |
| 13                     | SPK1,SPK2      | CONN-2P    | Speaker 4 ohm 1W 28mm  x2                    | —         | 2   | $1.0000    | Rs.133.50  | Rs.267.00   | —         |
| 14                     | S1             | SENSOR-SMD | HDC1080DMBR  Temp and Humidity  I2C 0x40     | C82227    | 1   | $1.4400    | Rs.192.24  | Rs.192.24   | LCSC Link |
| 15                     | U3             | WSOF-6     | BH1750FVI-TR  Ambient Light  I2C 0x23        | C78960    | 1   | $0.9329    | Rs.124.54  | Rs.124.54   | LCSC Link |
| 16                     | LED2           | SOT-23-6   | VEML7700-TR  Light Sensor  I2C 0x10          | C504893   | 1   | $0.7128    | Rs.95.16   | Rs.95.16    | LCSC Link |
| 17                     | U7             | SOIC-16    | DS3231SN  RTC  I2C 0x68                      | C9866     | 1   | $5.3806    | Rs.718.31  | Rs.718.31   | LCSC Link |
| 18                     | U2             | VSSOP-10   | DRV2605LDGSR  Haptic Driver  I2C 0x5A        | C527464   | 1   | $1.2010    | Rs.160.33  | Rs.160.33   | LCSC Link |
| 19                     | M1             | —          | LRA Haptic Motor  Coin 10mm                  | C381213   | 1   | $0.5000    | Rs.66.75   | Rs.66.75    | LCSC Link |
| 20                     | LED3-LED132    | LED-SMD4   | SK6812MINI-B  RGB Addressable LED  3.5x3.5mm | C5183448  | 127 | $0.0937    | Rs.12.51   | Rs.1588.64  | LCSC Link |
| 21                     | C_LED          | ELEC-TH    | 100uF 10V Electrolytic  LED rail bulk cap    | C16780    | 1   | $0.0300    | Rs.4.00    | Rs.4.00     | LCSC Link |
| 22                     | D_LED          | SOD-123    | 1N5819W Schottky  LED reverse protection     | C191024   | 1   | $0.0200    | Rs.2.67    | Rs.2.67     | LCSC Link |
| 23                     | SW5            | SW-SMD     | EC11E18244A5  Rotary Encoder  15mm shaft     | C255506   | 1   | $0.3076    | Rs.41.06   | Rs.41.06    | LCSC Link |
| 24                     | SW2,SW3,SW4    | SW-TH      | TS-1187A-B-A-B  6x6mm Tactile Button  x3     | C318884   | 3   | $0.1499    | Rs.20.01   | Rs.60.03    | LCSC Link |
| 25                     | SW_PWR         | SW-SMD     | SS-12D00G3  SPDT Slide Switch  Power         | C431540   | 1   | $0.1500    | Rs.20.02   | Rs.20.02    | LCSC Link |
| 26                     | USB1           | USB-C-SMD  | TYPE-C 16PIN 2MD  USB-C Receptacle           | C2765186  | 1   | $0.0705    | Rs.9.41    | Rs.9.41     | LCSC Link |
| 27                     | CARD1          | TF-SMD     | TF-01A  MicroSD Push-Push Socket             | C91145    | 1   | $0.1922    | Rs.25.66   | Rs.25.66    | LCSC Link |
| 28                     | P1,P2,P3,P4    | CONN-2P    | WJ301V-5.0-02P  5mm Terminal Block  x4       | C8475     | 4   | $0.0917    | Rs.12.24   | Rs.48.97    | LCSC Link |
| 29                     | R12            | R0603      | 180 ohm  ILIM resistor  BQ25895              | C22775    | 1   | $0.0100    | Rs.1.34    | Rs.1.34     | LCSC Link |
| 30                     | R22            | R0402      | 33 ohm  TFT backlight current limit          | C138002   | 1   | $0.1000    | Rs.13.35   | Rs.13.35    | LCSC Link |
| 31                     | R21            | R1206      | 100 ohm  Buzzer current limit                | C245445   | 1   | $0.0057    | Rs.0.76    | Rs.0.76     | LCSC Link |
| 32                     | R11            | R0603      | 1k ohm  LED status resistor                  | C22548    | 1   | $0.1800    | Rs.24.03   | Rs.24.03    | LCSC Link |
| 33                     | R24,R25        | R0603      | 2.2k ohm  I2C pull-ups SDA and SCL  x2       | C4190     | 2   | $0.1500    | Rs.20.02   | Rs.40.05    | LCSC Link |
| 34                     | R2,R3          | R0603      | 5.1k ohm  USB-C CC1 and CC2  x2              | C23186    | 2   | $0.1600    | Rs.21.36   | Rs.42.72    | LCSC Link |
| 35                     | R8,R9,R10      | R0603      | 10k ohm  Encoder pull-downs  x3              | C25804    | 3   | $0.1100    | Rs.14.69   | Rs.44.05    | LCSC Link |
| 36                     | R1,R13-R20,R26 | R0603      | 10k ohm  General pull-downs  x9              | C98220    | 9   | $0.1800    | Rs.24.03   | Rs.216.27   | LCSC Link |
| 37                     | R6,R23         | R0603      | 100k ohm  Feedback and SD_MODE  x2           | C25803    | 2   | $0.1800    | Rs.24.03   | Rs.48.06    | LCSC Link |
| 38                     | R5             | R0603      | 200k ohm  Buck feedback bottom               | C25811    | 1   | $0.1700    | Rs.22.70   | Rs.22.70    | LCSC Link |
| 39                     | C2,C3,C12,C26  | C0603      | 1uF  Decoupling  x4                          | C15849    | 4   | $0.0109    | Rs.1.46    | Rs.5.82     | LCSC Link |
| 40                     | C6,C15,C17,C19 | C0603      | 10uF  Bulk decoupling  x4                    | C96446    | 4   | $0.0362    | Rs.4.83    | Rs.19.33    | LCSC Link |
| 41                     | C8             | C0603      | 22uF  MP2307 output cap                      | C86295    | 1   | $0.0211    | Rs.2.82    | Rs.2.82     | LCSC Link |
| 42                     | C1,C4..C27     | C0603      | 100nF  General decoupling  x17               | C14663    | 17  | $0.0107    | Rs.1.43    | Rs.24.28    | LCSC Link |
| 43                     | LED1           | LED0402    | NCD0402R1  Red LED  Charge indicator         | C130719   | 1   | $0.0386    | Rs.5.15    | Rs.5.15     | LCSC Link |
| 44                     | BAT1           | —          | 4000mAh 3.7V LiPo Pouch Cell                 | —         | 1   | $4.0000    | Rs.534.00  | Rs.534.00   | —         |
| 45                     | BT2_CELL       | —          | CR2032 Coin Cell  DS3231 backup              | —         | 1   | $0.3000    | Rs.40.05   | Rs.40.05    | —         |
|                        |                |            |                                              |           |     |            |            |             |           |
| TOTAL  (45 line items) |                |            |                                              |           |     |            |            | Rs.7,889.80 |           |





## How to Build
<img width="784" height="555" alt="Screenshot 2026-06-07 234635" src="https://github.com/user-attachments/assets/fb090bf2-8a9b-43db-84c4-067ce5768a00" />

### What you need
- Soldering iron (fine tip recommended)
- Solder wire 
- Flux
- Multimeter
- USB-C cable

### Assembly order
1. Solder all SMD passives first (resistors, capacitors)
2. Solder ICs — BQ25895, MP2307, DS3231, HDC1080, BH1750, DRV2605, MAX98357 ×2
3. Solder ESP32-S3-WROOM-1U module
4. Solder USB-C connector and test 5V rail with multimeter before connecting anything else
5. Solder connectors — terminal blocks, SD card slot
6. Solder through-hole components — buttons, encoder
7. Connect LiPo battery via JST connector
8. Connect display via HDR-1X9 header
9. Solder SK6812 LED matrix on back side
10. Flash firmware via USB-C using PlatformIO
11. Open Serial Monitor — verify WiFi connects and sensors respond
12. Access web UI at the IP shown in Serial Monitor

### Firmware setup
- Install PlatformIO in VS Code
- Clone this repo
- Edit `firmware/src/config.h` — add your WiFi SSID, password, and OpenWeatherMap API key
- Run `pio run --target upload`


## GPIO Pinout
| GPIO | Function |
|------|----------|
| IO4  | Reset button |
| IO5  | Encoder SW |
| IO6  | Encoder A |
| IO7  | Encoder B |
| IO8  | I2C SDA |
| IO9  | I2C SCL |
| IO10 | TFT CS |
| IO11 | SPI MOSI |
| IO12 | SPI SCK |
| IO13 | SPI MISO |
| IO14 | TFT RS/DC |
| IO15 | I2S LRCLK |
| IO16 | I2S BCLK |
| IO17 | I2S DIN |
| IO18 | Buzzer |
| IO19 | USB D- |
| IO20 | USB D+ |
| IO35 | LED matrix data |
| IO36 | Haptic trigger |
| IO37 | HOME button |
| IO38 | BACK button |
| IO39 | EXTRA button |
| IO45 | Mic SD |
| IO46 | SD card CS |
| IO47 | Mic SCK |
| IO48 | Mic WS |

# Feature
- Wifi & BLE capabilities
- 3 buttons & enconder
- 3.2 inch TFT display
- ESP32-S3**
- Temperature & Humiditiy sensor
- Ambient light sensor
- Haptic feedback
- Supports 2 speakers
- LED Matrix
- RTC
- BMS and charger
- Prayer times (Aladhan API)
- Google Calendar integration
- Pomodoro timer
- Web browser control
- Microphone
- MicroSD audio playback
- Auto brightness (BH1750 ambient light sensor)
- USB-C charging
- Backup battery (LiPo)


# Hardware
| Component | Part |
|-----------|------|
| MCU | ESP32-S3-WROOM-1U-N16 |
| Display | 3.2" ST7789 TFT HS32B01A |
| Charger IC | BQ25895RTWR |
| Buck converter | MSMP2307DN |
| Audio amp | MAX98357AEWL+T ×2 (stereo) |
| RTC | DS3231SN |
| Temp/Humidity | HDC1080DMBR |
| Light sensor | BH1750FVI-TR |
| Haptic driver | DRV2605LDGSR |
| Microphone | ICS-43434 |
| LED matrix | SK6812MINI-B ×127 |
| Encoder | EC11E18244A5 |
| Buttons | 1-1825027-4 ×3 |
| MicroSD | TF-01A |
| USB-C | TYPE-C 16PIN 2MD |
| PCB | Custom 2-layer JLCPCB |
| Case | 3D printed PETG |

## Web Interface
Once powered on and connected to WiFi, open a browser on any device 
on the same network and go to the IP address shown on the display.

From the web interface you can:
- Add and remove alarms
- Control LED matrix mode and color
- Start/stop Pomodoro timer
- Adjust display brightness
- View current weather and prayer times

  

