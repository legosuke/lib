---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: 06_Others/04_Random/01_random-number.hpp
    title: "\u4E71\u6570 (\u6570)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4E71\u6570 (\u5217)"
    links: []
  bundledCode: "#line 2 \"06_Others/04_Random/03_random-vector.hpp\"\n#include <cstdint>\n\
    #include <numeric>\n#include <utility>\n#include <vector>\n#line 2 \"06_Others/04_Random/01_random-number.hpp\"\
    \n#include <cassert>\n#include <chrono>\n#include <random>\n#include <type_traits>\n\
    \nstruct Random {\n    std::mt19937_64 mt;\n    Random() { mt.seed(std::chrono::steady_clock::now().time_since_epoch().count());\
    \ }\n} rnd;\n\n/**\n * @brief \u4E71\u6570 (\u6570)\n * @note O(1)\n */\ntemplate\
    \ <typename T>\nT random_number(const T a, const T b) {\n    assert(a < b);\n\
    \    if (std::is_integral<T>::value) {\n        std::uniform_int_distribution<T>\
    \ dist(a, b - 1);\n        return dist(rnd.mt);\n    } else {\n        std::uniform_real_distribution<>\
    \ dist(a, b);\n        return dist(rnd.mt);\n    }\n}\n\n/**\n * @note O(1)\n\
    \ */\ntemplate <typename T>\nT random_number(const T b) {\n    return random_number(T(0),\
    \ b);\n}\n#line 7 \"06_Others/04_Random/03_random-vector.hpp\"\n\n/**\n * @brief\
    \ \u4E71\u6570 (\u5217)\n * @note O(n)\n */\ntemplate <typename T>\nstd::vector<T>\
    \ random_vector_number(const std::uint32_t n, const T a, const T b) {\n    std::vector<T>\
    \ res(n);\n    for (std::uint32_t i = 0; i < n; ++i) {\n        res[i] = random_number(a,\
    \ b);\n    }\n    return res;\n}\n\n/**\n * @note O(|v|)\n */\ntemplate <typename\
    \ T>\nvoid random_shuffle(std::vector<T>& v) {\n    const std::uint32_t n = v.size();\n\
    \    for (int i = n - 1; i > 0; --i) {\n        std::swap(v[i], v[random_number(i\
    \ + 1)]);\n    }\n}\n\n/**\n * @note O(n)\n */\nstd::vector<std::uint32_t> random_permutation(const\
    \ std::uint32_t n) {\n    std::vector<std::uint32_t> res(n);\n    std::iota(res.begin(),\
    \ res.end(), 1);\n    random_shuffle(res);\n    return res;\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <numeric>\n#include <utility>\n\
    #include <vector>\n#include \"01_random-number.hpp\"\n\n/**\n * @brief \u4E71\u6570\
    \ (\u5217)\n * @note O(n)\n */\ntemplate <typename T>\nstd::vector<T> random_vector_number(const\
    \ std::uint32_t n, const T a, const T b) {\n    std::vector<T> res(n);\n    for\
    \ (std::uint32_t i = 0; i < n; ++i) {\n        res[i] = random_number(a, b);\n\
    \    }\n    return res;\n}\n\n/**\n * @note O(|v|)\n */\ntemplate <typename T>\n\
    void random_shuffle(std::vector<T>& v) {\n    const std::uint32_t n = v.size();\n\
    \    for (int i = n - 1; i > 0; --i) {\n        std::swap(v[i], v[random_number(i\
    \ + 1)]);\n    }\n}\n\n/**\n * @note O(n)\n */\nstd::vector<std::uint32_t> random_permutation(const\
    \ std::uint32_t n) {\n    std::vector<std::uint32_t> res(n);\n    std::iota(res.begin(),\
    \ res.end(), 1);\n    random_shuffle(res);\n    return res;\n}"
  dependsOn:
  - 06_Others/04_Random/01_random-number.hpp
  isVerificationFile: false
  path: 06_Others/04_Random/03_random-vector.hpp
  requiredBy: []
  timestamp: '2020-12-20 23:40:08+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: 06_Others/04_Random/03_random-vector.hpp
layout: document
redirect_from:
- /library/06_Others/04_Random/03_random-vector.hpp
- /library/06_Others/04_Random/03_random-vector.hpp.html
title: "\u4E71\u6570 (\u5217)"
---
