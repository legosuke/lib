#pragma once
#include <cstdint>
#include <vector>

/**
 * @brief いもす法 (2D)
 */
template <typename T>
class imos_2d {
public:
    /**
     * @note field is [0, N) × [0, M)
     */
    imos_2d(std::uint32_t N, std::uint32_t M) : N(N), M(M), data(N + 1, std::vector<T>(M + 1, 0)) {}

    void build() {
        for (std::uint32_t i = 0; i < N; ++i) {
            for (std::uint32_t j = 0; j < M; ++j) {
                data[i][j + 1] += data[i][j];
            }
        }
        for (std::uint32_t j = 0; j < M; ++j) {
            for (std::uint32_t i = 0; i < N; ++i) {
                data[i + 1][j] += data[i][j];
            }
        }
    }

    const std::vector<T>& operator [] (std::uint32_t i) const {
        return (data.at(i));
    }

    /**
     * @note add val to [y1, y2) × [x1, x2)
     */
    void add(std::uint32_t y1, std::uint32_t x1, std::uint32_t y2, std::uint32_t x2, const T& val) {
        data[y1][x1] += val;
        data[y1][x2] -= val;
        data[y2][x1] -= val;
        data[y2][x2] += val;
    }

private:
    const std::uint32_t N, M;
    std::vector<std::vector<T>> data;
};