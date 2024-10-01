#ifndef _BIQUAD_H
#define _BIQUAD_H


#include "jack_client.h"

template<int Order>
class biquad {
    private:
        double b0, b1, b2;
        double a0, a1, a2;
        double x1, x2;
        double y1, y2;


    public:
        biquad(const std::array<sample_t, Order>& coeffs)
            : bo(coeffs[0]), b1(coeffs[1]), b2(coeffs[2]),
              a0(coeffs[3]), a1(coeffs[4], a2(coeffs[5])) {
                x1 = x2 = 0.0;
                y1 = y2 = 0.0;
              }

        ~biquad(){};

        double process(const sample_t * const in){
            double output = (b0 * input + b1 * x1 + b2 * x2) / a0 - (a1 * y1 + a2 * y2) / a0;
            x2 = x1;
            x1 = input;
            y2 = y1;
            y1 = output;

            return output;
        }


};

#endif
