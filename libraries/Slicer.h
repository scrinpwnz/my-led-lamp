//
// Created by scrinpwnz on 18.08.2020.
//

#ifndef MYLEDLIGHTING_SLICER_H
#define MYLEDLIGHTING_SLICER_H

#include "FastLED.h"

#ifndef LEDS_NUM
#define LEDS_NUM 156
#endif

class Slicer {
public:
    static void createSlice(CRGB *leds, CRGB **slice, byte ledsStartPosition, byte startPosition, byte size, char step);

    virtual void init() = 0;

    virtual void fadeToBlackBy(byte pixel, byte decay) = 0;

    virtual void setCHSV(byte pixel, byte h, byte s, byte v) = 0;

    virtual void setCRGB(byte pixel, byte r, byte g, byte b) = 0;

    void setAllCRGB(byte r, byte g, byte b);

    void setAllCHSV(byte h, byte s, byte v);

    byte getSliceSize();

protected:
    inline static CRGB *_leds;
    inline static CRGB *_slice[LEDS_NUM];
    byte _sliceSize;
};

class Slice : public Slicer {
public:
    Slice(CRGB *leds, byte startPosition, byte sliceSize);

    void init() override;

    void fadeToBlackBy(byte pixel, byte decay) override;

    void setCHSV(byte pixel, byte h, byte s, byte v) override;

    void setCRGB(byte pixel, byte r, byte g, byte b) override;

private:
    byte _startPosition;
};

class SliceLeftRight : public Slicer {
public:
    SliceLeftRight(CRGB *leds, byte centerPlusOne);

    void init() override;

    void fadeToBlackBy(byte pixel, byte decay) override;

    void setCHSV(byte pixel, byte h, byte s, byte v) override;

    void setCRGB(byte pixel, byte r, byte g, byte b) override;

private:
    byte _centerPlusOne;

};

#endif //MYLEDLIGHTING_SLICER_H
