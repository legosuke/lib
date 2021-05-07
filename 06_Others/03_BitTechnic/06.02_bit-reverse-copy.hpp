#pragma once
#include <vector>

/**
 * @brief ビット反転置換
 * @note O(n⋅log(n))
 */
template <typename T>
std::vector<T> bit_reverse_copy(std::vector<T> a) {
    std::uint32_t n = a.size();
    for (std::uint32_t i = 0, j = 1; j < n - 1; ++j) {
        for (std::uint32_t k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) std::swap(a[i], a[j]);
    }
    return a;
}