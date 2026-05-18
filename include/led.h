/*
 * led.h
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

#ifndef _LED_H_
#define _LED_H_

#include <Arduino.h>

class LED {
    private:
        bool _COMMON_ANODE = false;
        uint8_t _CHANNEL_RED = 0;
        uint8_t _CHANNEL_GREEN = 1;
        uint8_t _CHANNEL_BLUE = 2;
        inline uint8_t _brightness(uint8_t value) const { return (this->_COMMON_ANODE) ? 255 - value : value; }
        void _applyBrightness(uint8_t red, uint8_t green, uint8_t blue);
    public:
        /**
         * @brief constructor
         * @param pinRed pin of red led
         * @param pinGreen pin of green led
         * @param pinBlue pin of blue led
         * @param commonAnode (default: false) true if RGB LED is common anode
         * @param frequency (default: 5000) PWM frequency
         * @param resolution (default: 8) PWM resolution
         */
        LED(int pinRed, int pinGreen, int pinBlue, bool commonAnode = false, uint32_t frequency = 5000, uint8_t resolution = 8);
        
        /**
         * @brief destructor
         */
        ~LED() { this->clear(); }

        /**
         * @brief disable copy constructor
         */
        LED(const LED&) = delete;

        /**
         * @brief disable copy assignment
         */
        LED& operator=(const LED&) = delete;

        /**
         * @brief set RGB color state
         * @param red red LED state
         * @param green green LED state
         * @param blue blue LED state
         */
        inline void rgb(bool red, bool green, bool blue) { this->_applyBrightness((red) ? 255 : 0, (green) ? 255 : 0, (blue) ? 255 : 0); }

        /**
         * @brief set RGB color from hexadecimal value
         * @param color hexadecimal RGB color, example: 0xFF0000
         */
        void hex(uint32_t color);

        /**
         * @brief set red color
         */
        inline void red() { this->_applyBrightness(255, 0, 0); }

        /**
         * @brief set green color
         */
        inline void green() { this->_applyBrightness(0, 255, 0); }

        /**
         * @brief set blue color
         */
        inline void blue() { this->_applyBrightness(0, 0, 255); }

        /**
         * @brief set white color
         */
        inline void white() { this->_applyBrightness(255, 255, 255); }

        /**
         * @brief set yellow color
         */
        inline void yellow() { this->_applyBrightness(255, 255, 0); }

        /**
         * @brief set orange color
         */
        inline void orange() { this->_applyBrightness(255, 128, 0); }

        /**
         * @brief set cyan color
         */
        inline void cyan() { this->_applyBrightness(0, 255, 255); }

        /**
         * @brief set magenta color
         */
        inline void magenta() { this->_applyBrightness(255, 0, 255); }

        /**
         * @brief turn off all colors
         */
        inline void clear() { this->_applyBrightness(0, 0, 0); }
};
#endif