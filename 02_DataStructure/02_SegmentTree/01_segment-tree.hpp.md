---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: 02_DataStructure/02_SegmentTree/00.00_monoid.base.hpp
    title: "\u30E2\u30CE\u30A4\u30C9 (base)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/02_DataStructure/02_SegmentTree/00.01.01.01_AOJ-DSL-2-A.test.cpp
    title: test/02_DataStructure/02_SegmentTree/00.01.01.01_AOJ-DSL-2-A.test.cpp
  - icon: ':x:'
    path: test/02_DataStructure/02_SegmentTree/00.01.01.02_AOJ-DSL-2-A.test.cpp
    title: test/02_DataStructure/02_SegmentTree/00.01.01.02_AOJ-DSL-2-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/02_DataStructure/02_SegmentTree/00.01.02.01_AOJ-DSL-2-A.test.cpp
    title: test/02_DataStructure/02_SegmentTree/00.01.02.01_AOJ-DSL-2-A.test.cpp
  - icon: ':x:'
    path: test/02_DataStructure/02_SegmentTree/00.01.02.02_AOJ-DSL-2-A.test.cpp
    title: test/02_DataStructure/02_SegmentTree/00.01.02.02_AOJ-DSL-2-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/02_DataStructure/02_SegmentTree/00.01.03_AOJ-DSL-2-B.test.cpp
    title: test/02_DataStructure/02_SegmentTree/00.01.03_AOJ-DSL-2-B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC"
    links: []
  bundledCode: "#line 2 \"02_DataStructure/02_SegmentTree/01_segment-tree.hpp\"\n\
    #include <cassert>\n#include <cstdint>\n#include <vector>\n#line 2 \"02_DataStructure/02_SegmentTree/00.00_monoid.base.hpp\"\
    \n#include <type_traits>\n\n/**\n * @brief \u30E2\u30CE\u30A4\u30C9 (base)\n */\n\
    class monoid_base {};\n\ntemplate <class T>\nusing is_monoid = std::is_base_of<monoid_base,\
    \ T>;\n#line 6 \"02_DataStructure/02_SegmentTree/01_segment-tree.hpp\"\n\n/**\n\
    \ * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC\n */\ntemplate <class\
    \ MonoidX>\nclass segment_tree {\n    static_assert(is_monoid<MonoidX>::value);\n\
    \npublic:\n    using data_type = typename MonoidX::value_type;\n\nprotected:\n\
    \    void init(const std::uint32_t& n) {\n        for (_size = 1, _level = 0;\
    \ _size < n; _size <<= 1, ++_level);\n        _data.assign(_size << 1, _monoid_x.e());\n\
    \    }\n\npublic:\n    segment_tree() = default;\n    explicit segment_tree(const\
    \ std::uint32_t& n) {\n        build(n);\n    }\n    explicit segment_tree(const\
    \ std::vector<data_type>& v) {\n        build(v);\n    }\n\n    void build(const\
    \ std::uint32_t& n) {\n        init(n);\n    }\n    void build(const std::vector<data_type>&\
    \ v) {\n        const std::uint32_t n = v.size();\n        init(n);\n        for\
    \ (std::uint32_t i = 0; i < n; ++i) {\n            _data[_size + i] = v[i];\n\
    \        }\n        for (std::uint32_t i = _size - 1; i > 0; --i) {\n        \
    \    _data[i] = _monoid_x.op(_data[(i << 1) | 0], _data[(i << 1) | 1]);\n    \
    \    }\n    }\n\n    void set(std::uint32_t p, data_type x) {\n        assert(0\
    \ <= p && p < _size);\n        _data[p += _size] = x;\n        while (p >>= 1)\
    \ {\n            _data[p] = _monoid_x.op(_data[(p << 1) | 0], _data[(p << 1) |\
    \ 1]);\n        }\n    }\n    data_type get(std::uint32_t p) {\n        assert(0\
    \ <= p && p < _size);\n        return _data[p + _size];\n    }\n\n    data_type\
    \ product(std::uint32_t l, std::uint32_t r) {\n        if (l >= r) return _monoid_x.e();\n\
    \        data_type L = _monoid_x.e(), R = _monoid_x.e();\n        for (l += _size,\
    \ r += _size; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) L = _monoid_x.op(L,\
    \ _data[l++]);\n            if (r & 1) R = _monoid_x.op(_data[--r], R);\n\t\t\
    }\n        return _monoid_x.op(L, R);\n    }\n\nprotected:\n    std::uint32_t\
    \ _size, _level;\n    std::vector<data_type> _data;\n    const MonoidX _monoid_x\
    \ = MonoidX();\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n#include <vector>\n\
    #include \"00.00_monoid.base.hpp\"\n\n/**\n * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\
    \u30C4\u30EA\u30FC\n */\ntemplate <class MonoidX>\nclass segment_tree {\n    static_assert(is_monoid<MonoidX>::value);\n\
    \npublic:\n    using data_type = typename MonoidX::value_type;\n\nprotected:\n\
    \    void init(const std::uint32_t& n) {\n        for (_size = 1, _level = 0;\
    \ _size < n; _size <<= 1, ++_level);\n        _data.assign(_size << 1, _monoid_x.e());\n\
    \    }\n\npublic:\n    segment_tree() = default;\n    explicit segment_tree(const\
    \ std::uint32_t& n) {\n        build(n);\n    }\n    explicit segment_tree(const\
    \ std::vector<data_type>& v) {\n        build(v);\n    }\n\n    void build(const\
    \ std::uint32_t& n) {\n        init(n);\n    }\n    void build(const std::vector<data_type>&\
    \ v) {\n        const std::uint32_t n = v.size();\n        init(n);\n        for\
    \ (std::uint32_t i = 0; i < n; ++i) {\n            _data[_size + i] = v[i];\n\
    \        }\n        for (std::uint32_t i = _size - 1; i > 0; --i) {\n        \
    \    _data[i] = _monoid_x.op(_data[(i << 1) | 0], _data[(i << 1) | 1]);\n    \
    \    }\n    }\n\n    void set(std::uint32_t p, data_type x) {\n        assert(0\
    \ <= p && p < _size);\n        _data[p += _size] = x;\n        while (p >>= 1)\
    \ {\n            _data[p] = _monoid_x.op(_data[(p << 1) | 0], _data[(p << 1) |\
    \ 1]);\n        }\n    }\n    data_type get(std::uint32_t p) {\n        assert(0\
    \ <= p && p < _size);\n        return _data[p + _size];\n    }\n\n    data_type\
    \ product(std::uint32_t l, std::uint32_t r) {\n        if (l >= r) return _monoid_x.e();\n\
    \        data_type L = _monoid_x.e(), R = _monoid_x.e();\n        for (l += _size,\
    \ r += _size; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) L = _monoid_x.op(L,\
    \ _data[l++]);\n            if (r & 1) R = _monoid_x.op(_data[--r], R);\n\t\t\
    }\n        return _monoid_x.op(L, R);\n    }\n\nprotected:\n    std::uint32_t\
    \ _size, _level;\n    std::vector<data_type> _data;\n    const MonoidX _monoid_x\
    \ = MonoidX();\n};"
  dependsOn:
  - 02_DataStructure/02_SegmentTree/00.00_monoid.base.hpp
  isVerificationFile: false
  path: 02_DataStructure/02_SegmentTree/01_segment-tree.hpp
  requiredBy: []
  timestamp: '2021-04-26 12:50:54+00:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/02_DataStructure/02_SegmentTree/00.01.01.01_AOJ-DSL-2-A.test.cpp
  - test/02_DataStructure/02_SegmentTree/00.01.02.02_AOJ-DSL-2-A.test.cpp
  - test/02_DataStructure/02_SegmentTree/00.01.01.02_AOJ-DSL-2-A.test.cpp
  - test/02_DataStructure/02_SegmentTree/00.01.03_AOJ-DSL-2-B.test.cpp
  - test/02_DataStructure/02_SegmentTree/00.01.02.01_AOJ-DSL-2-A.test.cpp
documentation_of: 02_DataStructure/02_SegmentTree/01_segment-tree.hpp
layout: document
redirect_from:
- /library/02_DataStructure/02_SegmentTree/01_segment-tree.hpp
- /library/02_DataStructure/02_SegmentTree/01_segment-tree.hpp.html
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC"
---
