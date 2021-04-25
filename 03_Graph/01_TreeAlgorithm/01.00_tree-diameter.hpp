#pragma once
#include "../../template/graph.hpp"

namespace __tree_diameter {
    std::vector<std::uint32_t> prev_node;

    template <class Graph>
    std::pair<std::uint32_t, typename Graph::value_type::value_type::weight_type> dfs(const Graph& g, std::uint32_t v, std::uint32_t pv) {
        std::pair<std::uint32_t, typename Graph::value_type::value_type::weight_type> res(v, 0);
        for (auto e : g[v]) if (e.to != pv) {
            auto tmp = dfs(g, e.to, v);
            tmp.second += e.weight;
            if (tmp.second > res.second) {
                res = tmp;
                prev_node[e.to] = v;
            }
        }
        return res;
    }
}