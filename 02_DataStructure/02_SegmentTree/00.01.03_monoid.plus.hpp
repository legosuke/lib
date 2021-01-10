#pragma once
#include "00.00_monoid.base.hpp"

/**
 * @brief モノイド (plus)
 */
template <class T>
class plus_monoid : public monoid_base {
public:
    using value_type = T;
    const T op(T lhs, T rhs) const { return lhs + rhs; }
    const T e() const { return T(0); }
};