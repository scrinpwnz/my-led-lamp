//
// Created by scrinpwnz on 12.08.2020.
//

#include "Strobe.h"


Strobe::Strobe() {
    _delay = 2;
}

void Strobe::tick() {
    if (_on) {
        setAllCRGB(0xEB, 0x6B, 0xFF);
        if (millisDelay(_delay, &_timer)) {
            _on = false;
        }
    } else {
        setAllCRGB(0, 0, 0);
        if (millisDelay(_delay*25, &_timer)) {
            _on = true;
        }
    }
}

