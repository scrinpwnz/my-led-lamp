//
// Created by scrinpwnz on 09.08.2020.
//

#ifndef MYLEDLIGHTING_RAINBOW_H
#define MYLEDLIGHTING_RAINBOW_H

#include "../EffectStrategy.h"

class Rainbow: public EffectStrategy {
public:
    void tick() override;

private:
    byte *_c;
    uint16_t _j;

};


#endif //MYLEDLIGHTING_RAINBOW_H
