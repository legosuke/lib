#pragma once
#include "07.01_bit-count.countl-zero.hpp"

namespace __bit_pow2 {
    /**
     * @brief $2$ の累乗整数 (bit_width)
     */
    template <typename T>
    constexpr std::uint32_t bit_width(T x) noexcept {
        return std::numeric_limits<T>::digits - __bit_count::countl_zero(x);
    }
}