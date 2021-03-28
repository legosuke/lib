---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: 02_DataStructure/02_SegmentTree/00.00_monoid.base.hpp
    title: "\u30E2\u30CE\u30A4\u30C9 (base)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/02_DataStructure/02_SegmentTree/00.01.03_AOJ-DSL-2-E.test.cpp
    title: test/02_DataStructure/02_SegmentTree/00.01.03_AOJ-DSL-2-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/02_DataStructure/02_SegmentTree/00.01.04_AOJ-DSL-2-D.test.cpp
    title: test/02_DataStructure/02_SegmentTree/00.01.04_AOJ-DSL-2-D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC"
    links: []
  bundledCode: "#line 2 \"02_DataStructure/02_SegmentTree/02_dual-segment-tree.hpp\"\
    \n#include <cassert>\n#include <cstdint>\n#include <type_traits>\n#include <vector>\n\
    #line 3 \"02_DataStructure/02_SegmentTree/00.00_monoid.base.hpp\"\n\n/**\n * @brief\
    \ \u30E2\u30CE\u30A4\u30C9 (base)\n */\nclass monoid_base {};\n\ntemplate <class\
    \ T>\nusing is_monoid = std::is_base_of<monoid_base, T>;\n#line 7 \"02_DataStructure/02_SegmentTree/02_dual-segment-tree.hpp\"\
    \n\n/**\n * @brief \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC\
    \n */\ntemplate <class MonoidF>\nclass dual_segment_tree {\n    static_assert(is_monoid<MonoidF>::value);\n\
    \npublic:\n    using lazy_type = typename MonoidF::value_type;\n\nprotected:\n\
    \    void init(const std::uint32_t& n) {\n        for (_size = 1, _level = 0;\
    \ _size < n; _size <<= 1, ++_level);\n        _lazy.assign(_size << 1, _monoid_f.e());\n\
    \    }\n\n    void push(std::uint32_t p) {\n        for (std::uint32_t i = _level;\
    \ i > 0; --i) {\n            std::uint32_t j = p >> i;\n            if (_lazy[j]\
    \ == _monoid_f.e()) continue;\n            _lazy[(j << 1) | 0] = _monoid_f.op(_lazy[(j\
    \ << 1) | 0], _lazy[j]);\n            _lazy[(j << 1) | 1] = _monoid_f.op(_lazy[(j\
    \ << 1) | 1], _lazy[j]);\n            _lazy[j] = _monoid_f.e();\n        }\n \
    \   }\n\npublic:\n    dual_segment_tree() = default;\n    explicit dual_segment_tree(const\
    \ std::uint32_t& n) {\n        build(n);\n    }\n    explicit dual_segment_tree(const\
    \ std::vector<lazy_type>& v) {\n        build(v);\n    }\n    \n    void build(const\
    \ std::uint32_t& n) {\n        init(n);\n    }\n    void build(const std::vector<lazy_type>&\
    \ v) {\n        const std::uint32_t n = v.size();\n        init(n);\n        for\
    \ (std::uint32_t i = 0; i < n; ++i) {\n            _lazy[_size + i] = v[i];\n\
    \        }\n        for (std::uint32_t i = _size - 1; i > 0; --i) {\n        \
    \    _lazy[i] = _monoid_f.op(_lazy[(i << 1) | 0], _lazy[(i << 1) | 1]);\n    \
    \    }\n    }\n\n    void set(std::uint32_t p, lazy_type x) {\n        assert(0\
    \ <= p && p < _size);\n        _lazy[p += _size] = x;\n    }\n    lazy_type get(std::uint32_t\
    \ p) {\n        assert(0 <= p && p < _size);\n        push(p += _size);\n    \
    \    return _lazy[p];\n    }\n\n    void apply(std::uint32_t l, std::uint32_t\
    \ r, const lazy_type& x) {\n        if (l >= r) return;\n        push(l += _size);\
    \ push(r += _size - 1);\n        for (++r; l < r; l >>= 1, r >>= 1) {\n      \
    \      if (l & 1) _lazy[l] = _monoid_f.op(_lazy[l], x), ++l;\n            if (r\
    \ & 1) --r, _lazy[r] = _monoid_f.op(_lazy[r], x);\n\t\t}\n    }\n\nprotected:\n\
    \    std::uint32_t _size, _level;\n    std::vector<lazy_type> _lazy;\n    const\
    \ MonoidF _monoid_f = MonoidF();\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n#include <type_traits>\n\
    #include <vector>\n#include \"00.00_monoid.base.hpp\"\n\n/**\n * @brief \u53CC\
    \u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC\n */\ntemplate <class MonoidF>\n\
    class dual_segment_tree {\n    static_assert(is_monoid<MonoidF>::value);\n\npublic:\n\
    \    using lazy_type = typename MonoidF::value_type;\n\nprotected:\n    void init(const\
    \ std::uint32_t& n) {\n        for (_size = 1, _level = 0; _size < n; _size <<=\
    \ 1, ++_level);\n        _lazy.assign(_size << 1, _monoid_f.e());\n    }\n\n \
    \   void push(std::uint32_t p) {\n        for (std::uint32_t i = _level; i > 0;\
    \ --i) {\n            std::uint32_t j = p >> i;\n            if (_lazy[j] == _monoid_f.e())\
    \ continue;\n            _lazy[(j << 1) | 0] = _monoid_f.op(_lazy[(j << 1) | 0],\
    \ _lazy[j]);\n            _lazy[(j << 1) | 1] = _monoid_f.op(_lazy[(j << 1) |\
    \ 1], _lazy[j]);\n            _lazy[j] = _monoid_f.e();\n        }\n    }\n\n\
    public:\n    dual_segment_tree() = default;\n    explicit dual_segment_tree(const\
    \ std::uint32_t& n) {\n        build(n);\n    }\n    explicit dual_segment_tree(const\
    \ std::vector<lazy_type>& v) {\n        build(v);\n    }\n    \n    void build(const\
    \ std::uint32_t& n) {\n        init(n);\n    }\n    void build(const std::vector<lazy_type>&\
    \ v) {\n        const std::uint32_t n = v.size();\n        init(n);\n        for\
    \ (std::uint32_t i = 0; i < n; ++i) {\n            _lazy[_size + i] = v[i];\n\
    \        }\n        for (std::uint32_t i = _size - 1; i > 0; --i) {\n        \
    \    _lazy[i] = _monoid_f.op(_lazy[(i << 1) | 0], _lazy[(i << 1) | 1]);\n    \
    \    }\n    }\n\n    void set(std::uint32_t p, lazy_type x) {\n        assert(0\
    \ <= p && p < _size);\n        _lazy[p += _size] = x;\n    }\n    lazy_type get(std::uint32_t\
    \ p) {\n        assert(0 <= p && p < _size);\n        push(p += _size);\n    \
    \    return _lazy[p];\n    }\n\n    void apply(std::uint32_t l, std::uint32_t\
    \ r, const lazy_type& x) {\n        if (l >= r) return;\n        push(l += _size);\
    \ push(r += _size - 1);\n        for (++r; l < r; l >>= 1, r >>= 1) {\n      \
    \      if (l & 1) _lazy[l] = _monoid_f.op(_lazy[l], x), ++l;\n            if (r\
    \ & 1) --r, _lazy[r] = _monoid_f.op(_lazy[r], x);\n\t\t}\n    }\n\nprotected:\n\
    \    std::uint32_t _size, _level;\n    std::vector<lazy_type> _lazy;\n    const\
    \ MonoidF _monoid_f = MonoidF();\n};"
  dependsOn:
  - 02_DataStructure/02_SegmentTree/00.00_monoid.base.hpp
  isVerificationFile: false
  path: 02_DataStructure/02_SegmentTree/02_dual-segment-tree.hpp
  requiredBy: []
  timestamp: '2021-03-25 11:25:32+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/02_DataStructure/02_SegmentTree/00.01.04_AOJ-DSL-2-D.test.cpp
  - test/02_DataStructure/02_SegmentTree/00.01.03_AOJ-DSL-2-E.test.cpp
documentation_of: 02_DataStructure/02_SegmentTree/02_dual-segment-tree.hpp
layout: document
redirect_from:
- /library/02_DataStructure/02_SegmentTree/02_dual-segment-tree.hpp
- /library/02_DataStructure/02_SegmentTree/02_dual-segment-tree.hpp.html
title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC"
---