#pragma once
#include <cstdint>
#include <vector>

namespace __kitamasa {
    template <typename T>
    std::vector<T> dfs(std::vector<T> c_k, std::uint64_t n) {
        std::uint32_t k = c_k.size();
        if (n == k) return c_k;
        std::vector<T> res(k);
        if ((n & 1) || n < k * 2) {
            std::vector<T> c_n = dfs(c_k, n - 1);
            res[0] = c_n[k - 1] * c_k[0];
            for (std::uint32_t i = 1; i < k; ++i) {
                res[i] = c_n[i - 1] + c_n[k - 1] * c_k[i];
            }
        } else {
            std::vector<std::vector<T>> C(k, std::vector<T>(k));
            C[0] = dfs(c_k, n >> 1);
            for (std::uint32_t i = 0; i + 1 < k; ++i) {
                C[i + 1][0] = C[i][k - 1] * c_k[0];
                for (std::uint32_t j = 0; j + 1 < k; ++j) {
                    C[i + 1][j + 1] = C[i][j] + C[i][k - 1] * c_k[j + 1];
                }
            }
            for (std::uint32_t i = 0; i < k; ++i) {
                for (std::uint32_t j = 0; j < k; ++j) {
                    res[i] = res[i] + C[0][j] * C[j][i];
                }
            }
        }
        return res;
    }
}

/**
 * @brief Kitamasa 法
 * @note n is 0-indexed
 */
template <typename T>
T kitamasa(std::vector<T> a, std::vector<T> c, std::uint64_t n) {
    if (n < a.size()) return a[n];
    auto C = __kitamasa::dfs(c, n);
    T res = 0;
    for (std::uint32_t i = 0; i < a.size(); ++i) {
        res = res + C[i] * a[i];
    }
    return res;
}