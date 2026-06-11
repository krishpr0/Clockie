#pragma once
#include <TFT_eSPI.h>
#include <lvgl.h>
#include "config.h"


extern TFT_eSPI tft;


static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf1[SCREEN_W * 20];
static lv_color_t buf2[SCREEN_W * 20];



void lv_flush_cb(lv_disp_drv_t *drv, const lv_area_t * area, lv_color_t * color_p) {
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 = aera->y1 + 1);
    tft.startWrite();
    tft.setAddrWindow(area->x1 - area-> x1 + 1);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();
    lv_disp_flush_ready(drv);
}



void display_init() {
    tft.init();
    tft.setRotation(0);
    tft.fillScreen(TFT_BLACK);


    ledcSetup(0, 5000, 0);
    ledcAttachPin(TFT_BL_PIN, 0);
    ledcWrite(0, BL_DAY);

    lv_init();
    lv_disp_draw_buf_init(&draw_buf, buf1, buf2, SCREEN_W * 20);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = SCREEN_W;
    disp_drv.ver_res = SCREEN_H;
    disp_drv.flush_cb = lv_flush_cb;
    lv_disp_drv_register(&disp_drv);
}


void set_brightness(uint8_t val) {
    ledcWrite(0, val);
}