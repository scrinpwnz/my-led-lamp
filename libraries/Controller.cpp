//
// Created by scrinpwnz on 07.08.2020.
//

#include "Controller.h"

#define SWITCH_MODE 9000
#define SWITCH_LED_SLICE 8000
#define SET_EFFECT_DELAY 7000
#define SET_MAX_BRIGHT 1000
#define BRIGHTNESS 255


Controller::Controller(Slicer *slices[], EffectStrategy *effects[]) {
    _slices = slices;
    _currentSlice = _slices[0];
    _currentSlice->init();
    _effects = effects;
    _currentEffect = _effects[1];
    _currentEffect->setSlice(_currentSlice);
}

void Controller::tick() {
    checkSerial();
    if (_switchEffect > 0) switchEffect();
    if (!_readingSerial) {
        elapsedTime = millis();
        _currentEffect->tick();
        timePassed = millis() - elapsedTime;
        adjustBrightness();
        FastLED.show();
    }
}

void Controller::checkSerial() {
    if (Serial.available() > 0) {
        if (_readingSerial) {
            handleSerial(Serial.parseInt());
            _readingSerial = false;
        } else {
            if (Serial.read() == 99) _readingSerial = true;
        }
    }
}

void Controller::handleSerial(uint16_t serial) {
    if (serial >= SWITCH_MODE) {
        switchMode(serial - SWITCH_MODE);
        return;
    }
    if (serial >= SWITCH_LED_SLICE) {
        switchSlice(serial - SWITCH_LED_SLICE);
        return;
    }
    if (serial >= SET_EFFECT_DELAY) {
        setEffectDelay(serial - SET_EFFECT_DELAY);
        return;
    }
    if (serial >= SET_MAX_BRIGHT) {
        setMaxBrightness(serial - SET_MAX_BRIGHT);
        return;
    }
    if (serial <= BRIGHTNESS) {
        setBrightness(serial);
        return;
    }
}

void Controller::switchMode(uint16_t mode) {
    if (mode > 0) {
        _switchEffect = mode;
        _newBrightness = 0;
    }
}

void Controller::switchEffect() {
    if (_brightness == 0) {
        _currentEffect = _effects[_switchEffect];
        _currentEffect->setSlice(_currentSlice);
        _switchEffect = 0;
        _newBrightness = 255;
    }
}

void Controller::setBrightness(byte b) {
    if (_switchEffect == 0) _newBrightness = b;
}

void Controller::setMaxBrightness(byte b) {
    _maxBrightness = b;
}

void Controller::adjustBrightness() {
    int incr = (int)timePassed / 8;
    if (incr < 1) incr = 1;
    if (_brightness != _newBrightness) {
        if (_brightness < _newBrightness) {
            _brightness += incr;
            if (_brightness > _newBrightness) _brightness = _newBrightness;
        }
        else {
            _brightness -= incr;
            if (_brightness < _newBrightness) _brightness = _newBrightness;
        }
    };
    if (_brightness > _maxBrightness) {
        _brightness = _maxBrightness;
        _newBrightness = _brightness;
    }
    FastLED.setBrightness(_brightness);

}

void Controller::switchSlice(byte mode) {
    FastLED.clear();
    _currentSlice = _slices[mode];
    _currentSlice->init();
    _currentEffect->setSlice(_currentSlice);
}

void Controller::setEffectDelay(uint16_t delay) {
    _currentEffect->setDelay(delay);
}



