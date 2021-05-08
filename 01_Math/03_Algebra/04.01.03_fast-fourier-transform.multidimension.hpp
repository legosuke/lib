#pragma once
#include "04.01.01.02_fast-fourier-transform.arbitrary.hpp"

namespace __fft {
    /**
     * @brief 多次元高速フーリエ変換
     * @note O(n⋅lg(n))
     */
    std::vector<F> multidimension_fast_fourier_transform(std::vector<F> a, std::vector<std::uint32_t> ns, bool is_inverse) {
        std::uint32_t d = ns.size(), n = a.size(), pm = 1, m = 1;
        for (std::uint32_t k = 0; k < d; ++k) {
            m *= ns[k];
            for (std::uint32_t s = 0; s < n; s += m) {
                for (std::uint32_t t = 0; t < pm; ++t) {
                    std::vector<F> x;
                    for (std::uint32_t u = 0; u < ns[k]; ++u) {
                        x.emplace_back(a[s + t + pm * u]);
                    }
                    auto y = fast_fourier_transform_arbitrary(x, is_inverse);
                    for (std::uint32_t u = 0; u < ns[k]; ++u) {
                        a[s + t + pm * u] = y[u];
                    }
                }
            }
            pm = m;
        }
        return a;
    }
}