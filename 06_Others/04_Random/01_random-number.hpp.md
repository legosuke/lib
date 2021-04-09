---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: 01_Math/01_NumberTheory/02.01.02_is-prime.fermat.hpp
    title: "\u7D20\u6570\u5224\u5B9A (\u30D5\u30A7\u30EB\u30DE\u30FC)"
  - icon: ':heavy_check_mark:'
    path: 01_Math/01_NumberTheory/02.01.03_is-prime.miller-rabin.hpp
    title: "\u7D20\u6570\u5224\u5B9A (\u30DF\u30E9\u30FC\u30FB\u30E9\u30D3\u30F3)"
  - icon: ':heavy_check_mark:'
    path: 01_Math/01_NumberTheory/02.02.03_prime-factor.rho.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3 (\u30ED\u30FC\u6CD5)"
  - icon: ':warning:'
    path: 06_Others/04_Random/02_random-string.hpp
    title: "\u4E71\u6570 (\u6587\u5B57\u5217)"
  - icon: ':warning:'
    path: 06_Others/04_Random/03_random-vector.hpp
    title: "\u4E71\u6570 (\u5217)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/01_Math/01_NumberTheory/02.01.02_AOJ-ALDS1-1-C.test.cpp
    title: test/01_Math/01_NumberTheory/02.01.02_AOJ-ALDS1-1-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/01_Math/01_NumberTheory/02.01.03_AOJ-ALDS1-1-C.test.cpp
    title: test/01_Math/01_NumberTheory/02.01.03_AOJ-ALDS1-1-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/01_Math/01_NumberTheory/02.01.03_yukicoder-3030.test.cpp
    title: test/01_Math/01_NumberTheory/02.01.03_yukicoder-3030.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/01_Math/01_NumberTheory/02.02.03_LC-factorize.test.cpp
    title: test/01_Math/01_NumberTheory/02.02.03_LC-factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E71\u6570 (\u6570)"
    links: []
  bundledCode: "#line 2 \"06_Others/04_Random/01_random-number.hpp\"\n#include <cassert>\n\
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
  path: 06_Others/04_Random/01_random-number.hpp
  requiredBy:
  - 06_Others/04_Random/03_random-vector.hpp
  - 06_Others/04_Random/02_random-string.hpp
  - 01_Math/01_NumberTheory/02.02.03_prime-factor.rho.hpp
  - 01_Math/01_NumberTheory/02.01.02_is-prime.fermat.hpp
  - 01_Math/01_NumberTheory/02.01.03_is-prime.miller-rabin.hpp
  timestamp: '2020-12-17 21:19:56+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/01_Math/01_NumberTheory/02.02.03_LC-factorize.test.cpp
  - test/01_Math/01_NumberTheory/02.01.03_AOJ-ALDS1-1-C.test.cpp
  - test/01_Math/01_NumberTheory/02.01.02_AOJ-ALDS1-1-C.test.cpp
  - test/01_Math/01_NumberTheory/02.01.03_yukicoder-3030.test.cpp
documentation_of: 06_Others/04_Random/01_random-number.hpp
layout: document
redirect_from:
- /library/06_Others/04_Random/01_random-number.hpp
- /library/06_Others/04_Random/01_random-number.hpp.html
title: "\u4E71\u6570 (\u6570)"
---
