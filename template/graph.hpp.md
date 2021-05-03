---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: 03_Graph/01_TreeAlgorithm/01.00_tree-diameter.hpp
    title: "\u6728\u306E\u76F4\u5F84"
  - icon: ':heavy_check_mark:'
    path: 03_Graph/01_TreeAlgorithm/01.01_tree-diameter.weight.hpp
    title: "\u6728\u306E\u76F4\u5F84 (\u91CD\u307F)"
  - icon: ':heavy_check_mark:'
    path: 03_Graph/01_TreeAlgorithm/01.02_tree-diameter.path.hpp
    title: "\u6728\u306E\u76F4\u5F84 (\u30D1\u30B9)"
  - icon: ':question:'
    path: 03_Graph/02_GraphAlgorithm/01.01.03.01_single-source-shortest-path.weighted-graph.dijkstra.hpp
    title: "\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF (Dijkstra)"
  - icon: ':heavy_check_mark:'
    path: 03_Graph/04_DirectedGraphAlgorithm/02.01_strongly-connected-components.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/03_Graph/01_TreeAlgorithm/01.01_AOJ-GRL-5-A.test.cpp
    title: test/03_Graph/01_TreeAlgorithm/01.01_AOJ-GRL-5-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/03_Graph/01_TreeAlgorithm/01.02_LC-tree-diameter.test.cpp
    title: test/03_Graph/01_TreeAlgorithm/01.02_LC-tree-diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/03_Graph/02_GraphAlgorithm/01.01.03.01_AOJ-GRL-1-A.test.cpp
    title: test/03_Graph/02_GraphAlgorithm/01.01.03.01_AOJ-GRL-1-A.test.cpp
  - icon: ':x:'
    path: test/03_Graph/02_GraphAlgorithm/01.01.03.01_LC-shortest-path.test.cpp
    title: test/03_Graph/02_GraphAlgorithm/01.01.03.01_LC-shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/03_Graph/04_DirectedGraphAlgorithm/02.01_AOJ-GRL-3-C.test.cpp
    title: test/03_Graph/04_DirectedGraphAlgorithm/02.01_AOJ-GRL-3-C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/graph.hpp\"\n#include <cstdint>\n#include <vector>\n\
    \ntemplate <typename T = std::uint32_t>\nstruct edge {\n    std::uint32_t from,\
    \ to;\n    T weight;\n    edge(std::uint32_t f, std::uint32_t t, T w) : from(f),\
    \ to(t), weight(w) {}\n    using weight_type = T;\n};\n\nstruct unweighted_edge\
    \ : edge<> {\n    explicit unweighted_edge(std::uint32_t t) : edge<>(-1, t, 1)\
    \ {}\n    explicit unweighted_edge(std::uint32_t f, std::uint32_t t) : edge<>(f,\
    \ t, 1) {}\n};\nusing unweighted_edges = std::vector<unweighted_edge>;\nusing\
    \ unweighted_graph = std::vector<unweighted_edges>;\n\ntemplate <typename T =\
    \ std::uint32_t>\nstruct weighted_edge : edge<T> {\n    explicit weighted_edge(std::uint32_t\
    \ t, T w) : edge<T>(-1, t, w) {}\n    explicit weighted_edge(std::uint32_t f,\
    \ std::uint32_t t, T w) : edge<T>(f, t, w) {}\n};\ntemplate <typename T = std::uint32_t>\
    \ using weighted_edges = std::vector<weighted_edge<T>>;\ntemplate <typename T\
    \ = std::uint32_t> using weighted_graph = std::vector<weighted_edges<T>>;\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\n\ntemplate <typename\
    \ T = std::uint32_t>\nstruct edge {\n    std::uint32_t from, to;\n    T weight;\n\
    \    edge(std::uint32_t f, std::uint32_t t, T w) : from(f), to(t), weight(w) {}\n\
    \    using weight_type = T;\n};\n\nstruct unweighted_edge : edge<> {\n    explicit\
    \ unweighted_edge(std::uint32_t t) : edge<>(-1, t, 1) {}\n    explicit unweighted_edge(std::uint32_t\
    \ f, std::uint32_t t) : edge<>(f, t, 1) {}\n};\nusing unweighted_edges = std::vector<unweighted_edge>;\n\
    using unweighted_graph = std::vector<unweighted_edges>;\n\ntemplate <typename\
    \ T = std::uint32_t>\nstruct weighted_edge : edge<T> {\n    explicit weighted_edge(std::uint32_t\
    \ t, T w) : edge<T>(-1, t, w) {}\n    explicit weighted_edge(std::uint32_t f,\
    \ std::uint32_t t, T w) : edge<T>(f, t, w) {}\n};\ntemplate <typename T = std::uint32_t>\
    \ using weighted_edges = std::vector<weighted_edge<T>>;\ntemplate <typename T\
    \ = std::uint32_t> using weighted_graph = std::vector<weighted_edges<T>>;"
  dependsOn: []
  isVerificationFile: false
  path: template/graph.hpp
  requiredBy:
  - 03_Graph/02_GraphAlgorithm/01.01.03.01_single-source-shortest-path.weighted-graph.dijkstra.hpp
  - 03_Graph/04_DirectedGraphAlgorithm/02.01_strongly-connected-components.hpp
  - 03_Graph/01_TreeAlgorithm/01.00_tree-diameter.hpp
  - 03_Graph/01_TreeAlgorithm/01.02_tree-diameter.path.hpp
  - 03_Graph/01_TreeAlgorithm/01.01_tree-diameter.weight.hpp
  timestamp: '2021-04-27 18:12:15+00:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/03_Graph/02_GraphAlgorithm/01.01.03.01_AOJ-GRL-1-A.test.cpp
  - test/03_Graph/02_GraphAlgorithm/01.01.03.01_LC-shortest-path.test.cpp
  - test/03_Graph/04_DirectedGraphAlgorithm/02.01_AOJ-GRL-3-C.test.cpp
  - test/03_Graph/01_TreeAlgorithm/01.01_AOJ-GRL-5-A.test.cpp
  - test/03_Graph/01_TreeAlgorithm/01.02_LC-tree-diameter.test.cpp
documentation_of: template/graph.hpp
layout: document
redirect_from:
- /library/template/graph.hpp
- /library/template/graph.hpp.html
title: template/graph.hpp
---
