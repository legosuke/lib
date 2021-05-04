#pragma once
#include "00.01.01.01_monoid.min.hpp"
#include "01.00_segment-tree.hpp"

/**
 * @brief セグメント木 (Range Minimum Query)
 */
template <typename T>
using range_minimum_query = segment_tree<min_monoid<T>>;