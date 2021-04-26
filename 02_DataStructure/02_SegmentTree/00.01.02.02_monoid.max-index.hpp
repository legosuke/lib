#pragma once
#include <algorithm>
#include <limits>
#include "00.00_monoid.base.hpp"

/**
 * @brief モノイド (max-index)
 */
template <typename T>
class max_index_monoid : public monoid_base {
    static_assert(std::is_arithmetic<T>::value);

public:
    using value_type = std::pair<T, std::uint32_t>;
    const value_type op(value_type lhs, value_type rhs) const { return std::max(lhs, rhs); }
    const value_type e() const { return value_type(std::numeric_limits<T>::min(), 0); }
};