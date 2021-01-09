---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: 02_DataStructure/01_UnionFind/01_union-find.hpp
    title: Union-Find
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A
  bundledCode: "#line 1 \"test/02_DataStructure/01_UnionFind/01_AOJ-DSL-1-A.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A\"\n#line\
    \ 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#define int int64_t\n\
    using namespace std;\n#line 5 \"02_DataStructure/01_UnionFind/01_union-find.hpp\"\
    \n\n/**\n * @brief Union-Find\n */\nclass UnionFind {\npublic:\n    UnionFind()\
    \ = default;\n    explicit UnionFind(std::uint32_t n) : _n(n), _num(n), _par(n,\
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
    \    std::vector<std::uint32_t> _par, _size;\n};\n#line 4 \"test/02_DataStructure/01_UnionFind/01_AOJ-DSL-1-A.test.cpp\"\
    \n\nsigned main() {\n    int n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n\
    \    for (int i = 0; i < q; ++i) {\n        int com, x, y;\n        cin >> com\
    \ >> x >> y;\n        if (com == 0) uf.unite_trees(x, y);\n        else cout <<\
    \ uf.is_same(x, y) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A\"\n#include\
    \ \"../../../template/template.hpp\"\n#include \"../../../02_DataStructure/01_UnionFind/01_union-find.hpp\"\
    \n\nsigned main() {\n    int n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n\
    \    for (int i = 0; i < q; ++i) {\n        int com, x, y;\n        cin >> com\
    \ >> x >> y;\n        if (com == 0) uf.unite_trees(x, y);\n        else cout <<\
    \ uf.is_same(x, y) << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - 02_DataStructure/01_UnionFind/01_union-find.hpp
  isVerificationFile: true
  path: test/02_DataStructure/01_UnionFind/01_AOJ-DSL-1-A.test.cpp
  requiredBy: []
  timestamp: '2021-01-09 20:51:59+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/02_DataStructure/01_UnionFind/01_AOJ-DSL-1-A.test.cpp
layout: document
redirect_from:
- /verify/test/02_DataStructure/01_UnionFind/01_AOJ-DSL-1-A.test.cpp
- /verify/test/02_DataStructure/01_UnionFind/01_AOJ-DSL-1-A.test.cpp.html
title: test/02_DataStructure/01_UnionFind/01_AOJ-DSL-1-A.test.cpp
---
