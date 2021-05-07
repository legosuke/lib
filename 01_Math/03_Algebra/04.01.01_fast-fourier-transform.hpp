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
    std::vector<F> fast_fourier_transform(std::vector<F> a, bool is_inverse) {
        std::uint32_t n = a.size();
        auto A = bit_reverse_copy(a);
        std::vector<F> zeta_pow;
        for (std::uint32_t i = 0; i < n; ++i) {
            long double theta = M_PI / n * i * (is_inverse ? -1 : 1);
            zeta_pow.emplace_back(cos(theta), sin(theta));
        }
        for (std::uint32_t m = 1; m < n; m <<= 1) {
            for (std::uint32_t j = 0; j < m; ++j) {
                F fac = zeta_pow[n / m * j];
                for (std::uint32_t k = 0; k < n; k += m << 1) {
                    F s = A[k + j] + fac * A[k + j + m];
                    F t = A[k + j] - fac * A[k + j + m];
                    A[k + j] = s; A[k + j + m] = t;
                }
            }
        }
        if (is_inverse) for (auto&& elem : A) elem /= (long double)n;
        return A;
    }
}