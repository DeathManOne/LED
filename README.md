# LED for ESP32
Complete RGB LED control library for ESP32 using PWM.
Compatible with Arduino framework and PlatformIO.

---
# Features
* RGB LED control
* PWM brightness control
* Hexadecimal colors support
* Common anode and common cathode support
* Predefined colors
* ESP32 hardware PWM using LEDC
* Simple and lightweight API

---
# Installation
## PlatformIO
Add in `platformio.ini`:
```ini
lib_deps =
    https://github.com/DeathManOne/LED.git
```

## Arduino IDE
Clone or download the repository into your `libraries` folder.

---
# Initialization
```cpp
#include <Arduino.h>
#include <led.h>

LED *led;

void setup() {
    led = new LED(
        21,     // red pin
        22,     // green pin
        23,     // blue pin
        true    // common anode
    );
}
```

---
# Constructor
```cpp
LED(
    int pinRed,
    int pinGreen,
    int pinBlue,
    bool commonAnode = false,
    uint32_t frequency = 5000,
    uint8_t resolution = 8
);
```

## Parameters
| Parameter     | Description                       |
| ------------- | --------------------------------- |
| `pinRed`      | GPIO of red LED                   |
| `pinGreen`    | GPIO of green LED                 |
| `pinBlue`     | GPIO of blue LED                  |
| `commonAnode` | `true` if RGB LED is common anode |
| `frequency`   | PWM frequency                     |
| `resolution`  | PWM resolution                    |

---
# Common Anode / Common Cathode
Two RGB LED types exist:
## Common cathode
Most common type.
Use:
```cpp
false
```
Example:
```cpp
LED led(21, 22, 23, false);
```

---
## Common anode
Colors are electrically inverted.
Use:
```cpp
true
```
Example:
```cpp
LED led(21, 22, 23, true);
```
If colors are inverted:
* `red()` gives cyan
* `blue()` gives yellow
then your LED is probably common anode.

---
# Methods

---
# RGB State
## Set RGB state
```cpp
led->rgb(true, false, true);
```

| Color | Value            |
| ----- | ---------------- |
| Red   | First parameter  |
| Green | Second parameter |
| Blue  | Third parameter  |

Example:
```cpp
led->rgb(true, false, false); // red
led->rgb(false, true, false); // green
led->rgb(false, false, true); // blue
led->rgb(true, true, true); // white
```

---
# Hexadecimal colors
## Set color from hexadecimal value
```cpp
led->hex(0xFF0000);
```

Examples:
```cpp
led->hex(0xFF0000); // red
led->hex(0x00FF00); // green
led->hex(0x0000FF); // blue
led->hex(0xFFFFFF); // white
led->hex(0xFFFF00); // yellow
led->hex(0xFF8000); // orange
```

---
# Predefined colors
## Red
```cpp
led->red();
```

## Green
```cpp
led->green();
```

## Blue
```cpp
led->blue();
```

## White
```cpp
led->white();
```

## Yellow
```cpp
led->yellow();
```

## Orange
```cpp
led->orange();
```

## Cyan
```cpp
led->cyan();
```

## Magenta
```cpp
led->magenta();
```

---
# Turn off LED
```cpp
led->clear();
```

---
# Complete example
```cpp
#include <Arduino.h>
#include <led.h>

LED led(
    21,
    22,
    23,
    true
);

void setup() {
    led.red();
    delay(1000);

    led.green();
    delay(1000);

    led.blue();
    delay(1000);

    led.white();
    delay(1000);

    led.hex(0xFF8000);
    delay(1000);

    led.clear();
}

void loop() {
}
```

---
# Notes
* PWM is handled using ESP32 LEDC hardware.
* Compatible with Arduino Nano ESP32.
* RGB brightness values go from `0` to `255`.
* `hex()` uses standard RGB hexadecimal colors.

---
# License
GNU GPL v3 or later.
