#pragma once
#include <cstdint>
#include <limits>
#include <type_traits>
#include "00.02.00_mapping.base.hpp"
#include "00.01.01_monoid.min.hpp"
#include "00.01.04_monoid.update.hpp"

/**
 * @brief 写像 (update-min)
 */
template <class T>
class update_min_mapping : public mapping_base {
    static_assert(std::is_arithmetic<T>::value);

public:
    using data_type = typename min_monoid<T>::value_type;
    using lazy_type = typename update_monoid<T>::value_type;
    data_type op(data_type x, lazy_type f, std::uint32_t length) {
        return f;
    }
};