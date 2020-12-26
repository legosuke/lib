#pragma once
#include <cstdint>

/**
 * @brief mod 上の基本演算
 */
template <typename T, typename M>
inline M mod(T a, M m) {
    return (a % m + m) % m;
}

template <typename T, typename U, typename M>
inline M add(T a, U b, M m) {
    return mod(mod(a) + mod(b));
}

template <typename T, typename U, typename M>
inline M sub(T a, U b, M m) {
    return mod(mod(a) - mod(b));
}

template <typename T, typename U, typename M>
inline M mul(T a, U b, M m) {
    return mod((__uint128_t)a * b, m);
}