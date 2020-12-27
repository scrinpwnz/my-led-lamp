//
// Created by scrinpwnz on 08.08.2020.
//

#include "EffectStrategy.h"

bool EffectStrategy::millisDelay(uint32_t t, uint32_t *timer) {
    if (millis() - *timer > t) {
        *timer = millis();
        return true;
    }
    return false;
}

void EffectStrategy::setSlice(Slicer *slice) {
    _slice = slice;
}

void EffectStrategy::setDelay(uint16_t delay) {
    _delay = delay;
}

void EffectStrategy::setCHSV(byte pixel, byte h, byte s, byte v) {
    _slice->setCHSV(pixel, h, s, v);
}

void EffectStrategy::setCRGB(byte pixel, byte r, byte g, byte b) {
    _slice->setCRGB(pixel, r, g, b);
}

void EffectStrategy::setAllCRGB(byte r, byte g, byte b) {
    _slice->setAllCRGB(r, g, b);
}

void EffectStrategy::setAllCHSV(byte h, byte s, byte v) {
    _slice->setAllCHSV(h, s, v);
}

byte *EffectStrategy::wheel(byte wheelPos) {
    static byte c[3];

    if (wheelPos < 85) {
        c[0] = wheelPos * 3;
        c[1] = 255 - wheelPos * 3;
        c[2] = 0;
    } else if (wheelPos < 170) {
        wheelPos -= 85;
        c[0] = 255 - wheelPos * 3;
        c[1] = 0;
        c[2] = wheelPos * 3;
    } else {
        wheelPos -= 170;
        c[0] = 0;
        c[1] = wheelPos * 3;
        c[2] = 255 - wheelPos * 3;
    }

    return c;
}












