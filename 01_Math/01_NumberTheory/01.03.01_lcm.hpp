#pragma once
#include "01.02.01_gcd.hpp"

/**
 * @brief 最小公倍数
 * @note O(\min\log(a,b))
 */
std::uint64_t lcm(std::uint64_t a, std::uint64_t b) {
    return a / gcd(a, b) * b;
}