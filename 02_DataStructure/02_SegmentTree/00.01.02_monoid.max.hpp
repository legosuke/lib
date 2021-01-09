#pragma once
#include <algorithm>
#include <limits>
#include <type_traits>
#include "00.00_monoid.base.hpp"

/**
 * @brief モノイド (max)
 */
template <typename T>
class max_monoid : public monoid_base {
    static_assert(std::is_arithmetic<T>::value);

public:
    using value_type = T;
    const T op(T lhs, T rhs) const { return std::max(lhs, rhs); }
    const T e() const { return std::numeric_limits<T>::min(); }
};