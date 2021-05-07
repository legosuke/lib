#pragma once
#include "04.01.01_fast-fourier-transform.hpp"
#include "../../06_Others/03_BitTechnic/08.02_bit-pow2.bit-ceil.hpp"

namespace __fft {
    /**
     * @brief 畳み込み (高速フーリエ変換)
     * @note O(n⋅log(n))
     */
    template <typename T>
    std::vector<T> convolution(std::vector<T> _a, std::vector<T> _b) {
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
        std::vector<T> _c;
        for (auto&& elem : c) {
            if constexpr (std::is_same<T, F>::value) {
                _c.emplace_back(elem);
            } else if constexpr (std::is_integral<T>::value) {
                _c.emplace_back(std::floor(elem.real() + 0.5));
            } else {
                _c.emplace_back((T)elem.real());
            }
        }
        return _c;
    }
}