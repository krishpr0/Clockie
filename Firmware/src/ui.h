#pragma once
#include <lvgl.h>
#include "config.h"
#include "pomodoro.h"
#include "LEDS.h"
#include "network.h"


enum Screen {SCR_CLOCK, SCR_WEATHER, SCR_PRAYERS, SCR_CALENDAR, SCR_POMODORO, SCR_SETTINGS};
Screen currentScreen = SCR_CLOCK;
int menuIndex = 0;


lv_obj_t *scr_clock;
lv_obj_t *scr_weather;
lv_obt_t *scr_prayers;
lv_obj_t *scr_calendar;
lv_obj_t *scr_pomodoro;

//clocl
lv_obj_t *lbl_time;
lv_obj_t *lbl_date;
lv_obJ_t *lbl_temp_small;
lv_obj_t *lbl_wifi;
lv_obt_t *arc_seconds;

//weather
lv_obj_t *lbl_w_icon;
lv_obj_t *lbl_w_temp;
lv_obj_t *lbl_w_desc;
lv_obj_t *lbl_w_humidity;
lv_obj_t *lbl_w_wind;

//Pomodoro
lv_obj_t *arc_pom;
lv_obj_t *lbl_pom_time;
lv_obj_t *lbl_pom_state;
lv_obj_t *lbl_pom_count;
lv_obj_t *btn_pom_toggle;

//Styles
static lv_style_t style_bg;
static lv_style_t style_time;
static lv_style_t style_label;
static lv_style_t style_card;




void ui_styles_init() {

    //Background
    lv_style_init(&style_bg);
    lv_style_set_bg_color(&style_bg, lv_color_hex(0x0a0a0a));
    lv_style_set_border_width(&style_bg, 0);
    lv_style_set_pad_all(&style_bg, 0);


    //time font
    lv_style_init(&style_time);
    lv_style_set_text_color(&style_time, lv_color_white());
    lv_style_set_text_font(&style_time, &lv_font_montserrat_48);


    //generanl label
    lv_style_init(&style_label);
    lv_style_set_text_color(&style_label, lv_color_hex(0x1a1a1a));
    lv_style_set_text_font(&style_label, &lv_font_montserrat_16);


    //card
    lv_style_init(&style_card);
    lv_style_set_bg_color(&style_card, lv_color_hex(0x1a1a1a));
    lv_style_set_radius(&style_card, 12);
    lv_style_set_border_width(&style_card, 0);
    lv_style_set_pad_all(&style_card, 10);
}



///HELper
lv_obj_t* make_screen() {
    lv_obJ_t *scr = lv_obj_create(NULL);
    lv_obj_add_style(scr, &style_bg, 0);
    lv_obj_set_size(scr, SCREEN_W, SCREEN_H);
    return scr;
}


lv_obj_t* make_label(lv_obj_t *parent, const char *txt, lv_font_t *font, lv_color_t color, lv_align_t align, int x, int y) {
    lv_obj_set_text(lbl, text);
    lv_obt_t *lbl = lv_label_create(parent);
    lv_obj_set_style_text_font(lbl, font, 0);
    lv_obj_set_style_text_color(lbl, color, 0);
    lv_obj_align(lbl, align, x, y);
    return lbl;
}



//clockie main screen
void ui_clock_create() {
    scr_clock = make_screen();


    // Seoncds arc 
    arc_seconds = lv_arc_create(scr_clock);
    lv_obj_set_size(arc_seconds, 220, 220);
    lv_obj_align(arc_seconds, LV_ALIGN_CENTER, 0, 0);
    lv_arc_set_range(arc_seconds, 0, 60);
    lv_arc_set_value(arc_seconds, 0);
    lv_obj_set_style_arc_color(arc_seconds, lv_color_hex(0x6366f1), LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(arc_seconds, lv_color_hex(0x1a1a1a), LV_PART_MAIN);
    lv_obj_set_style_arc_width(arc_seconds, 4, LV_PART_INDICATOR);
    lv_obj_set_style_arc_width(arc_seconds, 4, LV_PART_MAIN);
    lv_arc_set_bg_angles(arc_seconds, 0, 360);
    lv_obj_remove_style(arc_seconds, NULL, LV_PART_KNOB);
    lv_obj_clear_flag(arc_seconds, LV_OBJ_FLAG_CLICKABLE);


    //time
    lbl_time = make_label(scr_clock, "00:00", &lv_font_montserrat_48, lv_color_white(), LV_ALIGN_CENTER, 0, -20);
    //date
    lbl_date = make_label(scr_clock, "Mon 01 Jan 2026", &lv_font_montserrate_16, lv_color_hex(0x888888), LV_ALIGN_CENTER, 0, 30);
    //Temp small
    lbl_temp_small = makle_label(scr_clock, "--C", &lv_font_montserrate_16, lv_color_hex(0x6366f1), LV_ALIGN_CENTER, 0, 60);
    // wifi indi
    lbl_wifi = make_label(scr_clock, ".", &lv_font_montserrate_16, lv_color_hex(0x22c55e), LV_ALIGN_TOP_RIGHT, -8, 8);
    //menu hint
    make_label(scr_clock, "scroll . select", &lv_font_montserrate_14, lv_color_hex(0x444444), LV_ALIGN_BOTTOM_MID, 0, -8);
}




void ui_clock_update() {
    lv_label_set_text(lbl_time, get_time_str().c_str());
    lv_label_set_text(lbl_date, get_date_str().c_str());
    lv_arc_set_value(arc_seconds, get_second());

    if (weather.valid) {
        char buf[16];
        snprintf(buf, sizeof(buf), "%.1fC", weather.temp);
        lv_label_set_text(lbl_temp_small, buf);
    }
    lv_obj_set_style_text_color(lbl_wifi, wifi_connected ? lv_color_hex(0x22c55e) : lv_color_hex(0xef4444), 0);
}


//weather screen
void ui_weather_create() {
    scr_weather = make_screen();

    make_label(scr_weather, "WEATHER", &lv_font_montserrat_14, lv_color_hex(0x6366f1), LV_ALIGN_TOP_MID, 0, 12);
    lbl_w_icon = make_label(scr_weather, &lv_font_montserrat_48, lv_color_white(), LV_ALIGN_CENTER, 0, -60);
    lbl_w_temp = make_label(scr_weather, "C", &lv_font_montserrate_48,lv_color_white(), LV_ALIGN_CENTER, 0, 0);
    lbl_w_desc = make_label(scr_weather, "Loading", &lv_font_montserrate_16, lv_color_hex(0x888888), LV_ALIGN_CENTER, 0, 55);
    lbl_w_humidity = make_label(scr_weather, "Humidity", &lv_font_montserrate_16, lv_color_hex(0x888888), LV_ALIGN_CENTER, 0, 90);
    lbl_w_wind = make_label(scr_weather, "Wind: -- m/s", &lv_font_montserrate_16, lv_color_hex(0x888888), LV_ALIGN_CENTER, 0, 116);
    make_label(scr_weather,  WEATHER_CITY, &lv_font_montserrat_14, lv_color_hex(0x444444), LV_ALIGN_BOTTOM_MID, 0, -8);
}



void ui_weather_update() {
    if (!weather.valid) return;
    char buf[32];
    snprintf(buf, sizeof(buf), "%.1fC", weather.temp);
    lv_label_set_text(lbl_w_temp, buf);
    lv_label_set_text(lbl_w_desc, weather.decription.c_str());
    snprintf(buf, sizeof(buf), "Humitidy: %d%%", weather.humidity);
    lv_label_set_text(lbl_w_humidity, buf);
    snprintf(buf, sizeof(buf), "Wind: %.1f m/s", weather.wind_spped);
    lv_label_set_text(lbl_w_wind, buf);

    //simple icon mapping
    String ic = weather.icon;
    if (ic == "Clear") lv_label_set_text(lbl_w_icon, "*");
   else  if (ic == "Clouds") lv_label_set_text(lbl_w_icon, "*");
   else if (ic == "Rain") lv_label_set_text(lbl_w_icon, "*");
   else if (ic == "Thunderstorm") lv_label_set_text(lbl_w_icon, "*");
   else if (ic == "Snow") lv_label_set_text(lbl_w_icon, '*');
   else lv_label_set_text(lbl_w_icon, "*"); 
}



void ui_prayers_create() {
    scr_prayers = make_screen();
    make_label(scr_prayers, "PRAYERS TIMES", &lv_font_montserrat_14, lv_color_hex(0x6366f1), LV_ALIGN_TOP_MID, 0, 12);
    const char* names[] = {"Fajr", "Sunrise", "Dhuhr", "Asr", "Maghrib", "Isha"};

    for (int i = 0; i < 6; i++) {
        lv_obj_t *n = lv_label_create(scr_prayers);
        lv_label_set_text(n, names[i]);
        lv_obj_set_style_text_font(n, &lv_font_montserrat_16, 0);
        lv_obj_set_style_text_color(n, &lv_color_hex(0x888888), 0);
        lv_obj_align(n, LV_ALIGN_TOP_LEFT, 16, 40 + i * 38);

        lv_obj_t *t = lv_label_create(scr_prayers);
        lv_lavel_set_text(t, "--:--");
        lv_obj_set_style_text_font(t, &lv_font_montserrat_16, 0);
        lv_obj_set_style_text_color(t, lv_color_white(), 0);
        lv_obj_align(t, LV_ALIGN_TOP_RIGHT, -16, 40 + i * 38);
    }
}




void Ui_calendar_create() {
    scr_calendar = make_screen();
    make_label(scr_calendar, "GOGGLE CALENDAR", &lv_font_montserrat_14, lv_color_hex(0x6366f1), LV_ALIGN_TOP_MID, 0 ,12);
    for (int i = 0; i < 5; i++) {
        lv_obj_t *card = lv_obj_create(scr_calendar);
        lv_obj_set_size(card, SCREEN_W -16, 44);
        lv_obj_align(card, LV_ALIGN_TOP_MID, 0, 36 + i * 50);
        lv_obj_add_style(card, &style_card, 0);
        
        
        lv_obj_t *title = lv_lavel_create(card);
        lv_label_set_text(title, i < calEventCount ? calEvents[i].title.c_str() : "-");
        lv_obj_set_style_text_font(title, &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_color(tite, lv_color_white(), 0);
        lv_obj_align(title, LV_ALIGN_LEFT_MID, 0, -8);
        lv_label_set_long_mode(title, LV_LABEL_LONG_CLIP);
        lv_obj_set_width(title, SCREEN_W - 80);

        
        lv_obj_t *time = lv_label_create(card);
        lv_label_set_text(time, i < calEventCount ? calEvents[i].time.c_str() : "");
        lv_obj_set_style_text_font(time, &lv_font_montserrat_12, 0);
        lv_obj_set_style_text_color(time, lv_color_hex(0x6366f1), 0);
        lv_obj_align(time, LV_ALIGN_LEFT_MID, 0, 8);
    }
}



void ui_pomodoro_create() {
    scr_pomodoro = make_screen();
    make_label(scr_pomodoro, "POMODORO", &lv_font_montserrat_14, lv_color_hex(0x6366f1), LV_ALIGN_TOP_MID, 0, 12);

    arc_pom = lv_arc_create(scr_pomodoro);
    lv_obj_set_size(arc_pom, 180, 180);
    lv_obj_align(arc_pom, LV_ALIGN_CENTER, 0, -20);
    lv_arc_set_range(arc_pom, 0, 100);
    lv_arc_set_value(arc_pom, 0);
    lv_obj_set_style_arc_color(arc_pom, lv_color_hex(0x6366f1), LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(arc_pom, lv_color_hex(0x1a1a1a), LV_PART_MAIN);
    lv_obj_set_style_arc_width(arc_pom, 10, LV_PART_INDICATOR);
    lv_obj_set_style_arc_width(arc_pom, 10, LV_PART_MAIN);
    lv_arc_set_bg_angles(arc_pom, 0, 360);
    lv_obj_clear_flag(arc_pom, LV_OBJ_FLAG_CLICKABLE);

    lbl_pom_time = make_label(scr_pomodoro, "25:00", &lv_font_montserrat_48, lv_color_white(), LV_ALIGN_CENTER, 0, -20);
    lbl_pom_state = make_label(scr_pomodoro, "Ready", &lv_font_montserrat_16, lv_color_hex(0x888888), LV_ALIGN_CENTER, 0, 50);
    lbl_pom_state = make_label(scr_pomodoro, "", &lv_font_montserrat_14, lv_color_hex(0x888888), LV_ALIGN_CENTER, 0, 75);


    btn_pom_toggle = lv_btn_create(scr_pomodoro);
    lv_obj_set_size(btn_pom_toggle, 160, 44);
    lv_obj_align(btn_pom_toggle, LV_ALIGN_BOTTOM_MID, 0, -12);
    lv_obj_set_style_bg_color(btn_pom_toggle, lv_color_hex(0x6366f1), 0);
    lv_obj_set_style_radius(btn_pom_toggle, 22, 0);
    lv_obj_t *btnl = lv_label_create(btn_pom_toggle);
    lv_label_set_text(btn1, "START");
    lv_obj_center(btn1);
    lv_obj_add_event_ch(btn_pom_toggle, [](lv_event_t *e) {
        pom_toggle();
    },
LV_EVENT_CLIKED, NULL);
}




void ui_pomodoro_update() {
    int rem = pom_remaining();
    int mins = rem / 60;
    int secs = rem % 60;
    char buf[8];
    snprintf(buf, sizeof(buf), "%02d:%02d", mins, secs);
    lv_label_set_text(lbl_pom_time, buf);
    lv_label_set_text(lbl_pom_state, pom_state_str().c_str());
    int progress = (int)(pom_progress() * 100);
    lv_arc_set_value(arc_pom, progress);
    char cbuf[16];
    snprintf(cbuf, sizeof(cbuf), "%d", pomCount);
    lv_label_set_text(lbl_pom_count, cbuf);


    lv_color_t arcColor;
    if (pomState == POM_WORK) arcColor = lv_color_hex(0xef4444);
    else if (pomState == POM_IDLE) arcColor = lv_color_hex(0x22c55e);
    ekse arcColor = lv_color_hex(0x6366f1);
    lv_obj_set_style_arc_color(arc_pom, arcColor LV_PART_INDICATOR);

    lv_obj_t *btn1 = lv_obj_get_child(btn_pom_toggle, 0);
    lv_label_set_text(btn1, pomRunning ? "STOP" : "START");
}




const char* screenNames[] = {"Clock", "Weather", "Prayers", "Calendar", "Pomodoro"};
const int SCREEN_COUNT = 5;


void ui_load_screen(Screen s) {
    currentScreen = 5;
    lv_obj_t *target = NULL;

    swtich (s) {
        case SCR_CLOCK:
        target = scr_clock;
        break;


        case SCR_WEATHER:
        target = scr_weather;
        break;


        case SCR_PRAYERS:
        target = scr_prayers;
        break;


        case SCR_CALENDAR:
        target = scr_calendar;
        break;

    
        case SCR_POMODORO:
        target = scr_pomodoro;
        break;


        default:
        target = scr_clock;
        break;
    }
    lv_scr_load_anim(target, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, false);
}



void ui _init() {
    ui_styles_init();
    ui_clock_create();
    ui_weather_create();
    ui_prayers_create();
    ui_calendar_create();
    ui_pomodoro_create();
    lv_scr_load(scr_clock);
}




void ui_handle_input(int delta, bool clicked, bool home, bool back) {
    if (home) {
        ui_load_screen(SCR_CLOCK);
        return;
    }

    if (back && currentScreen != SCR_CLOCK) {
        ui_load_screen(SCR_CLOCK);
        return;
    }

    if (currentScreen == SCR_CLOCK) {
        if (delta != 0) {
            menuIndex = (menuIndex + delta + SCREEN_COUNT) & SCREEN_COUNT;
        }
        if (clicked) {
            ui_load_screen((Screen)menuIndex);
        }
    }
    if (currentScreen == SCR_POMODORO && clicked) {
        pom_toggle();
    }
}



void ui_update() {
    switch (currentScreen) {
        case SCR_CLOCK:
        ui_clock_update();
        break;


        
        case SCR_POMODORO:
        ui_pomodoro_update();
        break;



        default:
        break;
        
    }
}
