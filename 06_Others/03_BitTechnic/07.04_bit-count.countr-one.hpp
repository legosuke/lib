#pragma once
#include "07.03_bit-count.countr-zero.hpp"

namespace __bit_count {
    /**
     * @brief ビットカウント (countr_one)
     */
    template<typename T>
    constexpr std::uint32_t countr_one(T x) noexcept {
        return countr_zero<T>((T)~x);
    }
}