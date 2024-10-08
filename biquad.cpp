#include "biquad.h"

biquad::biquad(){
    b0 = 1.0;
    b1 = 1.0;
    b2 = 1.0;
    a0 = 1.0;
    a1 = 1.0;
    a2 = 1.0;
    x1 = x2 = 0.0;
    y1 = y2 = 0.0;
}


biquad::~biquad()
{
}

void biquad::set_coefficients(const std::array<sample_t, 6> &coeffs)
{
    b0 = coeffs[0];
    b1 = coeffs[1];
    b2 = coeffs[2];
    a0 = coeffs[3];
    a1 = coeffs[4];
    a2 = coeffs[5];
    x1 = x2 = 0.0;
    y1 = y2 = 0.0;
}

