#pragma once
#include <cstdint>
#include <random>
#include <vector>
#include "01.02.01_gcd.hpp"
#include "02.01.03_is-prime.miller-rabin.hpp"

/**
 * @brief 素因数分解 (ロー法)
 */
namespace rho {
    std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());

    inline std::int64_t f(__int128_t x, std::int64_t c, std::int64_t n) {
        return (x * x % n + c) % n;
    }

    std::int64_t rho(std::int64_t n) {
        if (!(n & 1)) return 2;
        std::int64_t c = mt() % n, x = mt() % n, y = x, d = 1;
        while (d == 1) {
            x = f(x, c, n);
            y = f(f(y, c, n), c, n);
            d = gcd(std::abs(x - y), n);
        }
        if (d == n) return -1;
        return d;
    }
}

std::vector<std::pair<std::uint64_t, std::uint32_t>> prime_factor(std::uint64_t n) {
    if (n <= 1) return {};
    if (is_prime(n)) return {std::pair<std::uint64_t, std::uint32_t>(n, 1)};
    std::uint64_t p = -1, num = 0;
    while (!~p || !is_prime(p)) p = rho::rho(n);
    while (n % p == 0) {
        num++;
        n /= p;
    }
    std::vector<std::pair<std::uint64_t, std::uint32_t>> pf = prime_factor(n);
    pf.emplace_back(p, num);
    return pf;
}