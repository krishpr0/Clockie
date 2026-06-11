#pragma once
#include <Arduino.h>
#include "config.h"


//Encoder state
volatile int encDelta = 0;
volatile bool encPressed = false;
bool btnHome = false;
bool btnBack = false;
bool btnExtra = false;


unsigned long lastDebounce = 0;
#define DEBOUNCE_MS 50

void IRAM_ATTR enc_isr_a() {
    bool a = digitalRead(ENC_A);
    bool b = digitalRead(ENC_B);
    if ( a == b) encDelta++;
    else encDelta--;
}


void IRAM_ATTR enc_isr_sw() {
    static unsigned long last = 0;
    if (millis() - last > DEBOUNCE_MS) {
        encPressed = true;
        last = millis();
    }
}


void input_init() {
    pinMode(ENC_A, INPUT_PULLUP);
    pinMode(ENC_B, INPUT_PULLUP);
    pinMode(ENC_SW, INPUT_PULLUP);
    pinMode(BTN_BACK, INPUT_PULLUP);
    pinMode(BTN_EXTRA, INPUT_PULLUP);
    pinMode(BTN_HOME, INPUT_PULLUP);


    attachInterrupt(digitalPinToInterrupt(ENC_A), enc_isr_a, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENC_SW), enc_isr_sw, FALLING);
}


//Returns the ecnoder delta and resets it again for the loop 
int input_get_delta() {
    int d = encDelta;
    encDelta = 0;
    return d;
}


bool input_enc_clicked() {
    if (encPressed) {
        encPressed = false;
        return true;
    }
    return false;
}



bool input_home_pressed() {
    static bool last = HIGH;
    bool cur = digitalRead(BTN_HOME);
    if (last == HIGH && cur == LOW) {
        last = cur;
        return true;
    }
    last = cur;
    return false;
}




bool input_back_clicked() {
    static bool last = HIGH;
    bool cur = digitalRead(BTN_HOME);
    if (last == HIGH && cur == LOW) {
        last = cur;
        return true;
    }
    last = cur;
    return false;
}



bool input_extra_pressed() {
    static bool last = HIGH;
    bool cur = digitalRead(BTN_EXTRA);
    if (last == HIGH && cur == LOW) {
        last = cur;
        return true;
    }
    last = cur;
    return false;
}