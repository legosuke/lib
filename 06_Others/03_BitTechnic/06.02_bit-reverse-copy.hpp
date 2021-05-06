#pragma once
#include <bit>
#include <vector>
#include "06.01_bit-reverse.hpp"
#include "08.04_bit-pow2.bit-width.hpp"

/**
 * @brief ビット反転置換
 * @note O(n⋅log(n))
 */
template <typename T>
std::vector<T> bit_reverse_copy(std::vector<T> a) {
    std::uint32_t n = a.size();
    std::vector<T> A(n);
    std::uint32_t len = __bit_pow2::bit_width(n - 1);
    for (std::uint32_t k = 0; k < n; ++k) {
        A[bit_reverse(k, len)] = a[k];
    }
    return A;
}