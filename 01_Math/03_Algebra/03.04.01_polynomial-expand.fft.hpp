#pragma once
#include "05.01_convolution.fast-fourier-transform.hpp"
#include "../../06_Others/03_BitTechnic/08.02_bit-pow2.bit-ceil.hpp"

namespace __fft {
    /**
     * @brief 多項式展開 (高速フーリエ変換)
     */
    std::vector<F> polynomial_expand(std::vector<F> z) {
        std::uint32_t n = __bit_pow2::bit_ceil(z.size());
        std::vector<std::vector<F>> a(n);
        for (std::uint32_t i = 0; i < n; ++i) {
            if (i < z.size()) a[i] = std::vector<F>{-z[i], 1};
            else a[i] = std::vector<F>{1};
        }
        while (a.size() > 1) {
            std::vector<std::vector<F>> b;
            for (std::uint32_t i = 0; i < a.size(); i += 2) {
                b.emplace_back(convolution(a[i], a[i + 1]));
            }
            swap(a, b);
        }
        return a.front();
    }
}