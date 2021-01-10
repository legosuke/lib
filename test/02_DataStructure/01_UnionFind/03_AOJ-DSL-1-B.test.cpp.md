---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: 02_DataStructure/01_UnionFind/03_potentialized-union-find.hpp
    title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union-Find"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
  bundledCode: "#line 1 \"test/02_DataStructure/01_UnionFind/03_AOJ-DSL-1-B.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B\"\n#line\
    \ 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#define int int64_t\n\
    using namespace std;\n#line 6 \"02_DataStructure/01_UnionFind/03_potentialized-union-find.hpp\"\
    \n\n/**\n * @brief \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union-Find\n\
    \ */\ntemplate <typename T>\nclass potentialized_union_find {\npublic:\n    potentialized_union_find()\
    \ = default;\n    explicit potentialized_union_find(std::uint32_t n)\n       \
    \ : _n(n), _num(n), _par(n, n), _size(n, 1), _weight(n) {}\n\n    bool unite_trees(std::uint32_t\
    \ x, std::uint32_t y, T w) {\n        assert(0 <= x && x < _n && 0 <= y && y <\
    \ _n);\n        w += weight(x); w -= weight(y);\n        x = find_root(x); y =\
    \ find_root(y);\n        if (x == y) return (w == 0);\n        if (_size[x] <\
    \ _size[y]) std::swap(x, y), w = -w;\n        _size[x] += _size[y];\n        _par[y]\
    \ = x;\n        _weight[y] = w;\n        --_num;\n        return true;\n    }\n\
    \    std::uint32_t find_root(std::uint32_t x) {\n        assert(0 <= x && x <\
    \ _n);\n        if (_par[x] == _n) return x;\n        std::uint32_t root = find_root(_par[x]);\n\
    \        _weight[x] += _weight[_par[x]];\n        return _par[x] = root;\n   \
    \ }\n    bool is_root(std::uint32_t x) {\n        assert(0 <= x && x < _n);\n\
    \        return (_par[x] == _n);\n    }\n    bool is_same(std::uint32_t x, std::uint32_t\
    \ y) {\n        assert(0 <= x && x < _n && 0 <= y && y < _n);\n        return\
    \ (find_root(x) == find_root(y));\n    }\n    std::size_t tree_size(std::uint32_t\
    \ x) {\n        assert(0 <= x && x < _n);\n        return _size[find_root(x)];\n\
    \    }\n    std::size_t number_of_trees() {\n        return _num;\n    }\n   \
    \ T weight(std::uint32_t x) {\n        assert(0 <= x && x < _n);\n        find_root(x);\n\
    \        return _weight[x];\n    }\n    T diff_weight(std::uint32_t x, std::uint32_t\
    \ y) {\n        assert(0 <= x && x < _n && 0 <= y && y < _n);\n        assert(is_same(x,\
    \ y));\n        return weight(y) - weight(x);\n    }\n\nprotected:\n    std::uint32_t\
    \ _n, _num;\n    std::vector<std::uint32_t> _par, _size;\n    std::vector<T> _weight;\n\
    };\n#line 4 \"test/02_DataStructure/01_UnionFind/03_AOJ-DSL-1-B.test.cpp\"\n\n\
    signed main() {\n    int n, q;\n    cin >> n >> q;\n    potentialized_union_find<int>\
    \ uf(n);\n    for (int i = 0; i < q; ++i) {\n        int c, x, y, z;\n       \
    \ cin >> c >> x >> y;\n        if (c == 0) {\n            cin >> z;\n        \
    \    uf.unite_trees(x, y, z);\n        } else {\n            if (uf.is_same(x,\
    \ y)) cout << uf.diff_weight(x, y) << endl;\n            else cout << \"?\" <<\
    \ endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B\"\n#include\
    \ \"../../../template/template.hpp\"\n#include \"../../../02_DataStructure/01_UnionFind/03_potentialized-union-find.hpp\"\
    \n\nsigned main() {\n    int n, q;\n    cin >> n >> q;\n    potentialized_union_find<int>\
    \ uf(n);\n    for (int i = 0; i < q; ++i) {\n        int c, x, y, z;\n       \
    \ cin >> c >> x >> y;\n        if (c == 0) {\n            cin >> z;\n        \
    \    uf.unite_trees(x, y, z);\n        } else {\n            if (uf.is_same(x,\
    \ y)) cout << uf.diff_weight(x, y) << endl;\n            else cout << \"?\" <<\
    \ endl;\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - 02_DataStructure/01_UnionFind/03_potentialized-union-find.hpp
  isVerificationFile: true
  path: test/02_DataStructure/01_UnionFind/03_AOJ-DSL-1-B.test.cpp
  requiredBy: []
  timestamp: '2021-01-10 00:26:45+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/02_DataStructure/01_UnionFind/03_AOJ-DSL-1-B.test.cpp
layout: document
redirect_from:
- /verify/test/02_DataStructure/01_UnionFind/03_AOJ-DSL-1-B.test.cpp
- /verify/test/02_DataStructure/01_UnionFind/03_AOJ-DSL-1-B.test.cpp.html
title: test/02_DataStructure/01_UnionFind/03_AOJ-DSL-1-B.test.cpp
---
