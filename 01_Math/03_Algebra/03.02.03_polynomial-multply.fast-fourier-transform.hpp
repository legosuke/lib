#pragma once
#include <cassert>
#include "03.01_polynomial.hpp"
#include "05.01_convolution.fast-fourier-transform.hpp"

/**
 * @brief 多項式の乗算 (高速フーリエ変換)
 * @note O(n⋅lg(n))
 */
template <typename T>
std::vector<T> operator * (std::vector<T> a, std::vector<T> b) {
    if constexpr (std::is_integral<T>::value) {
        return __fft::integral_convolution(a, b);
    } else if constexpr (std::is_floating_point<T>::value) {
        return __fft::real_convolution(a, b);
    } else {
        return __fft::convolution(a, b);
    }
}