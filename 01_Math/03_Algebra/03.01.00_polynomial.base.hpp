#pragma once
#include <type_traits>

/**
 * @brief 多項式 (base)
 */
class polynomial_base {};

template <class T>
using is_polynomial = std::is_base_of<polynomial_base, T>;