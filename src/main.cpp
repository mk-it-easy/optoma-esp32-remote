/*
   Copyright 2025 Martin Kaiser

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiManager.h>
#include <ESPAsyncWebServer.h>
#include "state.h"

AsyncWebServer server(80);

void setup() {
    // Start Serial Monitor
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 16, 17);

  WiFiManager wm;

  bool res = wm.autoConnect("Optoma ZH403 - ESP Remote"); // anonymous ap

  if(!res) {
    Serial.println("Failed to connect");
    ESP.restart();
  } 
  else {
    Serial.println("Connected to WiFi");
  }

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String command = request->getParam("command")->value();
    State state = mapStringToState(command);

    if (state == UNKNOWN) {
      request->send(400, "text/plain", "Invalid command");
      return;
    } else {
      handleState(state);
    }
    
    request->send(200, "text/plain", "OK.");
    Serial.println("sent: OK");
  });

  // Start server
  server.begin();
}

void loop() {
}
