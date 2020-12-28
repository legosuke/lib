#pragma once
#include <type_traits>

/**
 * @brief 行列 (base)
 */
class matrix_base {};

template <class T>
using is_matrix = std::is_base_of<matrix_base, T>;