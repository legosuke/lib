#pragma once
#include <cstdint>

/**
 * @brief 素数判定 (素朴な手法)
 * @note O(\sqrt{n})
 */
bool is_prime(std::uint64_t n) {
    for (std::uint64_t i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}