#pragma once
#include <cstdlib>
#include "05.01.01_convolution.fast-fourier-transform.hpp"

namespace __fft {
    /**
     * @brief チャープ変換
     * @note O(n⋅lg(n))
     */
    std::vector<F> chirp_transform(std::vector<F> a, F z) {
        std::uint32_t n = a.size();
        std::vector<F> b(2 * n - 1, 0), c(2 * n - 1);
        F z0 = std::sqrt(z), z1 = 1, z2 = 1;
        std::vector<F> zs;
        for (std::uint32_t j = 0; j < n; ++j) {
            b[j] = a[j] * z2;
            zs.emplace_back(z2);
            z2 = z2 * z1 * z0;
            z1 = z1 * z;
        }
        for (std::uint32_t j = 0; j < 2 * n - 1; ++j) {
            if (j < n - 1) c[j] = std::conj(zs[n - 1 - j]);
            else c[j] = std::conj(zs[j - n + 1]);
        }
        std::vector<F> y0 = convolution(b, c), y;
        for (std::uint32_t k = 0; k < n; ++k) {
            y.emplace_back(y0[k + n - 1] * zs[k]);
        }
        return y;
    }
}