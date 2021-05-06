#pragma once
#include "08.04_bit-pow2.bit-width.hpp"

namespace __bit_pow2 {
    /**
     * @brief $2$ の累乗整数 (bit_ceil)
     */
    template<typename T>
    constexpr T bit_ceil(T x) noexcept {
        return (T)(x <= 1 ? 1 : (T)1 << bit_width((T)(x - 1)));
    }
}