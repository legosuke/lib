#pragma once
#include <type_traits>

class mapping_base {};

template <class T>
using is_mapping = std::is_base_of<mapping_base, T>;
