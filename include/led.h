#ifndef _LED_H_
#define _LED_H_

#include <Arduino.h>

class LED {
    private:
        int *_PIN_RED, *_PIN_GREEN, *_PIN_BLUE;
    public:
        /**
         * @brief constructor
         * @param pinRed pin of red led
         * @param pinGreen pin of green led
         * @param pinBlue  pin of blue led
         */
        LED(int pinRed, int pinGreen, int pinBlue);

        /**
         * @brief deconstructor
         */
        ~LED();

        /**
         * @brief turn off all of leds
         * @return true if all of leds are off, otherwise false
         */
        bool clear() const;

        /**
         * @brief turn on/off red led
         * @param state (default: false) true to turn on, false to turn off
         * @return true if red led is on, false if off
         */
        bool red(bool state = false) const;

        /**
         * @brief turn on/off green led
         * @param state (default: false) true to turn on, false to turn off
         * @return true if green led is on, false if off
         */
        bool green(bool state = false) const;

        /**
         * @brief turn on/off blue led
         * @param state (default: false) true to turn on, false to turn off
         * @return true if blue led is on, false if off
         */
        bool blue(bool state = false) const;
};
#endif