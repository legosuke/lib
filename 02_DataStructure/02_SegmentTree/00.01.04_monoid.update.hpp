#pragma once
#include <limits>
#include "00.00_monoid.base.hpp"

/**
 * @brief モノイド (update)
 */
template <typename T>
class update_monoid : public monoid_base {
    static_assert(std::is_arithmetic<T>::value);

public:
    using value_type = T;
    const T op(T lhs, T rhs) const { return rhs; }
    const T e() const { return T(std::numeric_limits<T>::max()); }
};