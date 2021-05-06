#pragma once
#include "07.01_bit-count.countl-zero.hpp"

namespace __bit_count {
    /**
     * @brief ビットカウント (countl_one)
     */
    template<typename T>
    constexpr std::uint32_t countl_one(T x) noexcept {
        return countl_zero<T>((T)~x);
    }
}