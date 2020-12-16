#pragma once
#include <cstdint>

inline std::int64_t mod(std::int64_t a, std::int64_t MOD) {
    return (a % MOD + MOD) % MOD;
}

inline std::int64_t mul(std::int64_t a, std::int64_t b, std::int64_t MOD) {
    a = mod(a, MOD), b = mod(b, MOD);
    std::int64_t res = 0;
    while (b) {
        if (b & 1) res = mod(res + a, MOD);
        a = mod(a + a, MOD);
        b >>= 1;
    }
    return res;
}