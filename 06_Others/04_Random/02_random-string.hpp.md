---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: 06_Others/04_Random/01_random-number.hpp
    title: 06_Others/04_Random/01_random-number.hpp
  _extendedRequiredBy: []
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
    T random_number(const T b) {\n    return random_number(T(0), b);\n}\n#line 4 \"\
    06_Others/04_Random/02_random-string.hpp\"\n#include <cstring>\n\nstd::string\
    \ random_string_by_charset(const std::size_t n, const std::string cs) {\n    const\
    \ auto sz = cs.size();\n    std::string res;\n    for (std::size_t i = 0; i <\
    \ n; ++i) {\n        res += cs[random_number(sz)];\n    }\n    return res;\n}\n\
    \nstd::string random_string(const std::size_t n) {\n    const std::string cs =\
    \ \"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\";\n    return random_string_by_charset(n,\
    \ cs);\n}\n\nstd::string random_upper_string(const std::size_t n) {\n    const\
    \ std::string cs = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\";\n    return random_string_by_charset(n,\
    \ cs);\n}\n\nstd::string random_lower_string(const std::size_t n) {\n    const\
    \ std::string cs = \"abcdefghijklmnopqrstuvwxyz\";\n    return random_string_by_charset(n,\
    \ cs);\n}\n\nstd::string random_digit(const std::size_t n) {\n    const std::string\
    \ cs = \"012345689\";\n    return random_string_by_charset(n, cs);\n}\n"
  code: "#pragma once\n#include \"01_random-number.hpp\"\n#include <cassert>\n#include\
    \ <cstring>\n\nstd::string random_string_by_charset(const std::size_t n, const\
    \ std::string cs) {\n    const auto sz = cs.size();\n    std::string res;\n  \
    \  for (std::size_t i = 0; i < n; ++i) {\n        res += cs[random_number(sz)];\n\
    \    }\n    return res;\n}\n\nstd::string random_string(const std::size_t n) {\n\
    \    const std::string cs = \"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\"\
    ;\n    return random_string_by_charset(n, cs);\n}\n\nstd::string random_upper_string(const\
    \ std::size_t n) {\n    const std::string cs = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\"\
    ;\n    return random_string_by_charset(n, cs);\n}\n\nstd::string random_lower_string(const\
    \ std::size_t n) {\n    const std::string cs = \"abcdefghijklmnopqrstuvwxyz\"\
    ;\n    return random_string_by_charset(n, cs);\n}\n\nstd::string random_digit(const\
    \ std::size_t n) {\n    const std::string cs = \"012345689\";\n    return random_string_by_charset(n,\
    \ cs);\n}"
  dependsOn:
  - 06_Others/04_Random/01_random-number.hpp
  isVerificationFile: false
  path: 06_Others/04_Random/02_random-string.hpp
  requiredBy: []
  timestamp: '2020-12-16 22:28:26+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: 06_Others/04_Random/02_random-string.hpp
layout: document
redirect_from:
- /library/06_Others/04_Random/02_random-string.hpp
- /library/06_Others/04_Random/02_random-string.hpp.html
title: 06_Others/04_Random/02_random-string.hpp
---
