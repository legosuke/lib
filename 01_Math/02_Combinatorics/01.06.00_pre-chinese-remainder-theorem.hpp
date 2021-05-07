#pragma once
#include <cstdint>
#include <vector>
#include "../01_NumberTheory/01.02.01.01_gcd.hpp"

/**
 * @brief 中国剰余定理の前処理
 * @note O()
 */
template <typename Integer>
bool pre_chinese_remainder_theorem(std::vector<Integer>& r, std::vector<Integer>& m) {
    for (std::uint32_t i = 0; i < r.size(); ++i) {
        for (std::uint32_t j = 0; j < i; ++j) {
            auto g = gcd(m[i], m[j]);
            if ((r[i] - r[j]) % g != 0) return false;
            m[i] /= g, m[j] /= g;
            auto gi = gcd(m[i], g), gj = g / gi;
            do {
                g = gcd(gi, gj);
                gi *= g, gj /= g;
            } while (g != 1);
            m[i] *= gi, m[j] *= gj;
            r[i] %= m[i], r[j] %= m[j];
        }
    }
    return true;
}