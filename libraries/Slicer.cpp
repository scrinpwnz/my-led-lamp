//
// Created by scrinpwnz on 18.08.2020.
//

#include "Slicer.h"

void Slicer::createSlice(CRGB *leds, CRGB **slice, byte ledsStartPosition, byte startPosition, byte size, char step) {
    if (startPosition > LEDS_NUM - 1) startPosition = LEDS_NUM - 1;
    for (int j = 0, i = startPosition; j < size; i += step, j++) {
        if (i < 0 && step < 0) i = LEDS_NUM - 1;
        if (i > LEDS_NUM - 1 && step > 0) i = 0;
        slice[j + ledsStartPosition] = &leds[i];
    }
}

void Slicer::setAllCRGB(byte r, byte g, byte b) {
    for (int i = 0; i < _sliceSize; i++) {
        setCRGB(i, r, g, b);
    }
}

void Slicer::setAllCHSV(byte h, byte s, byte v) {
    for (int i = 0; i < _sliceSize; i++) {
        setCHSV(i, h, s, v);
    }
}

byte Slicer::getSliceSize() {
    return _sliceSize;
}

Slice::Slice(CRGB *leds, byte startPosition, byte sliceSize) {
    _leds = leds;
    _sliceSize = sliceSize;
    _startPosition = startPosition;
}

void Slice::init() {
    createSlice(_leds, _slice, 0, _startPosition, _sliceSize, 1);
}

void Slice::fadeToBlackBy(byte pixel, byte decay) {
    _slice[pixel]->fadeToBlackBy(decay);
}

void Slice::setCHSV(byte pixel, byte h, byte s, byte v) {
    *_slice[pixel] = CHSV(h,s,v);
}

void Slice::setCRGB(byte pixel, byte r, byte g, byte b) {
    *_slice[pixel] = CRGB(r,g,b);
}

SliceLeftRight::SliceLeftRight(CRGB *leds, byte centerPlusOne) {
    _leds = leds;
    _sliceSize = LEDS_NUM / 2;
    _centerPlusOne = centerPlusOne;
}

void SliceLeftRight::init() {
    createSlice(_leds, _slice, 0, _centerPlusOne, _sliceSize, 1);
    createSlice(_leds, _slice, _sliceSize, _centerPlusOne - 1, _sliceSize, -1);
}

void SliceLeftRight::fadeToBlackBy(byte pixel, byte decay) {
    _slice[pixel]->fadeToBlackBy(decay);
    _slice[pixel + _sliceSize]->fadeToBlackBy(decay);
}

void SliceLeftRight::setCHSV(byte pixel, byte h, byte s, byte v) {
    *_slice[pixel] = CHSV(h,s,v);
    *_slice[pixel + _sliceSize] = CHSV(h,s,v);
}

void SliceLeftRight::setCRGB(byte pixel, byte r, byte g, byte b) {
    *_slice[pixel] = CRGB(r,g,b);
    *_slice[pixel + _sliceSize] = CRGB(r,g,b);
}
