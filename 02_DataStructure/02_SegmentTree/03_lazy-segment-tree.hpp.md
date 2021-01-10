---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: 02_DataStructure/02_SegmentTree/00.00_monoid.base.hpp
    title: 02_DataStructure/02_SegmentTree/00.00_monoid.base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/02_DataStructure/02_SegmentTree/00.02.01_AOJ-DSL-2-F.test.cpp
    title: test/02_DataStructure/02_SegmentTree/00.02.01_AOJ-DSL-2-F.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC"
    links: []
  bundledCode: "#line 2 \"02_DataStructure/02_SegmentTree/03_lazy-segment-tree.hpp\"\
    \n#include <cassert>\n#include <cstdint>\n#include <type_traits>\n#include <vector>\n\
    #line 3 \"02_DataStructure/02_SegmentTree/00.00_monoid.base.hpp\"\n\nclass monoid_base\
    \ {};\n\ntemplate <class T>\nusing is_monoid = std::is_base_of<monoid_base, T>;\n\
    #line 7 \"02_DataStructure/02_SegmentTree/03_lazy-segment-tree.hpp\"\n\n/**\n\
    \ * @brief \u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC\n */\n\
    template <class MonoidX, class MonoidF, class Mapping>\nclass lazy_segment_tree\
    \ {\n    static_assert(is_monoid<MonoidX>::value);\n    static_assert(is_monoid<MonoidF>::value);\n\
    \    static_assert(is_mapping<Mapping>::value);\n\npublic:\n    using data_type\
    \ = typename MonoidX::value_type;\n    using lazy_type = typename MonoidF::value_type;\n\
    \    static_assert(std::is_invocable_r<data_type, decltype(Mapping::op), data_type,\
    \ lazy_type, std::uint32_t>::value);\n\nprotected:\n    void init(const std::uint32_t&\
    \ n) {\n        for (_size = 1, _level = 0; _size < n; _size <<= 1, ++_level);\n\
    \        _data.assign(_size << 1, _monoid_x.e());\n        _lazy.assign(_size\
    \ << 1, _monoid_f.e());\n    }\n\n    lazy_type reflect(std::uint32_t j, std::uint32_t\
    \ length) {\n        return _lazy[j] == _monoid_f.e() ? _data[j] : _mapping.op(_data[j],\
    \ _lazy[j], length);\n    }\n\n    void push(std::uint32_t p) {\n        for (std::uint32_t\
    \ i = _level, length = _size; i > 0; --i, length >>= 1) {\n            std::uint32_t\
    \ j = p >> i;\n            if (_lazy[j] == _monoid_x.e()) continue;\n        \
    \    _lazy[(j << 1) | 0] = _monoid_f.op(_lazy[(j << 1) | 0], _lazy[j]);\n    \
    \        _lazy[(j << 1) | 1] = _monoid_f.op(_lazy[(j << 1) | 1], _lazy[j]);\n\
    \            _data[j] = reflect(j, length);\n            _lazy[j] = _monoid_f.e();\n\
    \        }\n    }\n\n    void recalc(std::uint32_t p) {\n        std::uint32_t\
    \ length = 1;\n        while (length <<= 1, p >>= 1) {\n            data_type\
    \ lhs = reflect((p << 1) | 0, length >> 1);\n            data_type rhs = reflect((p\
    \ << 1) | 1, length >> 1);\n            _data[p] = _monoid_x.op(lhs, rhs);\n \
    \       }\n    }\n\npublic:\n    lazy_segment_tree() = default;\n    explicit\
    \ lazy_segment_tree(const std::uint32_t& n) {\n        build(n);\n    }\n    explicit\
    \ lazy_segment_tree(const std::vector<data_type>& v) {\n        build(v);\n  \
    \  }\n    \n    void build(const std::uint32_t& n) {\n        init(n);\n    }\n\
    \    void build(const std::vector<data_type>& v) {\n        const std::uint32_t\
    \ n = v.size();\n        init(n);\n        for (std::uint32_t i = 0; i < n; ++i)\
    \ {\n            _data[_size + i] = v[i];\n        }\n        for (std::uint32_t\
    \ i = _size - 1; i > 0; --i) {\n            _data[i] = _monoid_x.op(_data[(i <<\
    \ 1) | 0], _data[(i << 1) | 1]);\n        }\n    }\n\n    void set(std::uint32_t\
    \ p, const data_type& x) {\n        assert(0 <= p && p < _size);\n        push(p\
    \ += _size);\n        _data[p] = x;\n        recalc(p);\n    }\n\n    data_type\
    \ get(std::uint32_t p) {\n        assert(0 <= p && p < _size);\n        push(p\
    \ += _size);\n        return _data[p];\n    }\n\n    void apply(std::uint32_t\
    \ l, std::uint32_t r, const lazy_type& x) {\n        if (l >= r) return;\n   \
    \     push(l += _size); push(r += _size - 1);\n        std::uint32_t l0 = l, r0\
    \ = r;\n        for (++r; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) _lazy[l]\
    \ = _monoid_f.op(_lazy[l], x), ++l;\n            if (r & 1) --r, _lazy[r] = _monoid_f.op(_lazy[r],\
    \ x);\n\t\t}\n        recalc(l0); recalc(r0);\n    }\n\n    data_type product(std::uint32_t\
    \ l, std::uint32_t r) {\n        if (l >= r) return _monoid_x.e();\n        push(l\
    \ += _size); push(r += _size - 1);\n        std::uint32_t length;\n        data_type\
    \ L = _monoid_x.e(), R = _monoid_x.e();\n        for (++r, length = 1; l < r;\
    \ l >>= 1, r >>= 1, length <<= 1) {\n            if (l & 1) L = _monoid_x.op(L,\
    \ reflect(l++, length));\n            if (r & 1) R = _monoid_x.op(R, reflect(--r,\
    \ length));\n\t\t}\n        return _monoid_x.op(L, R);\n    }\n\nprotected:\n\
    \    std::uint32_t _size, _level;\n    std::vector<data_type> _data;\n    std::vector<lazy_type>\
    \ _lazy;\n    const MonoidX _monoid_x = MonoidX();\n    const MonoidF _monoid_f\
    \ = MonoidF();\n    const Mapping _mapping = Mapping();\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n#include <type_traits>\n\
    #include <vector>\n#include \"00.00_monoid.base.hpp\"\n\n/**\n * @brief \u9045\
    \u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC\n */\ntemplate <class MonoidX,\
    \ class MonoidF, class Mapping>\nclass lazy_segment_tree {\n    static_assert(is_monoid<MonoidX>::value);\n\
    \    static_assert(is_monoid<MonoidF>::value);\n    static_assert(is_mapping<Mapping>::value);\n\
    \npublic:\n    using data_type = typename MonoidX::value_type;\n    using lazy_type\
    \ = typename MonoidF::value_type;\n    static_assert(std::is_invocable_r<data_type,\
    \ decltype(Mapping::op), data_type, lazy_type, std::uint32_t>::value);\n\nprotected:\n\
    \    void init(const std::uint32_t& n) {\n        for (_size = 1, _level = 0;\
    \ _size < n; _size <<= 1, ++_level);\n        _data.assign(_size << 1, _monoid_x.e());\n\
    \        _lazy.assign(_size << 1, _monoid_f.e());\n    }\n\n    lazy_type reflect(std::uint32_t\
    \ j, std::uint32_t length) {\n        return _lazy[j] == _monoid_f.e() ? _data[j]\
    \ : _mapping.op(_data[j], _lazy[j], length);\n    }\n\n    void push(std::uint32_t\
    \ p) {\n        for (std::uint32_t i = _level, length = _size; i > 0; --i, length\
    \ >>= 1) {\n            std::uint32_t j = p >> i;\n            if (_lazy[j] ==\
    \ _monoid_x.e()) continue;\n            _lazy[(j << 1) | 0] = _monoid_f.op(_lazy[(j\
    \ << 1) | 0], _lazy[j]);\n            _lazy[(j << 1) | 1] = _monoid_f.op(_lazy[(j\
    \ << 1) | 1], _lazy[j]);\n            _data[j] = reflect(j, length);\n       \
    \     _lazy[j] = _monoid_f.e();\n        }\n    }\n\n    void recalc(std::uint32_t\
    \ p) {\n        std::uint32_t length = 1;\n        while (length <<= 1, p >>=\
    \ 1) {\n            data_type lhs = reflect((p << 1) | 0, length >> 1);\n    \
    \        data_type rhs = reflect((p << 1) | 1, length >> 1);\n            _data[p]\
    \ = _monoid_x.op(lhs, rhs);\n        }\n    }\n\npublic:\n    lazy_segment_tree()\
    \ = default;\n    explicit lazy_segment_tree(const std::uint32_t& n) {\n     \
    \   build(n);\n    }\n    explicit lazy_segment_tree(const std::vector<data_type>&\
    \ v) {\n        build(v);\n    }\n    \n    void build(const std::uint32_t& n)\
    \ {\n        init(n);\n    }\n    void build(const std::vector<data_type>& v)\
    \ {\n        const std::uint32_t n = v.size();\n        init(n);\n        for\
    \ (std::uint32_t i = 0; i < n; ++i) {\n            _data[_size + i] = v[i];\n\
    \        }\n        for (std::uint32_t i = _size - 1; i > 0; --i) {\n        \
    \    _data[i] = _monoid_x.op(_data[(i << 1) | 0], _data[(i << 1) | 1]);\n    \
    \    }\n    }\n\n    void set(std::uint32_t p, const data_type& x) {\n       \
    \ assert(0 <= p && p < _size);\n        push(p += _size);\n        _data[p] =\
    \ x;\n        recalc(p);\n    }\n\n    data_type get(std::uint32_t p) {\n    \
    \    assert(0 <= p && p < _size);\n        push(p += _size);\n        return _data[p];\n\
    \    }\n\n    void apply(std::uint32_t l, std::uint32_t r, const lazy_type& x)\
    \ {\n        if (l >= r) return;\n        push(l += _size); push(r += _size -\
    \ 1);\n        std::uint32_t l0 = l, r0 = r;\n        for (++r; l < r; l >>= 1,\
    \ r >>= 1) {\n            if (l & 1) _lazy[l] = _monoid_f.op(_lazy[l], x), ++l;\n\
    \            if (r & 1) --r, _lazy[r] = _monoid_f.op(_lazy[r], x);\n\t\t}\n  \
    \      recalc(l0); recalc(r0);\n    }\n\n    data_type product(std::uint32_t l,\
    \ std::uint32_t r) {\n        if (l >= r) return _monoid_x.e();\n        push(l\
    \ += _size); push(r += _size - 1);\n        std::uint32_t length;\n        data_type\
    \ L = _monoid_x.e(), R = _monoid_x.e();\n        for (++r, length = 1; l < r;\
    \ l >>= 1, r >>= 1, length <<= 1) {\n            if (l & 1) L = _monoid_x.op(L,\
    \ reflect(l++, length));\n            if (r & 1) R = _monoid_x.op(R, reflect(--r,\
    \ length));\n\t\t}\n        return _monoid_x.op(L, R);\n    }\n\nprotected:\n\
    \    std::uint32_t _size, _level;\n    std::vector<data_type> _data;\n    std::vector<lazy_type>\
    \ _lazy;\n    const MonoidX _monoid_x = MonoidX();\n    const MonoidF _monoid_f\
    \ = MonoidF();\n    const Mapping _mapping = Mapping();\n};"
  dependsOn:
  - 02_DataStructure/02_SegmentTree/00.00_monoid.base.hpp
  isVerificationFile: false
  path: 02_DataStructure/02_SegmentTree/03_lazy-segment-tree.hpp
  requiredBy: []
  timestamp: '2021-01-10 04:49:38+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/02_DataStructure/02_SegmentTree/00.02.01_AOJ-DSL-2-F.test.cpp
documentation_of: 02_DataStructure/02_SegmentTree/03_lazy-segment-tree.hpp
layout: document
redirect_from:
- /library/02_DataStructure/02_SegmentTree/03_lazy-segment-tree.hpp
- /library/02_DataStructure/02_SegmentTree/03_lazy-segment-tree.hpp.html
title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC"
---
