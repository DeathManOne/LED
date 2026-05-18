/*
 * led.cpp
 *
 * Copyright (c) 2026 DeathManOne
 * https://github.com/DeathManOne
 * 
 * This file is part of the LED library.
 *
 * LED is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LED is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LED.
 * If not, see <https://www.gnu.org/licenses/>.
 */

#include "../include/led.h"

LED::LED(int pinRed, int pinGreen, int pinBlue, bool commonAnode, uint32_t frequency, uint8_t resolution) {
    this->_COMMON_ANODE = commonAnode;

    ledcSetup(this->_CHANNEL_RED, frequency, resolution);
    ledcSetup(this->_CHANNEL_GREEN, frequency, resolution);
    ledcSetup(this->_CHANNEL_BLUE, frequency, resolution);

    ledcAttachPin(pinRed, this->_CHANNEL_RED);
    ledcAttachPin(pinGreen, this->_CHANNEL_GREEN);
    ledcAttachPin(pinBlue, this->_CHANNEL_BLUE);

    this->clear();
}

void LED::_applyBrightness(uint8_t red, uint8_t green, uint8_t blue) {
    ledcWrite(this->_CHANNEL_RED, this->_brightness(red));
    ledcWrite(this->_CHANNEL_GREEN, this->_brightness(green));
    ledcWrite(this->_CHANNEL_BLUE, this->_brightness(blue));
}


void LED::hex(uint32_t color) {
    uint8_t red = (color >> 16) & 0xFF;
    uint8_t green = (color >> 8) & 0xFF;
    uint8_t blue = color & 0xFF;
    this->_applyBrightness(red, green, blue);
}
