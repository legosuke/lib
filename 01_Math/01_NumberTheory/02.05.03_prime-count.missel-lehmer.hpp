#pragma once
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <unordered_map>
#include <vector>
#include "03.01.01_sieve.eratosthenes.hpp"
#include "02.07_enumerate-primes.hpp"

/**
 * @brief $n$ 以下の素数の個数 (Meissel-Lehmer)
 */
namespace __prime_count {
    const std::uint32_t LIMIT = 20'000'000;
    const std::uint32_t A_LIMIT = 500;
    std::vector<std::uint32_t> primes = enumerate_primes<eratosthenes<LIMIT>>(LIMIT);
    std::unordered_map<std::uint64_t, std::uint64_t> pi_cache;
    std::unordered_map<std::uint64_t, std::uint64_t> psi_cache[A_LIMIT];

    std::uint64_t small_psi(std::uint64_t n, std::uint32_t a) {
        std::uint64_t res = 0;
        for (std::uint32_t bit = 0; bit < 1U << a; ++bit) {
            std::uint64_t mul = 1;
            for (std::uint32_t i = 0; i < a; ++i) {
                if (bit >> i & 1) mul *= primes[i];
            }
            if (__builtin_popcountll(bit) & 1) res -= n / mul;
            else res += n / mul;
        }
        return res;
    }

    /**
     * @brief {p1,p1,...,pa} のいずれも素因数にもたない数の個数
     */
    std::uint64_t psi(std::uint64_t n, std::uint32_t a) {
        if (psi_cache[a].find(n) != psi_cache[a].end()) return psi_cache[a][n];
        if (a <= 7) return psi_cache[a][n] = small_psi(n, a);
        return psi_cache[a][n] = psi(n, a - 1) - psi(n / primes[a - 1], a - 1);
    }
}

std::uint64_t prime_count(std::uint64_t n) {
    using namespace __prime_count;
    if (pi_cache.find(n) != pi_cache.end()) return pi_cache[n];
    if (n <= LIMIT) return pi_cache[n] = std::upper_bound(primes.begin(), primes.end(), n) - primes.begin();
    std::uint32_t a = prime_count(std::floor(std::sqrt(std::sqrt(n))));
    std::uint32_t b = prime_count(std::floor(std::sqrt(n)));
    std::uint32_t c = prime_count(std::floor(std::cbrt(n)));
    std::uint64_t res = psi(n, a) + (b - a + 1) * (b + a - 2) / 2;
    for (std::uint32_t i = a + 1; i <= b; ++i) {
        res -= prime_count(n / primes[i - 1]);
        if (i <= c) {
            std::uint32_t b_i = prime_count(std::floor(std::sqrt(n / primes[i - 1])));
            for (std::uint32_t j = i; j <= b_i; ++j) {
                res -= prime_count(n / (primes[i - 1] * primes[j - 1])) - (j - 1);
            }
        }
    }
    return pi_cache[n] = res;
}