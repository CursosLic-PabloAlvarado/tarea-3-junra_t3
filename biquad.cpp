#include "biquad.h"

template <int Order>
biquad<Order>::biquad(){
    b0 = 1.0;
    b1 = 1.0;
    b2 = 1.0;
    a0 = 1.0;
    a1 = 1.0;
    a2 = 1.0;
    x1 = x2 = 0.0;
    y1 = y2 = 0.0;
}

template <int Order>
inline biquad<Order>::~biquad()
{
}

template <int Order>
inline void biquad<Order>::set_coefficients(const std::array<sample_t, Order> &coeffs)
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

template <int Order>
inline typename biquad<Order>::sample_t biquad<Order>::process(const sample_t in){
  double output = (b0 * in + b1 * x1 + b2 * x2) / a0 - (a1 * y1 + a2 * y2) / a0;
  x2 = x1;
  x1 = in;
  y2 = y1;
  y1 = output;

  return output;
}

template class biquad<6>;
