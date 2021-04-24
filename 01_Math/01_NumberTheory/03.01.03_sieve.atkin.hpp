#pragma once
#include <cmath>
#include <cstdint>
#include <vector>

/**
 * @brief 篩 (アトキン)
 * @note O(n/log(log(n)))
 */
std::vector<bool> sieve(std::uint32_t n) {
    std::vector<bool> is_prime(n, false);
    std::uint32_t sqrt_n = std::uint32_t(sqrt(n)), m;
    for (std::uint32_t z = 1; z <= 5; z += 4) {
        for (std::uint32_t y = z; y <= sqrt_n; y += 6) {
            for (std::uint32_t x = 1; x <= sqrt_n && (m = 4 * x * x + y * y) < n; ++x) {
                is_prime[m] = !is_prime[m];
            }
            for (std::uint32_t x = y + 1; x <= sqrt_n && (m = 3 * x * x - y * y) < n; x += 2) {
                is_prime[m] = !is_prime[m];
            }
        }
    }
    for (std::uint32_t z = 2; z <= 4; z += 2) {
        for (std::uint32_t y = z; y <= sqrt_n; y += 6) {
            for (std::uint32_t x = 1; x <= sqrt_n && (m = 3 * x * x + y * y) < n; x += 2) {
                is_prime[m] = !is_prime[m];
            }
            for (std::uint32_t x = y + 1; x <= sqrt_n && (m = 3 * x * x - y * y) < n; x += 2) {
                is_prime[m] = !is_prime[m];
            }
        }
    }
    for (std::uint32_t y = 3; y <= sqrt_n; y += 6) {
        for (std::uint32_t z = 1; z <= 2; ++z) {
            for (std::uint32_t x = z; x <= sqrt_n && (m = 4 * x * x + y * y) < n; x += 3) {
                is_prime[m] = !is_prime[m];
            }
        }
    }
    for (std::uint32_t i = 5; i < sqrt_n; ++i) {
        if (!is_prime[i]) continue;
        for (std::uint32_t i2 = i * i, j = i2; j < n; j += i2) {
            is_prime[j] = false;
        }
    }
    is_prime[2] = is_prime[3] = true;
    return is_prime;
}