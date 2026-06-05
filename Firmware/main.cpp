#include <Arduino.h>
#include <Wire.h>
#include <TFT_eSPI.h>
#include <lvgl.h>
#include "config.h"
#include "display.h"
#include "../CLOCKKIE/LEDS.h"
#include "../CLOCKKIE/alarm.h"
#include "input.h"
#include "alarm.h"
#include "pomodoro.h"
#include "ui.h"
#include "webserver.h"


TFT_eSPI tft = TFT_eSPI();


TaskHandle_t taskNetwork;
TaskHandle_t taskLEDs;



uint32_t lastUIUpdate = 0;
uint32_t lastNTP = 0;
uint32_t lastWeather = 0;
uint32_t lastPrayer = 0;
uint32_t lastCalendar = 0;
uint32_t lastBLCheck = 0;
uint32_t lastAlarmCheck = 0;
int lastMinute = -1;




void network_task (void *param) {
    for (;;) {

        //EVERY NTP 5 SEC
        if (millis() - lastNTP > 300000UL) {
            ntp_update();
            lastNTP = millis();
        }



        //Weather every 10 mins
        if (millis() - lastWeather > 600000UL) {
            fetch_weather();
            lastWeather = millis();
        }


        //Prayers every 6 hrs
        if (millis() - lastPrayer > 21600000UL) {
            fetch_prayers();
            lastPrayer = millis();
        }


        //calendar every 5 mins
        if (millis() - lastCalendar > 300000UL) {
            fetch_calendar();
            lastCalendar = millis();
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}





void led_task(void *param) {
    for (;;) {
        leds_update();
        vTaskDelay(20 / portTICK_PERIOD_MS);
    }
}



void auto_brightnesss() {
    int h = get_hour();
    if (h >= NIGHT_HOUR || h < MORNING_HOUR) {
        set_brightness(BL_NIGHT);
        leds_set_brightness(20);
    } else {
        set_brightness(BL_DAY);
        leds_set_brightness(LED_BRIGHTNESS);
    }
}



void setup() {
    Serial.being(115200);
    Serial.println("Clockie bootin...");


    //I2C
    Wire.being(I2C_SDA, I2C_SCL);


    //Display + LVGL
    display_init();



    //show boot screeen
    lv_obj_t *boot = lv_obj_create(lv_scr_act());
    lv_obj_set_size(boot, SCREEN_W, SCREEN_H);
    lv_obj_set_style_bg_color(boot, lv_color_hex(0x0a0a0a), 0);
    lv_obj_set_style_border_width(boot, 0, 0);
    lv_obj_t *bootLabel = lv_label_create(boot);
    lv_label_set_text(bootLabel, "CLOCKIE");
    lv_obj_set_style_text_font(bootLabel, &lv_font_montserrat_48, 0);
    lv_obj_set_style_text_color(bootLabel, lv_color_hex(0x6366f1), 0);
    lv_obj_align(bootLabel, LV_ALIGN_CENTER, 0, -20);
    lv_obj_t *bootSub = lv_label_create(boot);
    lv_label_set_text(bootSub, "BY KRISH");
    lv_obj_set_style_text_font(bootSub, &lv_font_montserrat_16, 0);
    lv_obj_set_style_text_color(bootSub, lv_color_hex(0x444444), 0);
    lv_obj_align(bootSub, LV_ALIGN_CENTER, 0, 30);
    lv_timer_handler();
    delay(1500);



    //LEDS
    leds_int();
    leds_set_mode(LED_BREATHE, CRGB::Purple);


    //Input
    input_init();


    //alarm
    alarm_init();


    //wifi
    wifi_connect();


    if (wifi_connected) {
        ntp_update();
        fetch_weather();
        fetch_prayers();
        refresh_gcal_token();
        fetch_calendar();
        webserver_init();
        lastNTP = millis();
        lastWeather = millis();
        lastPrayer = millis();
        lastCalendar = millis();
    }


    ui_init();


    leds_set_mode(LED_RAINBOW);


    xTaskCreatePinnedToCore(network_task, "netwwork", 8192, NULL, 1, &taskNetwork, 0);
    xTaskCreatePinnedToCore(led_task, "leds", 4096, NULL, 1, &taskLEDs, 0);

    Serial.println("CLockie readyu!");
    Serial.printf("Web UI: https://%s\n", WiFi.local().toString().c_str());
}



void loop() {
    lv_timer_handler();


    int delta = input_get_delta();
    bool clicked = input_enc_clicked();
    bool home = input_home_pressed();
    bool back = input_back_pressed();
    bool extra = input_extra_pressed();


    if (extra) {
        static int ledModeIdx = 1;
        ledModeIdx = (ledModeIdx + 1) % 6;
        leds_set_mode((LedMode)ledModeIdx);
    }


    ui_handle_input(delta, clicked, home, back);


    if (millis() - lastUIupdate > 500) {
        ui_update();
        lastUIupdate = millis();
    }



    if (millis() - lastBLCheck > 600000UL) {
        ui_update();
        lastUIUpdate = millis();
    }



    if (millis() - lastAlarmCheck > 1000UL) {
        int h = get_hour();
        int m = get_minute();
        if (alarm_check(h, m)) {
            leds_set_mode(LED_ALRAM);
        }
        alarm_update();


        if (m != lastMinute) {
            alarm_reset_triggers(h, m);
            lastMinute = m;
        }
        lastAlarmCheck = millis();
    }



    if (pom_update()) {
        buzzer_beep(3);
        leds_set_mode(pomState == POM_WORK ? LED_RAINBOW : LED_BREATHE);
    }


    if (wifi_connected) webserver_handle();
    delay(5);
}