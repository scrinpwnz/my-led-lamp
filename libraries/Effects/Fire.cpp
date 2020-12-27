//
// Created by scrinpwnz on 20.08.2020.
//

#include "Fire.h"
void Fire::tick() {
    if (millisDelay(_delay, &_timer)) {
        static byte heat[LEDS_NUM];
        int cooldown;

        // Step 1.  Cool down every cell a little
        for( int i = 0; i < _slice->getSliceSize(); i++) {
            cooldown = random(0, ((Cooling * 10) / _slice->getSliceSize()) + 2);

            if(cooldown>heat[i]) {
                heat[i]=0;
            } else {
                heat[i]=heat[i]-cooldown;
            }
        }

        // Step 2.  Heat from each cell drifts 'up' and diffuses a little
        for( int k= _slice->getSliceSize() - 1; k >= 2; k--) {
            heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
        }

        // Step 3.  Randomly ignite new 'sparks' near the bottom
        if( random(255) < Sparking ) {
            int y = random(7);
            heat[y] = heat[y] + random(160,255);
            //heat[y] = random(160,255);
        }

        // Step 4.  Convert heat to LED colors
        for( int j = 0; j < _slice->getSliceSize(); j++) {
            setPixelHeatColor(j, heat[j] );
        }
    }
}

void Fire::setPixelHeatColor(byte pixel, byte temperature) {
    // Scale 'heat' down from 0-255 to 0-191
    byte t192 = round((temperature/255.0)*191);

    // calculate ramp up from
    byte heatramp = t192 & 0x3F; // 0..63
    heatramp <<= 2; // scale up to 0..252

    // figure out which third of the spectrum we're in:
    if( t192 > 0x80) {                     // hottest
        setCRGB(pixel, 255, 255, heatramp);
    } else if( t192 > 0x40 ) {             // middle
        setCRGB(pixel, 255, heatramp, 0);
    } else {                               // coolest
        setCRGB(pixel, heatramp, 0, 0);
    }
}
