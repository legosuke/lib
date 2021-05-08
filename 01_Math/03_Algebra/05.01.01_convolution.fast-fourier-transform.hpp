#pragma once
#include "04.01.01.01_fast-fourier-transform.hpp"
#include "../../06_Others/03_BitTechnic/08.02_bit-pow2.bit-ceil.hpp"

namespace __fft {
    /**
     * @brief 畳み込み (高速フーリエ変換)
     * @note O(n⋅lg(n))
     */
    std::vector<F> convolution(std::vector<F> a, std::vector<F> b) {
        std::uint32_t na = a.size(), nb = b.size();
        std::uint32_t nc = __bit_pow2::bit_ceil(na + nb - 1);
        a.resize(nc); b.resize(nc);
        auto dfta = fast_fourier_transform(a, false);
        auto dftb = fast_fourier_transform(b, false);
        decltype(a) dftc(nc);
        for (std::uint32_t i = 0; i < nc; ++i) {
            dftc[i] = dfta[i] * dftb[i];
        }
        auto c = fast_fourier_transform(dftc, true);
        c.resize(na + nb - 1);
        return c;
    }

    std::vector<std::int64_t> integral_convolution(std::vector<std::int_least32_t> a, std::vector<std::int_least32_t> b) {
        std::vector<F> _a(begin(a), end(a)), _b(begin(b), end(b));
        auto c = convolution(_a, _b);
        std::vector<std::int64_t> res;
        for (auto&& elem : c) res.emplace_back(std::floor(elem.real() + 0.5));
        return res;
    }

    std::vector<std::double_t> real_convolution(std::vector<std::double_t> a, std::vector<std::double_t> b) {
        std::vector<F> _a(begin(a), end(a)), _b(begin(b), end(b));
        auto c = convolution(_a, _b);
        std::vector<std::double_t> res;
        for (auto&& elem : c) res.emplace_back(elem.real());
        return res;
    }
}