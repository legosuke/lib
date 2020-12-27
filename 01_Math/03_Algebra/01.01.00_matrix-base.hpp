#pragma once
#include <type_traits>

/**
 * @brief 行列 (base)
 */
class MatrixBase {};

template <class T>
using is_matrix = std::is_base_of<MatrixBase, T>;