---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: 02_DataStructure/02_SegmentTree/00.00_monoid.base.hpp
    title: 02_DataStructure/02_SegmentTree/00.00_monoid.base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/02_DataStructure/02_SegmentTree/00.01.01_AOJ-DSL-2-A.test copy.cpp
    title: test/02_DataStructure/02_SegmentTree/00.01.01_AOJ-DSL-2-A.test copy.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/02_DataStructure/02_SegmentTree/00.01.01_AOJ-DSL-2-A.test.cpp
    title: test/02_DataStructure/02_SegmentTree/00.01.01_AOJ-DSL-2-A.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC"
    links: []
  bundledCode: "#line 2 \"02_DataStructure/02_SegmentTree/01_segment-tree.hpp\"\n\
    #include <cassert>\n#include <cstdint>\n#include <type_traits>\n#include <vector>\n\
    #line 3 \"02_DataStructure/02_SegmentTree/00.00_monoid.base.hpp\"\n\nclass monoid_base\
    \ {};\nclass operator_monoid_base : public monoid_base {};\n\ntemplate <class\
    \ T>\nusing is_monoid = std::is_base_of<monoid_base, T>;\n\ntemplate <class T>\n\
    using is_operator_monoid = std::is_base_of<operator_monoid_base, T>;\n#line 7\
    \ \"02_DataStructure/02_SegmentTree/01_segment-tree.hpp\"\n\n/**\n * @brief \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC\n */\ntemplate <class Monoid>\nclass\
    \ SegmentTree {\n    static_assert(is_monoid<Monoid>::value);\n\npublic:\n   \
    \ using T = typename Monoid::value_type;\n\nprotected:\n    void init(const std::uint32_t&\
    \ n) {\n        for (_size = 1, _level = 0; _size < n; _size <<= 1, ++_level);\n\
    \        _data.assign(_size << 1, _monoid.e());\n    }\n\npublic:\n    SegmentTree()\
    \ = default;\n    explicit SegmentTree(const std::uint32_t& n) {\n        build(n);\n\
    \    }\n    explicit SegmentTree(const std::vector<T>& v) {\n        build(v);\n\
    \    }\n\n    void build(const std::uint32_t& n) {\n        init(n);\n    }\n\
    \    void build(const std::vector<T>& v) {\n        const std::uint32_t n = v.size();\n\
    \        init(n);\n        for (std::uint32_t i = 0; i < n; ++i) {\n         \
    \   _data[_size + i] = v[i];\n        }\n        for (std::uint32_t i = _size\
    \ - 1; i > 0; --i) {\n            _data[i] = _monoid.op(_data[(i << 1) | 0], _data[(i\
    \ << 1) | 1]);\n        }\n    }\n\n    void set(std::uint32_t p, T x) {\n   \
    \     assert(0 <= p && p < _size);\n        _data[p += _size] = x;\n        while\
    \ (p >>= 1) {\n            _data[p] = _monoid.op(_data[(p << 1) | 0], _data[(p\
    \ << 1) | 1]);\n        }\n    }\n    T get(std::uint32_t p) {\n        assert(0\
    \ <= p && p < _size);\n        return _data[p + _size];\n    }\n\n    T query(std::uint32_t\
    \ a, std::uint32_t b) {\n        if (a >= b) return _monoid.e();\n        T L\
    \ = _monoid.e(), R = _monoid.e();\n        for (std::uint32_t l = a + _size, r\
    \ = b + _size; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) L = _monoid.op(L,\
    \ _data[l++]);\n            if (r & 1) R = _monoid.op(_data[--r], R);\n\t\t}\n\
    \        return _monoid.op(L, R);\n    }\n    T query() {\n        return _data[1];\n\
    \    }\n\nprotected:\n    std::uint32_t _size, _level;\n    std::vector<T> _data;\n\
    \    const Monoid _monoid = Monoid();\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n#include <type_traits>\n\
    #include <vector>\n#include \"00.00_monoid.base.hpp\"\n\n/**\n * @brief \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC\n */\ntemplate <class Monoid>\nclass\
    \ SegmentTree {\n    static_assert(is_monoid<Monoid>::value);\n\npublic:\n   \
    \ using T = typename Monoid::value_type;\n\nprotected:\n    void init(const std::uint32_t&\
    \ n) {\n        for (_size = 1, _level = 0; _size < n; _size <<= 1, ++_level);\n\
    \        _data.assign(_size << 1, _monoid.e());\n    }\n\npublic:\n    SegmentTree()\
    \ = default;\n    explicit SegmentTree(const std::uint32_t& n) {\n        build(n);\n\
    \    }\n    explicit SegmentTree(const std::vector<T>& v) {\n        build(v);\n\
    \    }\n\n    void build(const std::uint32_t& n) {\n        init(n);\n    }\n\
    \    void build(const std::vector<T>& v) {\n        const std::uint32_t n = v.size();\n\
    \        init(n);\n        for (std::uint32_t i = 0; i < n; ++i) {\n         \
    \   _data[_size + i] = v[i];\n        }\n        for (std::uint32_t i = _size\
    \ - 1; i > 0; --i) {\n            _data[i] = _monoid.op(_data[(i << 1) | 0], _data[(i\
    \ << 1) | 1]);\n        }\n    }\n\n    void set(std::uint32_t p, T x) {\n   \
    \     assert(0 <= p && p < _size);\n        _data[p += _size] = x;\n        while\
    \ (p >>= 1) {\n            _data[p] = _monoid.op(_data[(p << 1) | 0], _data[(p\
    \ << 1) | 1]);\n        }\n    }\n    T get(std::uint32_t p) {\n        assert(0\
    \ <= p && p < _size);\n        return _data[p + _size];\n    }\n\n    T query(std::uint32_t\
    \ a, std::uint32_t b) {\n        if (a >= b) return _monoid.e();\n        T L\
    \ = _monoid.e(), R = _monoid.e();\n        for (std::uint32_t l = a + _size, r\
    \ = b + _size; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) L = _monoid.op(L,\
    \ _data[l++]);\n            if (r & 1) R = _monoid.op(_data[--r], R);\n\t\t}\n\
    \        return _monoid.op(L, R);\n    }\n    T query() {\n        return _data[1];\n\
    \    }\n\nprotected:\n    std::uint32_t _size, _level;\n    std::vector<T> _data;\n\
    \    const Monoid _monoid = Monoid();\n};"
  dependsOn:
  - 02_DataStructure/02_SegmentTree/00.00_monoid.base.hpp
  isVerificationFile: false
  path: 02_DataStructure/02_SegmentTree/01_segment-tree.hpp
  requiredBy:
  - test/02_DataStructure/02_SegmentTree/00.01.01_AOJ-DSL-2-A.test copy.cpp
  timestamp: '2021-01-09 23:25:08+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/02_DataStructure/02_SegmentTree/00.01.01_AOJ-DSL-2-A.test.cpp
documentation_of: 02_DataStructure/02_SegmentTree/01_segment-tree.hpp
layout: document
redirect_from:
- /library/02_DataStructure/02_SegmentTree/01_segment-tree.hpp
- /library/02_DataStructure/02_SegmentTree/01_segment-tree.hpp.html
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC"
---
