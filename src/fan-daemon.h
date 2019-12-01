/* Jetson Nano Fan Control Daemon

 * MIT License
 *
 * Copyright (c) 2019 William Hooper
 * Copyright (c) 2019 Koos du Preez
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef FAN_CONTROL_H_INCLUDED
#define FAN_CONTROL_H_INCLUDED

#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <thread>
#include <signal.h>
#include <glob.h>

// the following defines can be modified to change the daemon behaviour
#define FAN_OFF_TEMP 25
#define FAN_MAX_TEMP 60
#define UPDATE_INTERVAL 2
#define JETSON_CLOCKS_WAIT 60
// end of modifiable code


#define MICRO_SECONDS 1000
#define JETSON_CLOCKS "/usr/bin/jetson_clocks"
#define THERMAL_ZONE_GLOB "/sys/devices/virtual/thermal/thermal_zone*/temp"
#define PWM_CAP "/sys/devices/pwm-fan/pwm_cap"
#define TARGET_PWM "/sys/devices/pwm-fan/target_pwm"

unsigned readAverageTemp();
unsigned adjustFanSpeed(unsigned, unsigned);
unsigned getPwmCap();
unsigned readIntSysFs(std::string);
void writeIntSysFs(std::string path, unsigned value);

#endif // FAN_CONTROL_H_INCLUDED
