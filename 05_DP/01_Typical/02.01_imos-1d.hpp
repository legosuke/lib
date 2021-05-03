#pragma once
#include <cstdint>
#include <vector>

/**
 * @brief いもす法 (1D)
 */
template <typename T>
class imos_1d {
public:
    /**
     * @note field is [0, N)
     */
    imos_1d(std::uint32_t N) : data(N + 1, 0) {}

    void build() {
        for (std::uint32_t i = 0; i < data.size(); ++i) {
            data[i + 1] += data[i];
        }
    }

    const T& operator [] (std::uint32_t i) const {
        return (data.at(i));
    }
    T& operator [] (std::uint32_t i) {
        return (data.at(i));
    }

    /**
     * @note add x to [l,r)
     */
    void add(std::uint32_t l, std::uint32_t r, const T& x) {
        data[l] += x;
        data[r] -= x;
    }

private:
    std::vector<T> data;
};