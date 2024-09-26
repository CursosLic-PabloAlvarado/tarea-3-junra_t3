#include "biquad.h"


biquad::biquad(): b0(b0), b1(b1), b2(b2), a0(a0), a1(a1), a2(a2)
{
    x1 = x2 = 0.0;
    y1 = y2 = 0.0;
}

biquad::~biquad()
{
}

biquad::process(jack_nframes_t nframes, const sample_t *const in, sample_t *const out)
{
    double output = (b0 * input + b1 * x1 + b2 * x2) / a0 - (a1 * y1 + a2 * y2) / a0;

        // Update the previous input and output samples for the next iteration
        x2 = x1;
        x1 = input;
        y2 = y1;
        y1 = output;

        // Return the filtered output sample
        return output;
}
