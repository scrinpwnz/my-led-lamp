//
// Created by scrinpwnz on 09.08.2020.
//

#include "Rainbow.h"

void Rainbow::tick() {
    if (millisDelay(_delay, &_timer)) {
        for (uint16_t i = 0; i < _slice->getSliceSize(); i++) {
            _c = wheel(((i * 256 / _slice->getSliceSize()) + _j) & 255);
            setCRGB(i, *_c, *(_c + 1), *(_c + 2));
        }
        _j++;
        if (_j >= 1280) _j = 0;
    }
}
