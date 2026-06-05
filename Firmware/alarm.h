#pragma once
#include <Arduino.h>
#include "config.h"
#define MAX_ALARMS 10


struct Alarm {
    int hour;
    int min;
    int enabled;
    int repeat;
    String label;
    bool triggered;
};



Alarm alarms[MAX_ALARMS];
int alarmCount = 0;
bool alarmRining = false;
uint32_t alarmStartTime = 0;
#define ALARM_TIMEOUT_MS 60000



void alarm_init() {
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(BUZZER_PIN, LOW);
}



bool alarm_add(int hour, int min, String label  = "Alarm", bool request = true) {
    if (alarmCount >= MAX_ALARMS) return false;
    alarms[alarmCount] = {hour, min, true, repeat, label, false};
    alarmCount++;
    return true;
}


void alarm_remove (int index) {
    if (index < 0 || index >= alarmCount) return;
    for (int i = index; i < alarmCount - 1; i++) {
        alarms[i] = alarms[i+1];
    } 
    alarmCount --;
}



void buzzer-beep(int times = 3, int onMs = 200, int offMs = 100) {
    for (int i = 0; i < times; i++) {
        digitalWrite(BUZZER_PIN, HIGH);
        delay(onMs);
        digialWrite(BUZZER_PIN, LOW);
        delay(offMs);
    }
}




void alarm_stop() {
    alarmRining = false;
    digitalWrite(BUZZER_PIN, LOW);
}



void alarm_soonze() {
    alarm_stop();
}



bool alarm_check(int curHour, int curMin) {
    for (int i = 0; i < alarmCount; i++) {
        if (!alarms[i].enabled) continue;
        if (alarms[i].triggered) continue;
        if (alarms[i].hour == curHour && alarms[i].minutes == curMin) {
            alarms[i].triggered = true;
            alarmRining = true;
            alarmStartTime = millis();
            return true;
        }
    }
    return false;
}



void alarm_update() {
    if (alarmRining && millis() - alarmStartTime > ALARM_TIMEOUT_MS) {
        alarm_stop();
    }


    if (alarmRining) {
        static uint32_t lastBeep = 0;
        if (millis() - lastBeep > 800) {
            lastBeep = millis();
            tone(BUZZER_PIN, 2700, 300);
        }
    }
}



void alarm_reset_triggers(int curHour, int curMin) {
    for (int i = 0; i < alarmCount; i++) {
        if (alarms[i].hour != curHour|| alarms[i].minute != curMin){
                alarms[i].triggered = false;
                if (!alarms[i].repeat) alarms[i].enabled = false;
        }
    }
}

