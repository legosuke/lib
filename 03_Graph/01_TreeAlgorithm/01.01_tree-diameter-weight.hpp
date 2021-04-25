#pragma once
#include "01.00_tree-diameter.hpp"

/**
 * @brief 木の直径 (重み)
 * @note O(n)
 */
template <class Graph>
typename Graph::value_type::value_type::weight_type tree_diameter_weight(const Graph& g) {
    using namespace __tree_diameter;
    using T = typename Graph::value_type::value_type::weight_type;
    prev_node.assign(g.size(), -1);
    std::pair<std::uint32_t, T> leaf1 = dfs(g, 0, -1);
    prev_node.assign(g.size(), -1);
    std::pair<std::uint32_t, T> leaf2 = dfs(g, leaf1.first, -1);
    return leaf2.second;
}