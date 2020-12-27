//
// Created by scrinpwnz on 12.08.2020.
//

#include "FadeInOut.h"


void FadeInOut::tick() {
    if (millisDelay(_delay, &_timer)) {
        switch (_j) {
            case 0:
                setAllCRGB(_i, 0, 0);
                break;
            case 1:
                setAllCRGB(0, _i, 0);
                break;
            case 2:
                setAllCRGB(0, 0, _i);
                break;
        }
        increment();
    }
}

void FadeInOut::increment() {
    _i = _i + _inc;
    if (_i >= 255) _inc = -1;
    if (_i <= 0) {
        _inc = 1;
        _j++;
        if (_j > 2) _j = 0;
    }
}
