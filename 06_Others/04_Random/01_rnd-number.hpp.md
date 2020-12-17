---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: 01_Math/01_NumberTheory/02.01.02_is-prime.fermat.hpp
    title: "\u7D20\u6570\u5224\u5B9A (\u30D5\u30A7\u30EB\u30DE\u30FC)"
  - icon: ':warning:'
    path: 06_Others/04_Random/02_rnd-string.hpp
    title: "\u4E71\u6570 (\u6587\u5B57\u5217)"
  - icon: ':warning:'
    path: 06_Others/04_Random/03_rnd-vector.hpp
    title: "\u4E71\u6570 (\u5217)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/01_Math/01_NumberTheory/02.01.02_AOJ-ALDS1-1-C.test.cpp
    title: test/01_Math/01_NumberTheory/02.01.02_AOJ-ALDS1-1-C.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u4E71\u6570 (\u6570)"
    links: []
  bundledCode: "#line 2 \"06_Others/04_Random/01_rnd-number.hpp\"\n#include <cassert>\n\
    #include <chrono>\n#include <random>\n#include <type_traits>\n\nstruct Random\
    \ {\n    std::mt19937_64 mt;\n    Random() { mt.seed(std::chrono::steady_clock::now().time_since_epoch().count());\
    \ }\n} rnd;\n\n/**\n * @brief \u4E71\u6570 (\u6570)\n * @note O(1)\n */\ntemplate\
    \ <typename T>\nT random_number(const T a, const T b) {\n    assert(a < b);\n\
    \    if (std::is_integral<T>::value) {\n        std::uniform_int_distribution<T>\
    \ dist(a, b - 1);\n        return dist(rnd.mt);\n    } else {\n        std::uniform_real_distribution<>\
    \ dist(a, b);\n        return dist(rnd.mt);\n    }\n}\n\n/**\n * @note O(1)\n\
    \ */\ntemplate <typename T>\nT random_number(const T b) {\n    return random_number(T(0),\
    \ b);\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <chrono>\n#include <random>\n\
    #include <type_traits>\n\nstruct Random {\n    std::mt19937_64 mt;\n    Random()\
    \ { mt.seed(std::chrono::steady_clock::now().time_since_epoch().count()); }\n\
    } rnd;\n\n/**\n * @brief \u4E71\u6570 (\u6570)\n * @note O(1)\n */\ntemplate <typename\
    \ T>\nT random_number(const T a, const T b) {\n    assert(a < b);\n    if (std::is_integral<T>::value)\
    \ {\n        std::uniform_int_distribution<T> dist(a, b - 1);\n        return\
    \ dist(rnd.mt);\n    } else {\n        std::uniform_real_distribution<> dist(a,\
    \ b);\n        return dist(rnd.mt);\n    }\n}\n\n/**\n * @note O(1)\n */\ntemplate\
    \ <typename T>\nT random_number(const T b) {\n    return random_number(T(0), b);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: 06_Others/04_Random/01_rnd-number.hpp
  requiredBy:
  - 06_Others/04_Random/02_rnd-string.hpp
  - 06_Others/04_Random/03_rnd-vector.hpp
  - 01_Math/01_NumberTheory/02.01.02_is-prime.fermat.hpp
  timestamp: '2020-12-17 01:14:01+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/01_Math/01_NumberTheory/02.01.02_AOJ-ALDS1-1-C.test.cpp
documentation_of: 06_Others/04_Random/01_rnd-number.hpp
layout: document
redirect_from:
- /library/06_Others/04_Random/01_rnd-number.hpp
- /library/06_Others/04_Random/01_rnd-number.hpp.html
title: "\u4E71\u6570 (\u6570)"
---