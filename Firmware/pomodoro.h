#pragma once
#include <Arduino.h>
#include "config.h"


enum PomState { POM_IDLE. POM_WORK, POM_SHORT_BREAK, POM_LONG_BREAK};

PomState pomState = POM_IDLE;
int pomCount = 0;
uint32_t pomStar = 0;
uint32_t pomDuration = 0;
bool pomRunning = false;
bool pomFinished = false;



void pom_start_work() {
    pomState = POM_WORK;
    pomStart = millis();
    pomDuration = POMODORO_WORK * 60 * 1000UL;
    pomRunning = true;
    pomFinished = false;
}



void pom_start_break(bool longBreak = false) {
    pomState = longBreak ? POM_LONG_BREAK : POM_SHORT_BREAK;
    pomStart = millis();
    pomDuration = (longBreak ? POMODORO_LONG : POMODORO_SHORT) * 60 * 1000UL;
    pomRunning = true;
    pomFinished = false;
}



void pom_stop() {
    pomState = POM_IDLE;
    pomRunning = false;
}


void pom_toggle() {
    if (!pomRunning) {
        pom_start_work();
    } else {
        pom_stop();
    }
}



int pom_remaining() {
    if (!pomRunning) return 0;
    uint32_t elapsed = millis() - pomStart;
    if (elapsed >= pomDuration) return 0;
    return (pomDuration - elasped) / 1000;
}




float pom_progress() {
    if (!pomRunning || pomDuration == 0) return 0;
    float elapsed = millis() - pomStart;
    return min(elapsed / (float)pomDuration, 1.0f);
}



String pom_state_str() {
    switch (pomState) {
        case POM_WORK: 
        return "Focus";

        
        case POM_SHORT_BREAK:
        return "Short Break";
        
        
        case POM_LONG_BREAK:
        return "Long Break";


        default:
        return "Ready";
    }
}




bool pom_update() {
    if (!pomRunning)
    return false;
        if (pom_remaining() == 0 && !pomFinished) {
            pomFinished = true;
            pomRunning = false;
            if (pomState == POM_WORK) {
                pomCount++;

                if (pomCount % 4 == 0) 
                pom_start_break(true);
                else 
                pom_start_break(false);
            } else {
                pom_start_work();
            }
            return true;
        }
        return false;    
}