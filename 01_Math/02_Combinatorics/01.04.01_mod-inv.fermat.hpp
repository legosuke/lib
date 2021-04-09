#pragma once
#include <cstdint>
#include "01.03.01_mod-pow.hpp"

/**
 * @brief 逆元 : $a^{-1}\bmod{p}$ (フェルマーの小定理)
 * @note O(log(p))
 * @warning p は素数
 */
std::uint32_t mod_inv(std::int64_t a, std::uint32_t p) {
    return mod_pow(a, p - 2, p);
}