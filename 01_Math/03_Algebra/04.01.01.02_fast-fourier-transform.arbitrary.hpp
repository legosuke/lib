#pragma once
#include <cmath>
#include <complex>
#include "04.01.02_fast-fourier-transform.chirp-transform.hpp"

namespace __fft {
    /**
     * @brief 高速フーリエ変換 (任意長)
     * @note O(n⋅lg(n))
     */
    std::vector<F> fast_fourier_transform_arbitrary(std::vector<F> a, bool is_inverse) {
        std::uint32_t n = a.size();
        F wn = std::polar(1.0, 2 * M_PI / n * (is_inverse ? -1 : 1));
        auto y = chirp_transform(a, wn);
        if (is_inverse) for (auto&& elem : y) elem /= n;
        return y;
    }
}