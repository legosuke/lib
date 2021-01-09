#pragma once
#include <type_traits>

class monoid_base {};
class operator_monoid_base : public monoid_base {};

template <class T>
using is_monoid = std::is_base_of<monoid_base, T>;

template <class T>
using is_operator_monoid = std::is_base_of<operator_monoid_base, T>;