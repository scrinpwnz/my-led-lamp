//
// Created by scrinpwnz on 12.08.2020.
//

#ifndef MYLEDLIGHTING_STROBE_H
#define MYLEDLIGHTING_STROBE_H

#include "../EffectStrategy.h"

class Strobe : public EffectStrategy {
public:
    Strobe();
    void tick() override;

private:
    bool _on = true;
};


#endif //MYLEDLIGHTING_STROBE_H
