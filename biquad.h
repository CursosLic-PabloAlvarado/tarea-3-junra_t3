#ifndef _BIQUAD_H
#define _BIQUAD_H


#include "jack_client.h"

class biquad {
    private:
        // Filter coefficients
        double b0, b1, b2;
        double a0, a1, a2;

        // Previous input and output samples
        double x1, x2; // Previous input samples
        double y1, y2; // Previous output samples


    public:
        biquad(double b0, double b1, double b2, double a0, double a1, double a2);
        ~biquad();
        double process(jack_nframes_t nframes, const sample_t * const in ,sample_t * const out);


};

#endif
