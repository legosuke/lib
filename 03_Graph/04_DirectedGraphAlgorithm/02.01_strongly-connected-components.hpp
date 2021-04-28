#pragma once
#include <cassert>
#include <algorithm>
#include <vector>
#include "../../template/graph.hpp"

/**
 * @brief 強連結成分分解
 */
class stolongly_connected_components {
private:
    void dfs(std::uint32_t v) {
        if (used[v]) return;
        used[v] = true;
        for (auto&& e : gg[v]) {
            dfs(e.to);
        }
        ord.emplace_back(v);
    }

    void rdfs(std::uint32_t v) {
        if (~cmp_id[v]) return;
        cmp_id[v] = sz;
        for (auto&& e : rg[v]) {
            rdfs(e.to);
        }
    }

public:
    stolongly_connected_components(std::uint32_t n)
        : sz(0), g(n), gg(n), rg(n), cmp_id(n, -1), used(n, false) {}

    const unweighted_edges& operator [] (std::uint32_t i) const {
        return (g.at(i));
    }
    unweighted_edges& operator [] (std::uint32_t i) {
        return (g.at(i));
    }

    /**
     * @brief 強連結成分を計算
     * @note O(|V|+|E|)
     */
    void build() {
        const std::uint32_t n = g.size();
        for (std::uint32_t i = 0; i < n; ++i) {
            for (auto&& e : g[i]) {
                gg[i].emplace_back(e.to);
                rg[e.to].emplace_back(i);
            }
        }
        for (std::uint32_t i = 0; i < n; ++i) {
            dfs(i);
        }
        std::reverse(begin(ord), end(ord));
        for (auto&& i : ord) {
            if (!~cmp_id[i]) {
                rdfs(i);
                ++sz;
            }
        }
        dag.resize(sz);
        cmps.resize(sz);
        for (std::uint32_t i = 0; i < n; ++i) {
            for (auto&& e : g[i]) {
                std::uint32_t x = cmp_id[i], y = cmp_id[e.to];
                if (x == y) continue;
                dag[x].emplace_back(y);
            }
            cmps[cmp_id[i]].emplace_back(i);
        }
    }

    std::vector<std::uint32_t> component(std::uint32_t k) {
        assert(0 <= k && k < cmps.size());
        return cmps[k];
    }
    std::uint32_t component_id(std::uint32_t k) {
        assert(0 <= k && k < cmp_id.size());
        return cmp_id[k];
    }
    bool is_same(std::uint32_t x, std::uint32_t y) {
        assert(0 <= x && x < cmp_id.size() && 0 <= y && y < cmp_id.size());
        return cmp_id[x] == cmp_id[y];
    }
    std::uint32_t number_of_components() {
        return sz;
    }
    unweighted_graph components_graph() {
        return dag;
    }

private:
    std::uint32_t sz;
    unweighted_graph g, gg, rg, dag;
    std::vector<std::uint32_t> cmp_id, ord;
    std::vector<std::vector<std::uint32_t>> cmps;
    std::vector<bool> used;
};