//
// Created by scrinpwnz on 13.08.2020.
//

#include "Meteor.h"

void Meteor::tick() {
    if (millisDelay(_delay, &_timer)) {
        for (uint16_t j = 0; j < _slice->getSliceSize(); j++) {
            if ((!_meteorRandomDecay) || (random(10) > 5)) {
                _slice->fadeToBlackBy(j, _meteorTrailDecay);
            }
        }
        for (byte j = 0; j < _meteorSize; j++) {
            if ((_i - j < _slice->getSliceSize()) && (_i - j >= 0)) {
                _random = _random + random(-2, 3);
                _slice->setCHSV(_i - j, _random, 255, 255);
            }
        }
        increment();
    }
}

void Meteor::increment() {
    _i = _i + 1;
    if (_i >= _slice->getSliceSize()) _i = 0;
}