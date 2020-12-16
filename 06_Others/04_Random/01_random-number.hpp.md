---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: 01_Math/01_NumberTheory/02.01.02_is-prime.fermat.hpp
    title: "\u7D20\u6570\u5224\u5B9A (\u30D5\u30A7\u30EB\u30DE\u30FC)"
  - icon: ':warning:'
    path: 06_Others/04_Random/02_random-string.hpp
    title: "\u4E71\u6570 (\u6587\u5B57\u5217)"
  - icon: ':warning:'
    path: 06_Others/04_Random/03_random-vector.hpp
    title: "\u4E71\u6570 (\u5217)"
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4E71\u6570 (\u6570)"
    links: []
  bundledCode: "#line 2 \"06_Others/04_Random/01_random-number.hpp\"\n#include <cassert>\n\
    #include <chrono>\n#include <cstdint>\n#include <random>\n\nstruct Random {\n\
    \    std::mt19937_64 mt;\n    Random() { mt.seed(std::chrono::steady_clock::now().time_since_epoch().count());\
    \ }\n} rnd;\n\n/**\n * @brief \u4E71\u6570 (\u6570)\n * @note O(1)\n */\ntemplate\
    \ <typename T>\nT random_number(const T a, const T b) {\n    assert(a < b);\n\
    \    if (std::is_integral<T>::value) {\n        std::uniform_int_distribution<T>\
    \ dist(a, b - 1);\n        return dist(rnd.mt);\n    } else {\n        std::uniform_real_distribution<>\
    \ dist(a, b);\n        return dist(rnd.mt);\n    }\n}\n\n/**\n * @note O(1)\n\
    \ */\ntemplate <typename T>\nT random_number(const T b) {\n    return random_number(T(0),\
    \ b);\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <chrono>\n#include <cstdint>\n\
    #include <random>\n\nstruct Random {\n    std::mt19937_64 mt;\n    Random() {\
    \ mt.seed(std::chrono::steady_clock::now().time_since_epoch().count()); }\n} rnd;\n\
    \n/**\n * @brief \u4E71\u6570 (\u6570)\n * @note O(1)\n */\ntemplate <typename\
    \ T>\nT random_number(const T a, const T b) {\n    assert(a < b);\n    if (std::is_integral<T>::value)\
    \ {\n        std::uniform_int_distribution<T> dist(a, b - 1);\n        return\
    \ dist(rnd.mt);\n    } else {\n        std::uniform_real_distribution<> dist(a,\
    \ b);\n        return dist(rnd.mt);\n    }\n}\n\n/**\n * @note O(1)\n */\ntemplate\
    \ <typename T>\nT random_number(const T b) {\n    return random_number(T(0), b);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: 06_Others/04_Random/01_random-number.hpp
  requiredBy:
  - 06_Others/04_Random/02_random-string.hpp
  - 06_Others/04_Random/03_random-vector.hpp
  - 01_Math/01_NumberTheory/02.01.02_is-prime.fermat.hpp
  timestamp: '2020-12-16 23:31:47+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: 06_Others/04_Random/01_random-number.hpp
layout: document
redirect_from:
- /library/06_Others/04_Random/01_random-number.hpp
- /library/06_Others/04_Random/01_random-number.hpp.html
title: "\u4E71\u6570 (\u6570)"
---
