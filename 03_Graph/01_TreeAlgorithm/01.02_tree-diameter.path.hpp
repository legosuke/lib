#pragma once
#include "01.00_tree-diameter.hpp"

/**
 * @brief 木の直径 (パス)
 * @note O(n)
 */
template <class Graph>
std::vector<std::uint32_t> tree_diameter_path(const Graph& g) {
    using namespace __tree_diameter;
    using T = typename Graph::value_type::value_type::weight_type;
    prev_node.assign(g.size(), -1);
    std::pair<std::uint32_t, T> leaf1 = dfs(g, 0, -1);
    prev_node.assign(g.size(), -1);
    std::pair<std::uint32_t, T> leaf2 = dfs(g, leaf1.first, -1);
    std::vector<std::uint32_t> res;
    std::uint32_t node = leaf2.first;
    while (node != -1) {
        res.emplace_back(node);
        node = prev_node[node];
    }
    return res;
}