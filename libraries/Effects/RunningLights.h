//
// Created by scrinpwnz on 18.08.2020.
//

#ifndef MYLEDLIGHTING_RUNNINGLIGHTS_H
#define MYLEDLIGHTING_RUNNINGLIGHTS_H

#include "../EffectStrategy.h"

class RunningLights: public EffectStrategy {
public:
    void tick() override;

protected:
    int _position = 0;
    byte _red = 255, _green = 255, _blue = 255;
};


#endif //MYLEDLIGHTING_RUNNINGLIGHTS_H
