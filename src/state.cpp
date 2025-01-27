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
#include "state.h"
#include <optoma.h>

State mapStringToState(String command) {
    if (command == "ON") {
        return ON;
    } else if (command == "OFF") {
        return OFF;
    } else {
        return UNKNOWN;
    }
}

void handlePowerState(PowerState state) {
        setPowerState(state);
}

void handleState(State state) {
    if (state == ON) {
        handlePowerState(PW_ON);
    } else if (state == OFF) {
        handlePowerState(PW_OFF);
    }
}

