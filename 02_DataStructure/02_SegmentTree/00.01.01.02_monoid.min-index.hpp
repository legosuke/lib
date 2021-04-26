#pragma once
#include <algorithm>
#include <limits>
#include "00.00_monoid.base.hpp"

/**
 * @brief モノイド (min-index)
 */
template <typename T>
class min_index_monoid : public monoid_base {
    static_assert(std::is_arithmetic<T>::value);

public:
    using value_type = std::pair<T, std::uint32_t>;
    const value_type op(value_type lhs, value_type rhs) const { return std::min(lhs, rhs); }
    const value_type e() const { return value_type(std::numeric_limits<T>::max(), -1); }
};