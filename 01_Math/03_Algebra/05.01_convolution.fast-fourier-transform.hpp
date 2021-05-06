#pragma once
#include "04.01_fast-fourier-transform.hpp"
#include "../../06_Others/03_BitTechnic/08.02_bit-pow2.bit-ceil.hpp"

namespace __fft {
    /**
     * @brief 畳み込み (高速フーリエ変換)
     * @note O(n⋅log(n))
     */
    std::vector<F> convolution(std::vector<F> a, std::vector<F> b) {
        std::uint32_t na = a.size(), nb = b.size(), nc = __bit_pow2::bit_ceil(na + nb - 1);
        a.resize(nc);
        b.resize(nc);
        auto dfta = fast_fourier_transform(a, false);
        auto dftb = fast_fourier_transform(b, false);
        decltype(a) dftc(nc);
        for (std::uint32_t i = 0; i < nc; ++i) {
            dftc[i] = dfta[i] * dftb[i];
        }
        auto c = fast_fourier_transform(dftc, true);
        return c;
    }
}