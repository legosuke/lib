#pragma once
#include "01_random-number.hpp"
#include <cassert>
#include <numeric>
#include <utility>
#include <vector>

template <typename T>
std::vector<T> random_vector_number(const std::size_t n, const T a, const T b) {
    std::vector<T> res(n);
    for (std::size_t i = 0; i < n; ++i) {
        res[i] = random_number(a, b);
    }
    return res;
}

template <typename T>
void random_shuffle(std::vector<T>& v) {
    const std::size_t n = v.size();
    for (int i = n - 1; i > 0; --i) {
        std::swap(v[i], v[random_number(i + 1)]);
    }
}

std::vector<std::uint32_t> random_permutation(const std::uint32_t n) {
    std::vector<std::uint32_t> res(n);
    std::iota(res.begin(), res.end(), 1);
    random_shuffle(res);
    return res;
}