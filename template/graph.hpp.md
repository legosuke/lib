---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: 03_Graph/01_TreeAlgorithm/01.00_tree-diameter.hpp
    title: "\u6728\u306E\u76F4\u5F84"
  - icon: ':heavy_check_mark:'
    path: 03_Graph/01_TreeAlgorithm/01.01_tree-diameter-weight.hpp
    title: "\u6728\u306E\u76F4\u5F84 (\u91CD\u307F)"
  - icon: ':warning:'
    path: 03_Graph/01_TreeAlgorithm/01.02_tree-diameter.path.hpp
    title: "\u6728\u306E\u76F4\u5F84 (\u30D1\u30B9)"
  - icon: ':heavy_check_mark:'
    path: 03_Graph/02_GraphAlgorithm/01.01.03.01_single-source-shortest-path.weighted-graph.dijkstra.hpp
    title: "\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF (Dijkstra)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/03_Graph/01_TreeAlgorithm/01.01_AOJ-GRL-5-A.test.cpp
    title: test/03_Graph/01_TreeAlgorithm/01.01_AOJ-GRL-5-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/03_Graph/02_GraphAlgorithm/01.01.03.01_AOJ-GRL-1-A.test.cpp
    title: test/03_Graph/02_GraphAlgorithm/01.01.03.01_AOJ-GRL-1-A.test.cpp
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
  - 03_Graph/02_GraphAlgorithm/01.01.03.01_single-source-shortest-path.weighted-graph.dijkstra.hpp
  - 03_Graph/01_TreeAlgorithm/01.00_tree-diameter.hpp
  - 03_Graph/01_TreeAlgorithm/01.01_tree-diameter-weight.hpp
  - 03_Graph/01_TreeAlgorithm/01.02_tree-diameter.path.hpp
  timestamp: '2021-04-25 12:31:21+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/03_Graph/02_GraphAlgorithm/01.01.03.01_AOJ-GRL-1-A.test.cpp
  - test/03_Graph/01_TreeAlgorithm/01.01_AOJ-GRL-5-A.test.cpp
documentation_of: template/graph.hpp
layout: document
redirect_from:
- /library/template/graph.hpp
- /library/template/graph.hpp.html
title: template/graph.hpp
---
