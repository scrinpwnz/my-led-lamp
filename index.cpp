#include "Arduino.h"
#include "FastLED.h"
#include "libraries/Controller.h"

#define LEDS_NUM 156
#define PIN 6

CRGB leds[LEDS_NUM];

SliceLeftRight sliceLeftRight(leds, 105);
Slice sliceFull(leds, 0, LEDS_NUM);
Slice sliceFront(leds, 78, 54);
Slice sliceNoBack(leds, 54, 102);

Slicer *slices[] = {
        &sliceFull,             // 0
        &sliceLeftRight,        // 1
        &sliceFront,            // 2
        &sliceNoBack            // 3
};

WhiteLampEffect whiteLampEffect;
Rainbow rainbow;
FadeInOut fadeInOut;
Strobe strobe;
Meteor meteor;
RunningLights runningLights;
Fire fire;

EffectStrategy *effects[] = {
        nullptr,
        &whiteLampEffect,       // 1
        &rainbow,               // 2
        &fadeInOut,             // 3
        &strobe,                // 4
        &meteor,                // 5
        &runningLights,         // 6
        &fire                   // 7
};

Controller controller(slices, effects);

void setup() {
    Serial.begin(9600);
    Serial.setTimeout(10);
    FastLED.addLeds<NEOPIXEL, PIN>(leds, LEDS_NUM);
    FastLED.clear();
    FastLED.show();
}

//unsigned long timer;

void loop() {
//    timer = millis();
    controller.tick();
//    Serial.println(millis() - timer);
}



