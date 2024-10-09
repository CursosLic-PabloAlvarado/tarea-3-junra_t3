#ifndef CASCADE_H
#define CASCADE_H

#include "biquad.h"

template<unsigned int N>
class cascade{
    private:
        std::array<biquad, N> biquads;

    public:
        typedef jack::client::sample_t sample_t;

        cascade();
        ~cascade();
        
        /**
         * sets the coefficients of every biquad
         * @param sosmatrix matrix where each row represents a biquad and each column is 
         * a coefficient
         */
        void set_biquads(const std::vector<std::array<sample_t, 6>> sosmatrix);

        /**
         * passes the audio data from one biquad to another
         * @param in audio data
         * @return processed audio
         */
        template<unsigned int I>
        sample_t process(const sample_t in);
        
};

#include "cascade.tpp"

#endif //CASCADE_H