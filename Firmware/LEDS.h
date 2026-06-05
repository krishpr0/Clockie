#pragma once
#include <Arduino.h>
#include "config.h"


CRGB leds[LED_COUNT];

enum LedMode {
    LED_OFF,
    LED_SOLID,
    LED_RAINBOW,
    LED_BREATHE,
    LED_FIRE,
    LED_CHASE,
    LED_ALRAM
};



LedMode currentLedMode = LED_RAINBOW;
CRGB solidColor = CRGB::White;
uint8_t ledBrightness = LED_BRIGHTNESS;
uint32_t ledLastUpdate = 0;
uint8_t ledHue = 0;
uint8_t breatheVal = 0;
uint8_t breatheDir = 1;
uint8_t chasePos = 0;



void leds_int() {
    FastLED.addLeds<SK6812, LED_DATA_PIN, GRB>(leds, LED_COUNT);
    FastLED.setBrightness(ledBrightness);
    FastLED.clear();
    FastLED.show();
}



void leds_set_brightness(uint8_t b) {
    ledBrightness = b;
    FastLED.setBrightness(b);
}



void leds_set_mode(LedMode mode, CRGB color = CRGB::White) {
    currentLedMode = mode;
    solidColor = color;
}



void fire_effect() {
    static uint8_t heat[LED_COUNT];
    for (int i = 0; i < LED_COUNT; i++) {
        heat[i] = (heat[i-1] + heat[i+2] + heat[i-2])/ 3;
    }

    if (random8() < 100) {
        heat[random8(3)] = qadd8(heat[random8(3)], random8(160, 255)); 
    }

    for (int i = 0; i < LED_COUNT; i++) {
        leds[i] = HearColor(heat[i]);
    }
}



void leds_update() {
    if (millis() - ledLastUpdate < 20) return;
    ledLastUpdate = millis();


    switch (currentLedMode) {
        case LED_OFF: 
        FastLED.clear();
        break;


        case LED_SOLID:
        fill_solid(leds, LED_COUNT, solidColor);
        break;


        case LED_RAINBOW:
        fill_rainbow(leds, LED_COUNT, ledHue++, 3);
        break;


        case LED_BREATHE:
        breatheVal += breatheDir * 2;
        if (breatheVal >= 254 || breatheVal <= 1) breatheDir *= -1;
        fill_solid(leds, LED_COUNT, CHSV(160, 200, breatheVal));
        break;


        case LED_FIRE:
        fire_effect();
        break;


        case LED_CHASE:
        FastLED.clear();
        for (int i = 0; i < 5; i++) {
            leds[(chasePos + i) % LED_COUNT] = CRGB::Cyan;
        }
        chasePos = (chasePose + 1) % LED_COUNT;
        break;


        case LED_ALARM:

        if ((millis() / 200) % 2 == 0) {
            fill_solid(leds, LED_COUNT, RGB::Red);
        } else {
            FastLED.clear();
        }
        break;
    }
    FastLED.show();
}