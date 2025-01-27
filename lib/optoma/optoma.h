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

#ifndef OPTOMA_H
#define OPTOMA_H

const char POWER_ON[] = {0x7E, 0x30, 0x30, 0x30, 0x30, 0x20, 0x31, 0x0D};
const char POWER_OFF[] = {0x7E, 0x30, 0x30, 0x30, 0x30, 0x20, 0x32, 0x0D};

typedef enum {
    PW_ON,
    PW_OFF
} PowerState;

void setPowerState(PowerState state);

#endif // OPTOMA_H