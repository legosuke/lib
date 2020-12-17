#pragma once
#include <cstring>
#include "01_random-number.hpp"

/**
 * @brief 乱数 (文字列)
 * @note O(n)
 */
std::string random_string_by_charset(const std::size_t n, const std::string cs) {
    const auto sz = cs.size();
    std::string res;
    for (std::size_t i = 0; i < n; ++i) {
        res += cs[random_number(sz)];
    }
    return res;
}

/**
 * @note O(n)
 */
std::string random_string(const std::size_t n) {
    const std::string cs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return random_string_by_charset(n, cs);
}

/**
 * @note O(n)
 */
std::string random_upper_string(const std::size_t n) {
    const std::string cs = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return random_string_by_charset(n, cs);
}

/**
 * @note O(n)
 */
std::string random_lower_string(const std::size_t n) {
    const std::string cs = "abcdefghijklmnopqrstuvwxyz";
    return random_string_by_charset(n, cs);
}

/**
 * @note O(n)
 */
std::string random_digit(const std::size_t n) {
    const std::string cs = "012345689";
    return random_string_by_charset(n, cs);
}