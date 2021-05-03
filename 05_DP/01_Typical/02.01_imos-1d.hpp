#pragma once
#include <cstdint>
#include <vector>

namespace __imos_1d {
    template <typename T>
    using interval = std::pair<T, T>;
}

/**
 * @brief いもす法 (1D)
 * @note O(N)
 */
template <typename T>
std::vector<T> imos_1d(const std::uint32_t N, const std::vector<__imos_1d::interval<T>>& intervals) {
    std::vector<T> res(N + 1, 0);
    for (auto&& c : intervals) {
        res[c.first]++;
        res[c.second]--;
    }
    for (std::uint32_t i = 0; i < N; ++i) {
        res[i + 1] += res[i];
    }
    return res;
}