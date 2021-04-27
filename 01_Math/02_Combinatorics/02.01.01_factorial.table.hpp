#pragma once
#include <vector>
#include "01.01_mod-operation.hpp"

/**
 * @brief 階乗 (テーブル)
 * @note O(n)
 */
template <typename Integer>
std::vector<Integer> factorial_table(std::uint32_t n) {
    std::vector<Integer> res(n + 1);
    res[0] = 1;
    for (std::uint32_t i = 1; i <= n; ++i) {
        res[i] = res[i - 1] * i;
    }
    return res;
}