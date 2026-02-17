
# LED for arduino, ESP32 and raspberryPi
## Initialization
```c++
#include <led.h>
LED *_LED;
int _LED_RED_PIN = 3
int _LED_GREEN_PIN = 2
int _LED_BLUE_PIN = 4

void setup() {
  LED = new LED(_LED_RED_PIN, _LED_GREEN_PIN, _LED_BLUE_PIN);
}
```

## Delete
```c++
delete _LED;
```

## Commands
#### turn on/off red
```c++
bool state = true; // true: turn on | false: turn off

bool turnOn = _LED->red(state);
if (turnOn)
  { Serial.println("Red turned on"); }
else { Serial.println("Red turned off"); }
```

#### turn on/off green
```c++
bool state = true; // true: turn on | false: turn off

bool turnOn = _LED->green(state);
if (turnOn)
  { Serial.println("Green turned on"); }
else { Serial.println("Green turned off"); }
```

#### turn on/off blue
```c++
bool state = true; // true: turn on | false: turn off

bool turnOn = _LED->blue(state);
if (turnOn)
  { Serial.println("Blue turned on"); }
else { Serial.println("Blue turned off"); }
```

#### Turn off all of leds
```c++
bool turnOn = _LED->clear();
if (turnOn)
  { Serial.println("Failed to clear"); }
else { Serial.println("All leds are turned off"); }
```

