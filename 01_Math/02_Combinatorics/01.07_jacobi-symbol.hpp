#pragma once
#include <cstdint>
#include <utility>

/**
 * @brief ヤコビ記号
 * @note O(log(a))
 */
std::int32_t jacobi(std::uint64_t a, std::uint64_t m) {
    std::int32_t res = 1;
    a %= m;
    while (a > 1) {
        while (!(a & 1)) {
            a >>= 1;
            if (m % 8 == 3 || m % 8 == 5) res = -res;
        }
        if (a > 1) {
            if (a % 4 == 3 && m % 4 == 3) res = -res;
            std::swap(a, m);
            a %= m;
        }
    }
    return res * a;
}