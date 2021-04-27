#pragma once
#include <cstdint>
#include <vector>

/**
 * @brief Binary Indexed Tree (1D)
 */
template <class Abel>
class binary_indexed_tree_1d {
public:
    binary_indexed_tree_1d(std::uint32_t n) : data(n, 0) {}

    /**
     * @brief data[p] に x を追加
     * @note O(log(p))
     */
    void add(std::uint32_t p, const Abel& x) {
        for (std::uint32_t i = p; i < data.size(); i |= i + 1) {
            data[i] = data[i] + x;
        }
    }

    /**
     * @brief ∀i ∈ [0,p) に対する data[i] の総和
     * @note O(log(p))
     */
    Abel sum(std::uint32_t p) {
        Abel res = 0;
        for (std::uint32_t i = p - 1; ~i; i = (i & (i + 1)) - 1) {
            res = res + data[i];
        }
        return res;
    }

    /**
     * @brief ∀i ∈ [l,r) に対する data[i] の総和
     * @note O(log(r))
     */
    Abel sum(std::uint32_t l, std::uint32_t r) {
        return sum(r) - sum(l);
    }

private:
    std::vector<Abel> data;
};