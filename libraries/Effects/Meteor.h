//
// Created by scrinpwnz on 13.08.2020.
//

#ifndef MYLEDLIGHTING_METEOR_H
#define MYLEDLIGHTING_METEOR_H


#include "../EffectStrategy.h"

class Meteor: public EffectStrategy {
public:
    Meteor() {_delay = 20;};

    void tick() override;

private:
    byte _i = 0;
    byte _meteorSize = 4;
    byte _meteorTrailDecay = 80;
    bool _meteorRandomDecay = true;
    byte _random = random8();

    void increment();
};

#endif //MYLEDLIGHTING_METEOR_H
