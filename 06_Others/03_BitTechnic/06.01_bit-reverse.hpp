#pragma once
#include <cstdint>

/**
 * @brief ビット列の反転
 * @note O(log(n))
 */
std::uint32_t bit_reverse(std::uint32_t n, std::uint32_t len) {
    std::uint32_t res = 0;
    for (std::uint32_t i = 0; i < len; ++i) {
        res = (res << 1) | (n >> i & 1);
    }
    return res;
}