#pragma once
#include <cstdint>

std::int64_t mod_pow(std::int64_t a, std::int64_t n, std::int32_t MOD) {
    a = (a % MOD + MOD) % MOD;
    std::int64_t res = 1;
    while (n) {
        if (n & 1) (res *= a) %= MOD;
        (a *= a) %= MOD;
        n >>= 1;
    }
    return res;
}