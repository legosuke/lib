---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: 06_Others/04_Random/02_random-string.hpp
    title: 06_Others/04_Random/02_random-string.hpp
  - icon: ':warning:'
    path: 06_Others/04_Random/03_random-vector.hpp
    title: 06_Others/04_Random/03_random-vector.hpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"06_Others/04_Random/01_random-number.hpp\"\n#include <cassert>\n\
    #include <chrono>\n#include <cstdint>\n#include <random>\n\nstruct Random {\n\
    \    std::mt19937_64 mt;\n    Random() { mt.seed(std::chrono::steady_clock::now().time_since_epoch().count());\
    \ }\n} rnd;\n\ntemplate <typename T>\nT random_number(const T a, const T b) {\n\
    \    assert(a < b);\n    if (std::is_integral<T>::value) {\n        std::uniform_int_distribution<T>\
    \ dist(a, b - 1);\n        return dist(rnd.mt);\n    } else {\n        std::uniform_real_distribution<>\
    \ dist(a, b);\n        return dist(rnd.mt);\n    }\n}\n\ntemplate <typename T>\n\
    T random_number(const T b) {\n    return random_number(T(0), b);\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <chrono>\n#include <cstdint>\n\
    #include <random>\n\nstruct Random {\n    std::mt19937_64 mt;\n    Random() {\
    \ mt.seed(std::chrono::steady_clock::now().time_since_epoch().count()); }\n} rnd;\n\
    \ntemplate <typename T>\nT random_number(const T a, const T b) {\n    assert(a\
    \ < b);\n    if (std::is_integral<T>::value) {\n        std::uniform_int_distribution<T>\
    \ dist(a, b - 1);\n        return dist(rnd.mt);\n    } else {\n        std::uniform_real_distribution<>\
    \ dist(a, b);\n        return dist(rnd.mt);\n    }\n}\n\ntemplate <typename T>\n\
    T random_number(const T b) {\n    return random_number(T(0), b);\n}"
  dependsOn: []
  isVerificationFile: false
  path: 06_Others/04_Random/01_random-number.hpp
  requiredBy:
  - 06_Others/04_Random/02_random-string.hpp
  - 06_Others/04_Random/03_random-vector.hpp
  timestamp: '2020-12-16 22:28:26+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: 06_Others/04_Random/01_random-number.hpp
layout: document
redirect_from:
- /library/06_Others/04_Random/01_random-number.hpp
- /library/06_Others/04_Random/01_random-number.hpp.html
title: 06_Others/04_Random/01_random-number.hpp
---
