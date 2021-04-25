#pragma once
#include <cstdint>
#include <vector>

template <typename T = std::uint32_t>
struct Edge {
    std::uint32_t from, to;
    T weight;
    Edge(std::uint32_t f, std::uint32_t t, T w) : from(f), to(t), weight(w) {}
    using weight_type = T;
};

struct UnweightedEdge : Edge<> {
    explicit UnweightedEdge(std::uint32_t t) : Edge<>(-1, t, 1) {}
    explicit UnweightedEdge(std::uint32_t f, std::uint32_t t) : Edge<>(f, t, 1) {}
};
using UnweightedEdges = std::vector<UnweightedEdge>;
using UnweightedGraph = std::vector<UnweightedEdges>;

template <typename T = std::uint32_t>
struct WeightedEdge : Edge<T> {
    explicit WeightedEdge(std::uint32_t t, T w) : Edge<T>(-1, t, w) {}
    explicit WeightedEdge(std::uint32_t f, std::uint32_t t, T w) : Edge<T>(f, t, w) {}
};
template <typename T = std::uint32_t> using WeightedEdges = std::vector<WeightedEdge<T>>;
template <typename T = std::uint32_t> using WeightedGraph = std::vector<WeightedEdges<T>>;