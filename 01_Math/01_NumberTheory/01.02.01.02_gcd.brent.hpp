#pragma once
#include <cstdint>
#include <utility>

/**
 * @brief 最大公約数 (Brent)
 * @note O(min(log(a),log(b)))
 */
std::uint64_t gcd(std::uint64_t a, std::uint64_t b) {
    std::uint32_t c = 0;
    while (!(a & 1) && !(b & 1)) {
        a >>= 1; b >>= 1;
        ++c;
    }
    while (a - b) {
        while (!(a & 1)) a >>= 1;
        while (!(b & 1)) b >>= 1;
        if (a < b) std::swap(a, b);
        std::uint64_t d = a - b;
        while (!(d & 1)) d >>= 1;
        a = b; b = d;
    }
    return a * ((std::uint64_t)1 << c);
}