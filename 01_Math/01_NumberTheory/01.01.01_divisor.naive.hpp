#pragma once
#include <algorithm>
#include <cstdint>
#include <vector>

/**
 * @brief 約数列挙 (素朴な手法 $O(\sqrt{n})$)
 */
std::vector<std::uint64_t> divisor(std::uint64_t n) {
    std::vector<std::uint64_t> res;
    for (std::uint64_t i = 1; i * i <= n; i++) if (n % i == 0) {
        res.push_back(i);
        if (i * i != n) res.push_back(n / i);
    }
    std::sort(res.begin(), res.end());
    return res;
}