#pragma once
#include <cstdint>
#include <vector>

template <typename T = std::uint32_t>
struct edge {
    std::uint32_t from, to;
    T weight;
    edge(std::uint32_t f, std::uint32_t t, T w) : from(f), to(t), weight(w) {}
    using weight_type = T;
};

struct unweighted_edge : edge<> {
    explicit unweighted_edge(std::uint32_t t) : edge<>(-1, t, 1) {}
    explicit unweighted_edge(std::uint32_t f, std::uint32_t t) : edge<>(f, t, 1) {}
};
using unweighted_edges = std::vector<unweighted_edge>;
using unweighted_graph = std::vector<unweighted_edges>;

template <typename T = std::uint32_t>
struct weighted_edge : edge<T> {
    explicit weighted_edge(std::uint32_t t, T w) : edge<T>(-1, t, w) {}
    explicit weighted_edge(std::uint32_t f, std::uint32_t t, T w) : edge<T>(f, t, w) {}
};
template <typename T = std::uint32_t> using weighted_edges = std::vector<weighted_edge<T>>;
template <typename T = std::uint32_t> using weighted_graph = std::vector<weighted_edges<T>>;