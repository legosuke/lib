#pragma once
#include "07.05_bit-count.popcount.hpp"

namespace __bit_pow2 {
    /**
     * @brief $2$ の累乗整数 (has_single_bit)
     */
    template<typename T>
    constexpr bool has_single_bit(T x) noexcept {
        return __bit_count::popcount(x) == 1;
    }
}