#pragma once
#include <cassert>
#include <limits>
#include <queue>
#include <type_traits>
#include "../../template/graph.hpp"

/**
 * @brief 単一始点最短経路 (Dijkstra)
 */
template <typename T>
class dijkstra {
public:
    dijkstra(std::uint32_t n) : g(n) {}

    const weighted_edges<T>& operator [] (std::uint32_t i) const {
        return (g.at(i));
    }
    weighted_edges<T>& operator [] (std::uint32_t i) {
        return (g.at(i));
    }

    /**
     * @note O((|V| + |E|)⋅log(|V|))
     */
    void build(std::uint32_t s) {
        using P = std::pair<T, std::uint32_t>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> que;
        dist.assign(g.size(), INF);
        prev.assign(g.size(), -1);
        que.emplace(0, s);
        dist[s] = 0;
        while (!que.empty()) {
            auto p = que.top(); que.pop();
            if (dist[p.second] < p.first) continue;
            for (auto&& e : g[p.second]) if (dist[e.to] > dist[p.second] + e.weight) {
                dist[e.to] = dist[p.second] + e.weight;
                prev[e.to] = p.second;
                que.emplace(dist[e.to], e.to);
            }
        }
    }

    bool reach(std::uint32_t t) {
        return dist[t] < INF;
    }

    T distance(std::uint32_t t) {
        return dist[t];
    }

    std::vector<T> distance_list() {
        return dist;
    }

    /**
     * @note O(min(|V|, |E|))
     */
    std::vector<std::uint32_t> path(std::uint32_t t) {
        std::vector<std::uint32_t> res(t);
        while (prev[res.back()] != -1) {
            res.push_back(prev[res.back()]);
        }
        std::reverse(begin(res), end(res));
        return res;
    }

private:
    const T INF = std::numeric_limits<T>::max();
    weighted_graph<T> g;
    std::vector<T> dist;
    std::vector<std::uint32_t> prev;
};