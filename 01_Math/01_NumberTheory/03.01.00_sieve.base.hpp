#pragma once
#include <type_traits>

/**
 * @brief 篩 (base)
 */
class sieve_base {};

template <class T>
using is_sieve = std::is_base_of<sieve_base, T>;