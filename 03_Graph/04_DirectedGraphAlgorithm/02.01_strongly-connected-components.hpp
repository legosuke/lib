#pragma once
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
        if (~cmp[v]) return;
        cmp[v] = sz;
        for (auto&& e : rg[v]) {
            rdfs(e.to);
        }
    }

public:
    stolongly_connected_components(std::uint32_t n)
        : sz(0), g(n), gg(n), rg(n), cmp(n, -1), used(n, false) {}

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
            if (!~cmp[i]) {
                rdfs(i);
                ++sz;
            }
        }
        dag.resize(sz);
        for (std::uint32_t i = 0; i < n; ++i) {
            for (auto&& e : g[i]) {
                std::uint32_t x = cmp[i], y = cmp[e.to];
                if (x == y) continue;
                dag[x].emplace_back(y);
            }
        }
    }

    /**
     * @brief 要素 k が属する連結成分の番号
     * @note O(1)
     */
    std::uint32_t component(std::uint32_t k) {
        return cmp[k];
    }

    /**
     * @brief 要素 x と要素 y が同じ連結成分に属するか判定
     * @note O(1)
     */
    bool same(std::uint32_t x, std::uint32_t y) {
        return cmp[x] == cmp[y];
    }

    /**
     * @brief 連結成分の個数
     * @note O(1)
     */
    std::uint32_t size() {
        return sz;
    }

    /**
     * @brief 連結成分のグラフ
     * @note O(1)
     */
    unweighted_graph component_graph() {
        return dag;
    }

private:
    std::uint32_t sz;
    unweighted_graph g, gg, rg, dag;
    std::vector<std::uint32_t> cmp, ord;
    std::vector<bool> used;
};