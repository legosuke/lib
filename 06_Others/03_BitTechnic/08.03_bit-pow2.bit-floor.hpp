#pragma once
#include "08.04_bit-pow2.bit-width.hpp"

namespace __bit_pow2 {
    /**
     * @brief $2$ の累乗整数 (bit_floor)
     */
    template<typename T>
    constexpr T bit_floor(T x) noexcept {
        return (T)(x == 0 ? 0 : (T)1 << (bit_width(x) - 1));
    }
}