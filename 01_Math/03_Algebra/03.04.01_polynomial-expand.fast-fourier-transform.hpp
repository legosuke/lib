#pragma once
#include "05.01_convolution.fast-fourier-transform.hpp"
#include "../../06_Others/03_BitTechnic/08.02_bit-pow2.bit-ceil.hpp"

namespace __fft {
    /**
     * @brief 多項式展開 (高速フーリエ変換)
     * @note O(n⋅log²(n))
     */
    template <typename T>
    std::vector<T> polynomial_expand(std::vector<std::vector<T>> p) {
        std::uint32_t n = __bit_pow2::bit_ceil(p.size());
        while (p.size() < n) p.emplace_back(std::vector<T>{1});
        while (p.size() > 1) {
            std::vector<std::vector<T>> q;
            for (std::uint32_t i = 0; i < p.size(); i += 2) {
                q.emplace_back(convolution(p[i], p[i + 1]));
            }
            std::swap(p, q);
        }
        return p.front();
    }
}