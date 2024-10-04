template <unsigned int N>
cascade<N>::cascade(){}

template<unsigned int N>
template<unsigned int I>
inline typename cascade<N>::sample_t cascade<N>::process(sample_t in){
    if constexpr (I < N){
        return process<I+1>(biquads[I].process(in));
    }else{
        return in;
    }
}

template<unsigned int N>
void cascade<N>::set_biquads(const std::vector<std::array<sample_t, 6>> sosmatrix){
    for(size_t i=0; i<N; i++){
        biquads[i].set_coefficients(sosmatrix[i]);
    }
}

