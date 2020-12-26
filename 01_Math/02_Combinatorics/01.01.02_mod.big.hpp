#pragma once
#include <cstdint>
#include "01.01.01_mod.hpp"

/**
 * @note 大きな mod 上の計算
 */
inline std::uint64_t mul(std::int64_t a, std::int64_t b, std::uint64_t m) {
    __uint128_t am = mod(a, m), bm = mod(b, m);
    return std::uint64_t(am * bm % m);
}