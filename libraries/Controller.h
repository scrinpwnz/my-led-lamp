//
// Created by scrinpwnz on 07.08.2020.
//

#ifndef MYLEDLIGHTING_CONTROLLER_H
#define MYLEDLIGHTING_CONTROLLER_H

#include "Arduino.h"
#include "Slicer.h"
#include "EffectStrategy.h"
#include "Effects/WhiteLampEffect.h"
#include "Effects/Rainbow.h"
#include "Effects/FadeInOut.h"
#include "Effects/Strobe.h"
#include "Effects/Meteor.h"
#include "Effects/RunningLights.h"
#include "Effects/Fire.h"


class Controller {
public:
    explicit Controller(Slicer *slices[], EffectStrategy *effects[]);

    void tick();

private:
    unsigned long elapsedTime;
    unsigned long timePassed;
    int _brightness = 0;
    byte _newBrightness = 255;
    byte _maxBrightness = 255;
    byte _switchEffect = 0;
    bool _readingSerial = false;
    Slicer *_currentSlice;
    Slicer **_slices;
    EffectStrategy *_currentEffect;
    EffectStrategy **_effects;

    void checkSerial();

    void handleSerial(uint16_t serial);

    void switchMode(uint16_t mode);

    void switchEffect();

    void switchSlice(byte mode);

    void setBrightness(byte b);

    void setMaxBrightness(byte b);

    void adjustBrightness();

    void setEffectDelay(uint16_t delay);

};


#endif //MYLEDLIGHTING_CONTROLLER_H
