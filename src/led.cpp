#include "../include/led.h"

LED::LED(int pinRed, int pinGreen, int pinBlue) {
    this->_PIN_RED = new int(pinRed);
    this->_PIN_GREEN = new int(pinGreen);
    this->_PIN_BLUE = new int(pinBlue);

    pinMode(*this->_PIN_RED, OUTPUT);
    pinMode(*this->_PIN_GREEN, OUTPUT);
    pinMode(*this->_PIN_BLUE, OUTPUT);

    this->clear();
}

LED::~LED() {
    this->clear();
    delete this->_PIN_RED;
    delete this->_PIN_GREEN;
    delete this->_PIN_BLUE;
}

bool LED::clear() const {
    bool red = this->red();
    bool green = this->green();
    bool blue = this->blue();
    return !red & !green & !blue;
}

bool LED::red(bool state) const {
    digitalWrite(*this->_PIN_RED, (state) ? HIGH : LOW);
    return digitalRead(*this->_PIN_RED);
}

bool LED::green(bool state) const {
    digitalWrite(*this->_PIN_GREEN, (state) ? HIGH : LOW);
    return digitalRead(*this->_PIN_GREEN);
}

bool LED::blue(bool state) const {
    digitalWrite(*this->_PIN_BLUE, (state) ? HIGH : LOW);
    return digitalRead(*this->_PIN_BLUE);
}