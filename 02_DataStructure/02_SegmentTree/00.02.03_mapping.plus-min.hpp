#pragma once
#include <cstdint>
#include "00.02.00_mapping.base.hpp"
#include "00.01.01_monoid.min.hpp"
#include "00.01.03_monoid.plus.hpp"

/**
 * @brief 写像 (plus-min)
 */
template <class T>
class plus_min_mapping : public mapping_base {
public:
    using data_type = typename min_monoid<T>::value_type;
    using lazy_type = typename plus_monoid<T>::value_type;
    static data_type op(data_type x, lazy_type f, std::uint32_t length) {
        return x + f;
    }
};