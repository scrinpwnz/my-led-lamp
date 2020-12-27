//
// Created by scrinpwnz on 20.08.2020.
//

#ifndef MYLEDLIGHTING_FIRE_H
#define MYLEDLIGHTING_FIRE_H

#include "../EffectStrategy.h"

class Fire : public EffectStrategy {
public:
    Fire() {_delay = 20;};
    void tick() override;

private:
    void setPixelHeatColor(byte pixel, byte temperature);

    int Cooling = 55;
    int Sparking = 120;
};


#endif //MYLEDLIGHTING_FIRE_H
