#ifndef _BIQUAD_H
#define _BIQUAD_H


#include "jack_client.h"
#include "array"

template<int Order>
class biquad {
    private:
        double b0, b1, b2;
        double a0, a1, a2;
        double x1, x2;
        double y1, y2;


    public:
		typedef jack::client::sample_t sample_t;

        biquad();

        ~biquad();

        void set_coefficients(const std::array<sample_t, Order>& coeffs);
        sample_t process(const sample_t in);


};

#endif

