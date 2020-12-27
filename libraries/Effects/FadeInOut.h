//
// Created by scrinpwnz on 12.08.2020.
//

#ifndef MYLEDLIGHTING_FADEINOUT_H
#define MYLEDLIGHTING_FADEINOUT_H

#include "../EffectStrategy.h"

class FadeInOut : public EffectStrategy {
public:

    void tick() override;

private:
    byte _j;
    byte _i;
    char _inc = 1;

    void increment();
};


#endif //MYLEDLIGHTING_FADEINOUT_H
