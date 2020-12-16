#pragma once
#include <cstdint>

/**
 * @brief 最大公約数
 * @note O(\min\log(a,b))
 */
std::uint64_t gcd(std::uint64_t a, std::uint64_t b) {
    while (b) {
        std::uint64_t c = a % b;
        a = b;
        b = c;
    }
    return a;
}