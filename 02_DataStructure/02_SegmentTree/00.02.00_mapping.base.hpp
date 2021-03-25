#pragma once
#include <type_traits>

/**
 * @brief 写像 (base)
 */
class mapping_base {};

template <class T>
using is_mapping = std::is_base_of<mapping_base, T>;
