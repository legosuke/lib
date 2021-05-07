#pragma once
#include <cassert>
#include "03.01.01_polynomial.real.hpp"
#include "../../06_Others/03_BitTechnic/08.02_bit-pow2.bit-ceil.hpp"

/**
 * @brief 多項式の乗算 (カラツバ法)
 * @note O(n^lg(3))
 */
template <typename T>
polynomial_real<T> operator * (polynomial_real<T> a, polynomial_real<T> b) {
    std::uint32_t n = __bit_pow2::bit_ceil(std::max(a.size(), b.size()));
    if (n == 1) return polynomial_real<T>(std::vector<T>{a[0] * b[0]});
    a.resize(n); b.resize(n);
    std::vector<polynomial_real<T>> aa(2, polynomial_real<T>(n >> 1)), bb(2, polynomial_real<T>(n >> 1));
    for (std::uint32_t i = 0; i < n; ++i) {
        aa[i & 1][i >> 1] = a[i];
        bb[i & 1][i >> 1] = b[i];
    }
    auto P = aa[1] * bb[1];
    auto Q = (aa[0] + aa[1]) * (bb[0] + bb[1]);
    auto R = aa[0] * bb[0];
    Q = Q - P - R;
    polynomial_real<T> res(2 * n - 1);
    for (std::uint32_t i = 0; i < P.size(); ++i) {
        res[2 * i + 2] += P[i];
    }
    for (std::uint32_t i = 0; i < Q.size(); ++i) {
        res[2 * i + 1] += Q[i];
    }
    for (std::uint32_t i = 0; i < R.size(); ++i) {
        res[2 * i] += R[i];
    }
    return res;
}