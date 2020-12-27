//
// Created by scrinpwnz on 08.08.2020.
//

#include "WhiteLampEffect.h"


void WhiteLampEffect::tick() {
    if (millisDelay(_delay, &_timer)) setAllCRGB(255, 255, 255);
}




