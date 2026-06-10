
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



[tableConvert.com_3jk98l.md](https://github.com/user-attachments/files/28801712/tableConvert.com_3jk98l.md)

| #     | Designator      | Footprint    | Description                 | LCSC #    | Qty | Unit Price (USD) | Unit Price (NPR) | Amount (NPR) | Link                                               |
|-------|-----------------|--------------|-----------------------------|-----------|-----|------------------|------------------|--------------|----------------------------------------------------|
| 1     | R12             | R0603        | 180Ω Resistor               | C94599    | 1   | $1.2381          | ₹165.29          | ₹165.29      | https://www.lcsc.com/product-detail/C94599.html    |
| 2     | BUZZER1         | BUZ-SMD_4P   | 2.7kHz Buzzer MLT-8530      | C94599    | 1   | $0.2080          | ₹27.77           | ₹27.77       | https://www.lcsc.com/product-detail/C94599.html    |
| 3     | C2,C3,C12,C26   | C0603        | 1uF Cap CL10A105KB8NNNC     | C15849    | 4   | $0.0109          | ₹1.46            | ₹5.82        | https://www.lcsc.com/product-detail/C15849.html    |
| 4     | C6,C15,C17,C19  | C0603        | 10uF Cap CL10A106MA8NRNC    | C96446    | 4   | $0.0362          | ₹4.83            | ₹19.33       | https://www.lcsc.com/product-detail/C96446.html    |
| 5     | C8              | C0603        | 22uF Cap CL10A226MP8NUNE    | C86295    | 1   | $0.0211          | ₹2.82            | ₹2.82        | https://www.lcsc.com/product-detail/C86295.html    |
| 6     | C1,C4,C5,...C27 | C0603        | 100nF Cap CC0603KRX7R9BB104 | C14663    | 17  | $0.0107          | ₹1.43            | ₹24.28       | https://www.lcsc.com/product-detail/C14663.html    |
| 7     | P1,P2,P3,P4     | CONN-TH_2P   | 5mm Terminal Block WJ301V   | C8475     | 4   | $0.0917          | ₹12.24           | ₹48.97       | https://www.lcsc.com/product-detail/C8475.html     |
| 8     | U4              | ESOP-8       | MSMP2307DN-LF-Z             | C49375228 | 1   | $1.1372          | ₹151.82          | ₹151.82      | https://www.lcsc.com/product-detail/C49375228.html |
| 9     | F1              | F1812        | Polyfuse 2.6A SMD1812P260TF | C438899   | 1   | $0.1178          | ₹15.73           | ₹15.73       | https://www.lcsc.com/product-detail/C438899.html   |
| 10    | L1              | IND-SMD      | 4.7uH Inductor CKCS5040     | C354606   | 1   | $0.0503          | ₹6.72            | ₹6.72        | https://www.lcsc.com/product-detail/C354606.html   |
| 11    | LCD2            | LCD-TH       | 3.5"" ILI9488 LCD HS32B01A  | C19632786 | 1   | $8.3381          | ₹1,113.14        | ₹1,113.14    | https://www.lcsc.com/product-detail/C19632786.html |
| 12    | LED3-LED132     | LED-SMD_4P   | SK6812MINI-B RGB LED        | C5183448  | 127 | $0.0937          | ₹12.51           | ₹1,588.64    | https://www.lcsc.com/product-detail/C5183448.html  |
| 13    | LED2            | LED-SMD_4P   | VEML7700-TR Light Sensor    | C504893   | 1   | $0.7128          | ₹95.16           | ₹95.16       | https://www.lcsc.com/product-detail/C504893.html   |
| 14    | LED1            | LED-SMD_L1.0 | NCD0402R1 Red LED           | C130719   | 1   | $0.0386          | ₹5.15            | ₹5.15        | https://www.lcsc.com/product-detail/C130719.html   |
| 15    | U1              | MIC-SMD_6P   | ICS-43434 MEMS Mic          | C5656610  | 1   | $6.5631          | ₹876.17          | ₹876.17      | https://www.lcsc.com/product-detail/C5656610.html  |
| 16    | U8              | QFN-24       | BQ25895RTWR USB-C Charger   | C80200    | 1   | $2.0396          | ₹272.29          | ₹272.29      | https://www.lcsc.com/product-detail/C80200.html    |
| 17    | R22             | R0402        | 33Ω Resistor RC0402FR       | C138002   | 1   | $0.1000          | ₹13.35           | ₹13.35       | https://www.lcsc.com/product-detail/C138002.html   |
| 18    | R11             | R0603        | 1kΩ Resistor RC0603FR       | C22548    | 1   | $0.1800          | ₹24.03           | ₹24.03       | https://www.lcsc.com/product-detail/C22548.html    |
| 19    | R24,R25         | R0603        | 2.2kΩ Resistor 0603WAF2201  | C4190     | 2   | $0.1500          | ₹20.02           | ₹40.05       | https://www.lcsc.com/product-detail/C4190.html     |
| 20    | R2,R3           | R0603        | 5.1kΩ Resistor 0603WAF5101  | C23186    | 2   | $0.1600          | ₹21.36           | ₹42.72       | https://www.lcsc.com/product-detail/C23186.html    |
| 21    | R8,R9,R10       | R0603        | 10kΩ Resistor 0603WAF1002   | C25804    | 3   | $0.1100          | ₹14.69           | ₹44.05       | https://www.lcsc.com/product-detail/C25804.html    |
| 22    | R1,R13-R20,R26  | R0603        | 10kΩ Resistor RC0603FR      | C98220    | 9   | $0.1800          | ₹24.03           | ₹216.27      | https://www.lcsc.com/product-detail/C98220.html    |
| 23    | R6,R23          | R0603        | 100kΩ Resistor 0603WAF1003  | C25803    | 2   | $0.1800          | ₹24.03           | ₹48.06       | https://www.lcsc.com/product-detail/C25803.html    |
| 24    | R5              | R0603        | 200kΩ Resistor 0603WAF2003  | C25811    | 1   | $0.1700          | ₹22.70           | ₹22.70       | https://www.lcsc.com/product-detail/C25811.html    |
| 25    | R21             | R1206        | 100Ω Resistor CR1206F100R   | C245445   | 1   | $0.0057          | ₹0.76            | ₹0.76        | https://www.lcsc.com/product-detail/C245445.html   |
| 26    | S1              | SENSOR-SMD   | HDC1080DMBR Temp/Humidity   | C82227    | 1   | $1.4400          | ₹192.24          | ₹192.24      | https://www.lcsc.com/product-detail/C82227.html    |
| 27    | U7              | SOIC-16      | DS3231SN RTC                | C9866     | 1   | $5.3806          | ₹718.31          | ₹718.31      | https://www.lcsc.com/product-detail/C9866.html     |
| 28    | SW5             | SW-SMD       | SSAG230400 Rotary Encoder   | C255506   | 1   | $0.3076          | ₹41.06           | ₹41.06       | https://www.lcsc.com/product-detail/C255506.html   |
| 29    | SW2,SW3,SW4     | SW-TH        | 1-1825027-4 Tactile Switch  | C2928195  | 3   | $0.1499          | ₹20.01           | ₹60.03       | https://www.lcsc.com/product-detail/C2928195.html  |
| 30    | U13             | SW-TH_CTR    | ED0890DM Knob w/ Switch     | C18213470 | 1   | $3.8268          | ₹510.88          | ₹510.88      | https://www.lcsc.com/product-detail/C18213470.html |
| 31    | CARD1           | TF-SMD       | TF-01A MicroSD Socket       | C91145    | 1   | $0.1922          | ₹25.66           | ₹25.66       | https://www.lcsc.com/product-detail/C91145.html    |
| 32    | USB1            | USB-C-SMD    | TYPE-C 16PIN 2MD Connector  | C2765186  | 1   | $0.0705          | ₹9.41            | ₹9.41        | https://www.lcsc.com/product-detail/C2765186.html  |
| 33    | U2              | VSSOP-10     | DRV2605LDGSR Haptic Driver  | C527464   | 1   | $1.2010          | ₹160.33          | ₹160.33      | https://www.lcsc.com/product-detail/C527464.html   |
| 34    | U14             | MODULE       | ESP32-S3-WROOM-1U-N16       | C2980298  | 1   | $5.6146          | ₹749.55          | ₹749.55      | https://www.lcsc.com/product-detail/C2980298.html  |
| 35    | U6,U12          | WLP-9        | MAX98357AEWL+T I2S Amp      | C2682619  | 2   | $0.4656          | ₹62.16           | ₹124.32      | https://www.lcsc.com/product-detail/C2682619.html  |
| 36    | U3              | WSOF-6       | BH1750FVI-TR Lux Sensor     | C78960    | 1   | $0.9329          | ₹124.54          | ₹124.54      | https://www.lcsc.com/product-detail/C78960.html    |
| TOTAL |                 |              |                             |           | 203 |                  |                  | ₹7,587.41    |                                                    |




# Feature
- **Wifi & BLE capabilities**
- ** 3 buttons & enconder**
- **3.2 inch TFT display**
- **ESP32-S3**
- **Temperature & Humiditiy sensor**
- **Ambient light sensor**
- **Haptic feedback**
- **Supports 2 speakers**
- **LED Matrix**
- **RTC**
- **BMS and charger**


# Hardware
|  Component | Description
|---|---|
| MCU | Seeed Studio XIAO ESP32-S3 |
| 2-Pin Terminal | WJ301V-5.0-02P-12-00A |
| Connectivity | Bluetooth, WIFI |
| Encoders | Rotary Encoders (360 Degree Rotary Encoder EC16) |
| Buttons | Tacticle Buttons|
| PCB | Custom Designes |
| Case | Themed Fracture Enclosure |



