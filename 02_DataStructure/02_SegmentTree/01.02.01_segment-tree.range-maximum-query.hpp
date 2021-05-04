#pragma once
#include "00.01.02.01_monoid.max.hpp"
#include "01.00_segment-tree.hpp"

/**
 * @brief セグメント木 (Range Maximum Query)
 */
template <typename T>
using range_maximum_query = segment_tree<max_monoid<T>>;