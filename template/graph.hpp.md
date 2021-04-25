---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: 03_Graph/01_TreeAlgorithm/01.00_tree-diameter.hpp
    title: 03_Graph/01_TreeAlgorithm/01.00_tree-diameter.hpp
  - icon: ':heavy_check_mark:'
    path: 03_Graph/01_TreeAlgorithm/01.01_tree-diameter-weight.hpp
    title: 03_Graph/01_TreeAlgorithm/01.01_tree-diameter-weight.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/03_Graph/01_TreeAlgorithm/01_AOJ-GRL.test.cpp
    title: test/03_Graph/01_TreeAlgorithm/01_AOJ-GRL.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/graph.hpp\"\n#include <cstdint>\n#include <vector>\n\
    \ntemplate <typename T = std::uint32_t>\nstruct Edge {\n    std::uint32_t from,\
    \ to;\n    T weight;\n    Edge(std::uint32_t f, std::uint32_t t, T w) : from(f),\
    \ to(t), weight(w) {}\n    using weight_type = T;\n};\n\nstruct UnweightedEdge\
    \ : Edge<> {\n    explicit UnweightedEdge(std::uint32_t t) : Edge<>(-1, t, 1)\
    \ {}\n    explicit UnweightedEdge(std::uint32_t f, std::uint32_t t) : Edge<>(f,\
    \ t, 1) {}\n};\nusing UnweightedEdges = std::vector<UnweightedEdge>;\nusing UnweightedGraph\
    \ = std::vector<UnweightedEdges>;\n\ntemplate <typename T = std::uint32_t>\nstruct\
    \ WeightedEdge : Edge<T> {\n    explicit WeightedEdge(std::uint32_t t, T w) :\
    \ Edge<T>(-1, t, w) {}\n    explicit WeightedEdge(std::uint32_t f, std::uint32_t\
    \ t, T w) : Edge<T>(f, t, w) {}\n};\ntemplate <typename T = std::uint32_t> using\
    \ WeightedEdges = std::vector<WeightedEdge<T>>;\ntemplate <typename T = std::uint32_t>\
    \ using WeightedGraph = std::vector<WeightedEdges<T>>;\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\n\ntemplate <typename\
    \ T = std::uint32_t>\nstruct Edge {\n    std::uint32_t from, to;\n    T weight;\n\
    \    Edge(std::uint32_t f, std::uint32_t t, T w) : from(f), to(t), weight(w) {}\n\
    \    using weight_type = T;\n};\n\nstruct UnweightedEdge : Edge<> {\n    explicit\
    \ UnweightedEdge(std::uint32_t t) : Edge<>(-1, t, 1) {}\n    explicit UnweightedEdge(std::uint32_t\
    \ f, std::uint32_t t) : Edge<>(f, t, 1) {}\n};\nusing UnweightedEdges = std::vector<UnweightedEdge>;\n\
    using UnweightedGraph = std::vector<UnweightedEdges>;\n\ntemplate <typename T\
    \ = std::uint32_t>\nstruct WeightedEdge : Edge<T> {\n    explicit WeightedEdge(std::uint32_t\
    \ t, T w) : Edge<T>(-1, t, w) {}\n    explicit WeightedEdge(std::uint32_t f, std::uint32_t\
    \ t, T w) : Edge<T>(f, t, w) {}\n};\ntemplate <typename T = std::uint32_t> using\
    \ WeightedEdges = std::vector<WeightedEdge<T>>;\ntemplate <typename T = std::uint32_t>\
    \ using WeightedGraph = std::vector<WeightedEdges<T>>;"
  dependsOn: []
  isVerificationFile: false
  path: template/graph.hpp
  requiredBy:
  - 03_Graph/01_TreeAlgorithm/01.00_tree-diameter.hpp
  - 03_Graph/01_TreeAlgorithm/01.01_tree-diameter-weight.hpp
  timestamp: '2021-04-25 12:31:21+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/03_Graph/01_TreeAlgorithm/01_AOJ-GRL.test.cpp
documentation_of: template/graph.hpp
layout: document
redirect_from:
- /library/template/graph.hpp
- /library/template/graph.hpp.html
title: template/graph.hpp
---
