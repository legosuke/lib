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
        for (std::uint32_t i = 0; i + 1 < data.size(); ++i) {
            data[i + 1] += data[i];
        }
    }

    const T& operator [] (std::uint32_t i) const {
        return (data.at(i));
    }

    /**
     * @note add val to [x1, x2)
     */
    void add(std::uint32_t x1, std::uint32_t x2, const T& val) {
        data[x1] += val;
        data[x2] -= val;
    }

private:
    std::vector<T> data;
};