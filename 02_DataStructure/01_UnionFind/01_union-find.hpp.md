---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: 02_DataStructure/01_UnionFind/02.01_attributed-union-find.min-max.hpp
    title: "\u5C5E\u6027\u3064\u304D Union-Find (min-max)"
  - icon: ':warning:'
    path: 02_DataStructure/01_UnionFind/02.02_attributed-union-find.sum.hpp
    title: "\u5C5E\u6027\u3064\u304D Union-Find (sum)"
  - icon: ':warning:'
    path: 02_DataStructure/01_UnionFind/02.03_attributed-union-find.mode.hpp
    title: "\u5C5E\u6027\u3064\u304D Union-Find (mode)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/02_DataStructure/01_UnionFind/01_AOJ-DSL-1-A.test.cpp
    title: test/02_DataStructure/01_UnionFind/01_AOJ-DSL-1-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/02_DataStructure/01_UnionFind/02.01_AOJ-2664.test.cpp
    title: test/02_DataStructure/01_UnionFind/02.01_AOJ-2664.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Union-Find
    links: []
  bundledCode: "#line 2 \"02_DataStructure/01_UnionFind/01_union-find.hpp\"\n#include\
    \ <cassert>\n#include <cstdint>\n#include <vector>\n\n/**\n * @brief Union-Find\n\
    \ */\nclass union_find {\npublic:\n    union_find() = default;\n    explicit union_find(std::uint32_t\
    \ n) : _n(n), _num(n), _par(n, n), _size(n, 1) {}\n    void init(std::uint32_t\
    \ n) { _par.assign(n, n); _size.assign(n, 1); }\n    \n    std::uint32_t unite_trees(std::uint32_t\
    \ x, std::uint32_t y) {\n        assert(0 <= x && x < _n && 0 <= y && y < _n);\n\
    \        x = find_root(x); y = find_root(y);\n        if (x == y) return x;\n\
    \        if (_size[x] < _size[y]) std::swap(x, y);\n        _size[x] += _size[y];\n\
    \        _par[y] = x;\n        --_num;\n        return x;\n    }\n    std::uint32_t\
    \ find_root(std::uint32_t x) {\n        assert(0 <= x && x < _n);\n        return\
    \ (is_root(x) ? x : _par[x] = find_root(_par[x]));\n    }\n    bool is_root(std::uint32_t\
    \ x) {\n        assert(0 <= x && x < _n);\n        return (_par[x] == _n);\n \
    \   }\n    bool is_same(std::uint32_t x, std::uint32_t y) {\n        assert(0\
    \ <= x && x < _n && 0 <= y && y < _n);\n        return (find_root(x) == find_root(y));\n\
    \    }\n    std::size_t tree_size(std::uint32_t x) {\n        assert(0 <= x &&\
    \ x < _n);\n        return _size[find_root(x)];\n    }\n    std::size_t number_of_trees()\
    \ {\n        return _num;\n    }\n\nprotected:\n    std::uint32_t _n, _num;\n\
    \    std::vector<std::uint32_t> _par, _size;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n#include <vector>\n\
    \n/**\n * @brief Union-Find\n */\nclass union_find {\npublic:\n    union_find()\
    \ = default;\n    explicit union_find(std::uint32_t n) : _n(n), _num(n), _par(n,\
    \ n), _size(n, 1) {}\n    void init(std::uint32_t n) { _par.assign(n, n); _size.assign(n,\
    \ 1); }\n    \n    std::uint32_t unite_trees(std::uint32_t x, std::uint32_t y)\
    \ {\n        assert(0 <= x && x < _n && 0 <= y && y < _n);\n        x = find_root(x);\
    \ y = find_root(y);\n        if (x == y) return x;\n        if (_size[x] < _size[y])\
    \ std::swap(x, y);\n        _size[x] += _size[y];\n        _par[y] = x;\n    \
    \    --_num;\n        return x;\n    }\n    std::uint32_t find_root(std::uint32_t\
    \ x) {\n        assert(0 <= x && x < _n);\n        return (is_root(x) ? x : _par[x]\
    \ = find_root(_par[x]));\n    }\n    bool is_root(std::uint32_t x) {\n       \
    \ assert(0 <= x && x < _n);\n        return (_par[x] == _n);\n    }\n    bool\
    \ is_same(std::uint32_t x, std::uint32_t y) {\n        assert(0 <= x && x < _n\
    \ && 0 <= y && y < _n);\n        return (find_root(x) == find_root(y));\n    }\n\
    \    std::size_t tree_size(std::uint32_t x) {\n        assert(0 <= x && x < _n);\n\
    \        return _size[find_root(x)];\n    }\n    std::size_t number_of_trees()\
    \ {\n        return _num;\n    }\n\nprotected:\n    std::uint32_t _n, _num;\n\
    \    std::vector<std::uint32_t> _par, _size;\n};"
  dependsOn: []
  isVerificationFile: false
  path: 02_DataStructure/01_UnionFind/01_union-find.hpp
  requiredBy:
  - 02_DataStructure/01_UnionFind/02.03_attributed-union-find.mode.hpp
  - 02_DataStructure/01_UnionFind/02.02_attributed-union-find.sum.hpp
  - 02_DataStructure/01_UnionFind/02.01_attributed-union-find.min-max.hpp
  timestamp: '2021-01-10 00:26:45+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/02_DataStructure/01_UnionFind/02.01_AOJ-2664.test.cpp
  - test/02_DataStructure/01_UnionFind/01_AOJ-DSL-1-A.test.cpp
documentation_of: 02_DataStructure/01_UnionFind/01_union-find.hpp
layout: document
redirect_from:
- /library/02_DataStructure/01_UnionFind/01_union-find.hpp
- /library/02_DataStructure/01_UnionFind/01_union-find.hpp.html
title: Union-Find
---
