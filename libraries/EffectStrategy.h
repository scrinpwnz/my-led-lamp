//
// Created by scrinpwnz on 08.08.2020.
//

#ifndef MYLEDLIGHTING_EFFECTSTRATEGY_H
#define MYLEDLIGHTING_EFFECTSTRATEGY_H

#include "FastLED.h"
#include "Slicer.h"

class EffectStrategy {
public:
    virtual void tick() = 0;

    void setSlice(Slicer *slice);

    void setDelay(uint16_t delay);

protected:
    Slicer *_slice = nullptr;
    uint32_t _timer = millis();
    uint16_t _delay = 0;

    static bool millisDelay(uint32_t t, uint32_t *timer);

    void setCHSV(byte pixel, byte h, byte s, byte v);

    void setCRGB(byte pixel, byte r, byte g, byte b);

    void setAllCRGB(byte r, byte g, byte b);

    void setAllCHSV(byte h, byte s, byte v);

    static byte *wheel(byte wheelPos);
};

#endif //MYLEDLIGHTING_EFFECTSTRATEGY_H


