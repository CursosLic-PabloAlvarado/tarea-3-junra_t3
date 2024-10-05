#ifndef _BIQUAD_H
#define _BIQUAD_H


#include "jack_client.h"
#include "array"

class biquad {
    typedef jack::client::sample_t sample_t;
    private:
        sample_t b0, b1, b2;
        sample_t a0, a1, a2;
        sample_t x1, x2;
        sample_t y1, y2;


    public:
		

        biquad();

        ~biquad();

        void set_coefficients(const std::array<sample_t, 6>& coeffs);
        sample_t process(const sample_t in);


};

#endif

