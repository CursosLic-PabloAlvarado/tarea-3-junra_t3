template <unsigned int N>
cascade<N>::cascade()
{
    nbiquads = N;
}

template<unsigned int N>
template<unsigned int I>
cascade<T>::sample_t cascade<T>::process(const sample_t in){
    if constexpr (I < N){
        return process<I+1>(biquads[I].process(in));
    }else{
        return in;
    }
}

template<unsigned int N>
void cascade<N>::set_biquads(const std::array<std::array<float, 6>, N> sosmatrix){
    for(size_t i=0; i<N; i++){
        biquad bq = biquad(sosmatrix[i])
        biquads[i] = bq;
    }
}

