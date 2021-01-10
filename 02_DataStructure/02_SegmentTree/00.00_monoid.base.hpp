#pragma once
#include <type_traits>

class monoid_base {};

template <class T>
using is_monoid = std::is_base_of<monoid_base, T>;
