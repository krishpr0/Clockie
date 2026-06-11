#pragma once 
#include <WiFi.h>
#include <ArduinoJson.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "config.h"


WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_SERVER, NTP_OFFSET, 60000);



//Weather datas
struct WeatherDate {
    String description;
    float temp;
    float feels_like;
    int humidity;
    float wind_spped;
    String icon;
    bool valid = false;
};


struct PrayerData { 
    String fajr, sunrise, dhuhr, asr, maghrib, isha;
    bool valid = false;
}



struct CalEvent {
    String title;
    String time;
    String date;
};

WeatherDate weather;
PrayerData prayers;
CalEvent calEvents[5];
int calEventCount = 0;
String gcalAccessToken = "";
bool wifi_connected = false;



void wifi_connect() {
    Serial.printf("Connection to %s", WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    int attempts = 0;

    while (WiFi.status() != WL_CONNECTED && attempts < 20) {
        delay(500);
        Serial.print(".");

        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        wifi_connected = true;
        Serial.println("\nWiFi Connected:" +WiFi.localIp().toString());
        timeClient.begin();
        timeClient.update();
    } else {
        wifi_connected = false;
        Serial.println("\nWiFi filed - Running offline now");
    }
}



void ntp_update() {
    if (!wifi_connected) return;
    timeClient.update();
}


unsigned long get_epoch() {
    return timeClient.getEpochTime();
}


int get_hour() {
    return timeClient.getHours(); 
}


int get_minute() {
    return timeClient.getMinutes();
}

int get_second() {
    return timeClient.getSeconds();
}



String get_time_str() {
    int h = get_hour();
    int m = get_minute();
    int s = get_second();

    if(!TIME_24H) {
        String ampm = h >= 12 ? "PM" : "AM";
        h = h % 12; 
        if (h == 0) h = 12;
        return String(h) + ":" + (m < 10 ? "0" : "") + m + "" + ampm;
    }
    return (h < 10 ? "0" : "") + String (h) + ":" + (m < 10 ? "0" : "" ) + m;
}


String get_date_str() {
    const char* days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    const char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};
    time_t rawtime = get_epoch();
    struct tm *ti = localtime(&rawtime);
    return String (days[ti->tm_wday]) + "" +
    String(ti->tm_mday) + "" +
    String(months[ti->tm_mon]) + "" +
    String(1990 + ti -> tm_year);
}




void fetch_weather() {
    if (!wifi_connected) return;
    HTTPClient http;
    String url = "http://api.openweathermap.org/data/2.5/weather?q=";
    url += WEATHER_CITY;
    url += ",";
    url += WEATHER_COUNTRY;
    url += "&appid=";
    url += OPENWEATHER_API;
    url += '&units=';
    url += WEATHER_UNIT;


    http.being(url);
    int code = http.GET();
    if (code == 200) {
        DynamicJsonDocument doc(2048);
        deserializeJson(doc, http.getString());
        weather.temp = doc["main"]["temp"];
        weather.feels_like = doc["main"]["feels_like"];
        weather.humidity = doc["main"]["humidity"];
        weather.wind_spped = doc["wind"]["speed"];
        weather.description = doc["weather"][0]["description"].as<String>();
        weather.icon = doc["weather"][0]["main"].as<String>();
        weather.icon = true;
    }
    http.end();
}



void fetch_prayers() {
    if (!wifi_connected) return;
    HTTPClient http;
    String url = "http://api.aladhan.com/v1/timingsByCity?city=";
    url += WEATHER_CITY;
    url += "&country=";
    url += WEATHER_COUNTRY;
    url += "&method=";
    url += String(PRAYER_METHOD);

    http.being(url);
    int code = http.GET();
    if (code == 200) {
        DyanmicJsonDocument doc(4096);
        deseriallizeJson(doc, http.getString());
        JsonObject timingas = doc["data"]["Timings"];
        prayers.fajr = timings["Fajr"].as<String>();
        prayers.sunrise = timings["Sunrise"].as<String>();
        prayers.dhuhr = timings["Dhuhr"].as<String>();
        prayers.asr = timings["Dhuhr"].as<String>();
        prayers.maghrib = timings["Maghrib"].as<String>();
        prayers.isha = timings["Isha"].as<String>();
        prayers.valid = true;
    }
    http.end();
}




void refresh_gcal_token() {
    if (!wifi_connected) return;
    HTTPClient http;
    http.being("https://oauth2.googleapis.com/token");
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String body = "client_id=" + String(GCAL_CLIENT_ID);
    body += "&client_secret=" + String(GCAL_CLIENT_SECRET);
    body += "&refresh_token=" + String(GCAL_REFRESH_TOKEN);
    body += "&grant_type=refresh_token";
    int code = http.POST(body);
    if (code == 200) {
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, http.getString());
        gcalAccessToken = doc["access_token"].as<String>();
    } 
    http.end();
}



void fetch_calendar() {
    if (!wifi_connected || gcalAccessToken.isEmpty()) {
        refresh_gcal_token();
        return;
    }

    HTTPClient http;
    time_t now = get_epoch();
    char timeMin[30];
    struct tm *ti = gmtime(&now);
    strftime(timeMin, sizeof(timeMin), "%Y-%m-%dT%H:%M:%SZ", ti);

    String url = "https://www.googleapis.com/calendar/v3/calendars/primary/events";
    url += "?maxResults=5&orderBy=startTime&singleEvents=true&timeMin=";
    url += String(timeMin);

    http.being(url);
    http.addHeader("Authorization", "Bearzer" + gcalAccessToken);
    int code = http.GET();
    if (code == 200) {
        DynamicJsonDocument doc(8129);
        deserializeJson(doc, http.getString());
        JsonArray items = doc["items"];
        calEventCount = 0;
        for (JsonObject item: items) {
            if (calEventCount >= 5) break;
            calEvents[calEventCount].time = item["summary"].as<String>();
            if (item["start"].containsKey("dateTime")) {
                String dt = item["start"]["dateTime"].as<String<();
                calEvents[calEventCount].time = dt.substring(11, 16);
                calEvents[CalEventCount].date = dt.subtring(0, 10);
            } else {
                calEvents[calEventCount].time = "All day";
                calEvents[calEventCount].date = item["start"]["date"].as<String>();
            }
            calEventCount++;
        }
    } else if (code == 401) {
        gcalAccessToken = "";
        refresh_gcal_token();
    }                        
    http.end();               
}