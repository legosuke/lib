#pragma once
#include <cassert>
#include <chrono>
#include <random>
#include <type_traits>

struct Random {
    std::mt19937_64 mt;
    Random() { mt.seed(std::chrono::steady_clock::now().time_since_epoch().count()); }
} rnd;

/**
 * @brief 乱数 (数)
 * @note O(1)
 */
template <typename T>
T random_number(const T a, const T b) {
    assert(a < b);
    if (std::is_integral<T>::value) {
        std::uniform_int_distribution<T> dist(a, b - 1);
        return dist(rnd.mt);
    } else {
        std::uniform_real_distribution<> dist(a, b);
        return dist(rnd.mt);
    }
}

/**
 * @note O(1)
 */
template <typename T>
T random_number(const T b) {
    return random_number(T(0), b);
}