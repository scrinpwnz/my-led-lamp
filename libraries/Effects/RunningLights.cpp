//
// Created by scrinpwnz on 18.08.2020.
//

#include "RunningLights.h"

void RunningLights::tick() {
    if (millisDelay(_delay, &_timer)) {
        _position++;
        for (int i = 0; i < _slice->getSliceSize(); i++) {
            setCRGB(i, ((sin(i + _position) * 127 + 128) / 255) * _red,
                     ((sin(i + _position) * 127 + 128) / 255) * _green,
                     ((sin(i + _position) * 127 + 128) / 255) * _blue);
        }
    }
}
