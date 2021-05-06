#pragma once
#include <cmath>
#include <complex>
#include "../../06_Others/03_BitTechnic/06.02_bit-reverse-copy.hpp"

namespace __fft {
    using F = std::complex<long double>;
    constexpr long double EPS = 1e-12;

    /**
     * @brief 高速フーリエ変換
     * @note O(n⋅log(n))
     */
    std::vector<F> fast_fourier_transform(const std::vector<F>& a, bool is_inverse) {
        auto A = bit_reverse_copy(a);
        const std::uint32_t n = a.size();
        for (std::uint32_t s = 1; (1U << s) <= n; ++s) {
            std::uint32_t m = (1 << s);
            F wm = std::polar(1.0, 2 * M_PI / m);
            if (is_inverse) wm = std::conj(wm);
            for (std::uint32_t k = 0; k < n; k += m) {
                F w = 1;
                for (std::uint32_t j = 0; j < m / 2; ++j) {
                    F t = w * A[k + j + m / 2];
                    F u = A[k + j];
                    A[k + j] = u + t;
                    A[k + j + m / 2] = u - t;
                    w = w * wm;
                }
            }
        }
        if (is_inverse) for (auto&& elem : A) elem /= 1.0f * n;
        return A;
    }
}