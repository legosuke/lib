#pragma once
#include "04.01.01_fast-fourier-transform.hpp"
#include "../../06_Others/03_BitTechnic/08.02_bit-pow2.bit-ceil.hpp"

namespace __fft {
    /**
     * @brief 畳み込み (高速フーリエ変換)
     * @note O(n⋅lg(n))
     */
    template <typename T>
    std::vector<F> convolution(std::vector<T> _a, std::vector<T> _b) {
        std::uint32_t na = _a.size(), nb = _b.size();
        std::uint32_t nc = __bit_pow2::bit_ceil(na + nb - 1);
        std::vector<F> a, b;
        for (auto&& elem : _a) a.emplace_back(elem, 0);
        for (auto&& elem : _b) b.emplace_back(elem, 0);
        a.resize(nc); b.resize(nc);
        auto dfta = fast_fourier_transform(a, false);
        auto dftb = fast_fourier_transform(b, false);
        decltype(a) dftc(nc);
        for (std::uint32_t i = 0; i < nc; ++i) {
            dftc[i] = dfta[i] * dftb[i];
        }
        auto c = fast_fourier_transform(dftc, true);
        return c;
    }

    std::vector<std::int64_t> integral_convolution(std::vector<std::int_least32_t> a, std::vector<std::int_least32_t> b) {
        auto c = convolution(a, b);
        std::vector<std::int64_t> res;
        for (auto&& elem : c) res.emplace_back(std::floor(elem.real() + 0.5));
        return res;
    }

    std::vector<std::double_t> real_convolution(std::vector<std::double_t> a, std::vector<std::double_t> b) {
        auto c = convolution(a, b);
        std::vector<std::double_t> res;
        for (auto&& elem : c) res.emplace_back(elem.real());
        return res;
    }
}