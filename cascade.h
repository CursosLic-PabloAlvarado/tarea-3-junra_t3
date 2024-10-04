#ifndef CASCADE_H
#define CASCADE_H

#include "biquad.h"

template<unsigned int N>
class cascade{
    private:
        std::array<biquad<6>, N> biquads;

    public:
        typedef jack::client::sample_t sample_t;

        cascade();
        
        void set_biquads(const std::vector<std::array<sample_t, 6>> sosmatrix);

        template<unsigned int I>
        sample_t process(const sample_t in);
        
};

#include "cascade.tpp"

#endif //CASCADE_H