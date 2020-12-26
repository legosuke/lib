#pragma once
#include <cstdint>
#include <type_traits>

/**
 * @brief modint 構造体 (base)
 */
class modint_base {};

template <class T>
using is_modint = std::is_base_of<modint_base, T>;