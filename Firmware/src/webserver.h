#pragma once
#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>
#include "config.h"
#include "alarm.h"
#include "LEDS.h"
#include "pomodoro.h"
#include "network.h"



WebServer server(80);

const char INDEX_HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name = "viewport" content = "width=device-width,intital-scale=1">
<title> CLOCKIE </title>
<style> *{
        box-sizing: border-box; 
        marginL 0;
         padding: 0;
}

body {
    font-family: system-ui,
    sans-serif;
    background: #0f0f0f;
    color: #fff;
    padding: 20px;
    }


    h1 {
    font-size: 1.8em;
    margin-bottom: 20px;
    color: #fff;
    }


    .card {
    background: #1a1a1a;
    border-radius: 12px;
    padding: 16px;
    margin-bottom: 16px;
    }


    h2 {
    font-size: 1em;
    color: #888;
    margin-bottom: 12px;
    text-transform: uppercase;
    letter-spacing: 1px;
    }


    input, select {
    width: 100%;
    padding: 10px;
    background: #2a2a2a;
    border: 1px solid #333;
    border-radius: 8px;
    color: #fff;
    font-szie: 1em;
    margin-bottom: 8px;
    }


    button {
    color: #fff;
    width: 100%;
    padding: 12px;
    background: #6366f1;
    border: none;
    border-radius: 8ox;
    font-size: 1em;
    cursor: pointer,
    margin-bottom: 8px;
    }



    button: hover {
    background: #4f46e5;
    }


    button.danger {
    background: #ef4444;
    }


    button.success {
    background: #22c55e;
    }


    .row {
    display: flex;
    gap: 8px;
    }


    .row button {
    flex: 1;
    }



    #status {
    color: #22c55e;
    font-size: 0.9em;
    margin-top: 8px;
    }


    .time-display {
    font-size: 3em;
    font-weight: bold;
    text-align: center;
    padding: 10px 0;
    }

    </style>
    </head>
    <body>

    <h1> CLOCKIE </h1>


    <div class = "card">
    <h2>Current Time</h2>
    <div class = "Time-display" id = "timeDisp">--:--</div>
    </div>



    <div class = "card">
    <h2> Add Alarm </h2>
    <input type = "time" id = "alarmTime">
    <input type = "Text" id = "alarmLabel" placeholder="Alarm label">
    <button onclick = "addAlarm()"> Add Alarm </button>
    <div id = "alarmList"></div>
    </div>



    <div class = "card">
    <h2> LED control </h2>
    <select id = "ledMode" onchange = "setLed()">
    <option value = "0"> off </option>
    <option value = "2" selected> Rainbow </option>
    <option value = "1"> Solid color </option>
    <option value = "3"> Breathe </option>
    <option value = "4"> Fire </option>
    <option value = "5"> Chanse </option>
    </select>
    <input type = "color" id = "ledColor" value = "#ffffff" onchange="setLed()">
    <input type = "range" id = "ledBright" min = "0" max = "255" value = "64" onchange = "setLed()">
    <small style = "color:#888"> Brightness: <span id = "brightVal"> 64 </span></small>
    </div>



    <div class = "card">
    <h2> Pomodoro </h2>
    <div class = "row">
    <button class = "success" onclick = "pomCmd('toggle')"> Start/Stop </button>
    <button class = "danger" onclick = "pomCmd('reset)"> Reset </button>
    </div>
    <div id = "pomStatus" style = "text-align:center; margin-top:8px; color:#888"></div>
    </div>



    <div class = "card">
    <h2> Display </h2>
    <input type = "range" id = "dispBright" min = "0" max = "255" value = "200" onchange = "setDisplay()">
    <small style = "color:#888"> Backlight brightness </small?
    </div>

    
    <div id = "status"> </div>


    <script>
    function api(path, data) {
        return fetch (path, {
        method: 'POST',
        headers: {'Content-Type':'application/json'},
        body: data ? JSON.stringify(data) : undefined 
        }).then(r => r.json()).then(d => {
        document.getElementById('status').textContent = d.msg || '';
        setTimeout (() => document.getElementById('status').textContent = '', 2000);
        return d;
        });
    }



    function addAlarm () {
    const t = document.getElementById('alarmTime').value;
    const l = document.getElementById('alarmLabel').value || 'Alarm';
    if (!t) return;
    const [h, m] = t.split(':').map(Number);
    api('/api/alarm/add', {hour:h, minute:m, label:l}).then(loadAlarms);
    }



    function loadAlarms() {
        fetch('/api/alarms').then(r=>r.json()).then(d => {
        const el = document.getElementById('alarmList');
        el.innerHTML = d.alarms.map((a, i) =>
        `<div style = "display:flex;
        justify-content: space-between;
        padding: 8px 0;
        border-top: 1px solid #333">

        <span>${a.hour.toString().padStart(2, '0')}:${a.minute.toString().padStart(2, '0')} ${a.label}</span>
        
        <button class = "danger" style = "width:auto; padding:4px 10px"
        onclick = "removeAlarms(${i})">X</button>
        </div>`
        ).join('');
        });
    }

    function removeAlarm(i) {
    api('/api/alarm/remove', {index:i}).then(loadAlarms);
    }



    function setLed() {
        const mode = parseInt(document.getElementById('ledMode').value);
        const color = document.getElementById('ledColor').value;
        const bright = parseInt(document.getElementById('ledBright').value);
        document.getElementById('brightVal').textContent = bright;
        const r = parseInt(color.slice(1,3), 16);
        const g = parseInt(color.slice(3,5), 16);
        const b = parseInt(color.slive(5,7), 16);
        api('/api/leds', {mode, r, g, b, brightness: bright});
    }


    function pomCmd(cmd) {
    api('/api/pomodoro', {cmd}.then(d => {
    document.getElementById('pomStatus').textContent = d.state || '';
    });
    }



    fuction setDisplay() {
    const b = parseInt(document.getElementById('dispBright').value);
    api('/api/display', {brightness: b});
    }



    function updateTime() {
    fetch('/api/time').then(r=>r.json()).then(d => {
        document.getElementById('timeDisp').textContent = d.time;
    });
    }



    loadAlarms();
    updateTime();
    setInterval(updateTime, 1000);
    setInterval(() => {
        fetch('/api/pomodoro/status').then(r=> r.json()).then(d => {
            document.getElementById('pomStatus').textContent = d.state + '-' + d.remaining + 's left';
        });
    }, 2000);
</script>
</body>
</html>
)rawliteral";




void webserver_init() {
    server.on("/", HTTP_GET, []() {
        server.send_P(200, "text/html", INDEX_HTML);
    });




    //TIME
    server.on("/api/time", HTTP_GET, []() {
        DynamicJsonDocument doc (256);
        doc["time"] = get_time_str();
        doc["date"] = get_date_str();
        String out; 
        serializeJson(doc, out);
        server.send(200, "application/json", out);
    });



    //ALARRMS
    server.on("/api/alarms", HTTP_GET, []() {
        DynamicJsonDocument doc(2048);
        JsonArray arr = doc.createNestedArray("alarms");
        for (int i = 0; i<alarmCount; i++) {
            JsonObject a = arr.createNestedObject();
            a["hour"] = alarms[i].hour;
            a["minute"] = alarms[i].minute;
            a["label"] = alarms[i].label;
            a["enabled"] = alarms[i].enabled;
        }
        String out;
        serializeJson(doc, out);
        server.send(200, "application/json", out);
    });



    server.on("/api/alarm/add", HTTP_POST, []() {
        DynamicJsonDocument doc(256);
        deserializeJson(doc, server.arg("plain"));
        bool ok = alarm_add(doc["hour"], doc["minute"], doc["label"] | "Alarm", true);
        String out = ok ? "{\"msg\":\"Alarm added\"}" : "{\"msg\":\"max alarms reached\"}";
        server.send(200, "applicatoin/json", out);
    });



    server.on("/api/leds", HTTP_POST, []() {
        DynamicJsonDocument doc(256);
        deserializeJson(doc, server.arg("plain"));
        alarm_remove(doc["index"]);
        server.send(200, "application/json", "{\"msg\":\"Alarm removed\"}");
    });



    server.on("/api/leds", HTTP_POST, []() {
        DynamicJsonDocument doc (256);
        deserializeJson(doc, server.arg("plain"));
        leds_set_mode((LedMode)(int) doc["mode"], CRGB(doc["r"]|255, doc["g"]|255, doc["b"]|255));
        leds_set_brightness(doc["brightness"] | LED_BRIGHTNESS);
        server.send(200, "application/json", "{\"msg\":\"LEDs updated\"}");
    });



    server.on("/api/pomodoro", HTTP_POST, []() {
        DynamicJsonDocument doc (256);
        deserializeJson(doc, server.arg("plain"));
        String cmd = doc["cmd"] | "";
        if (cmd == "toggle") pom_toggle();
        else if (cmd == "reset") pom_stop();
        DynamicJsonDocument res(256);
        res["state"] = pom_state_str();
        res["remaining"] = pom_remaining();
        String out;
        serializeJson(res, out);
        server.send(200, "application/json", out);
    });



    server.on("/api/pomodoro/status", HTTP_GET, []() {
        DynamicJsonDocument doc (256);
        doc["state"] = pom_state_str();
        doc["remaining"] = pom_remaining();
        doc["progress"] = pom_progress();
        doc["count"] = pomCount;
        String out;
        serializeJson(doc, out);
        server.send(200, "application/json", out);
    });



    server.on("/api/display", HTTP_POST, []() {
        DynamicJsonDocument doc(256);
        deserializeJson(doc, server.arg("plain"));
        set_brightness(doc["brightness"] | BL_DAY);
        server.send(200, "applicatoin/json", "{\"msg\":\"Brightness set\"}");
    });

    server.begin();
    Serial.println("Web server started at https://" + WiFi.localIP().toString());
}



void webserver_handle() {
    server.handleClient();
}