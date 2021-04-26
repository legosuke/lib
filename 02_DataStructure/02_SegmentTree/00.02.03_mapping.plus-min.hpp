#pragma once
#include <cstdint>
#include "00.02.00_mapping.base.hpp"
#include "00.01.01_monoid.min.hpp"
#include "00.01.03_monoid.plus.hpp"

/**
 * @brief 写像 (min-plus)
 */
template <class T>
class min_plus_mapping : public mapping_base {
    static_assert(std::is_arithmetic<T>::value);

public:
    using data_type = typename min_monoid<T>::value_type;
    using lazy_type = typename plus_monoid<T>::value_type;
    static data_type op(data_type x, lazy_type f, std::uint32_t length) {
        static_assert(std::is_convertible<lazy_type, data_type>::value);
        return x + f;
    }
};