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
    06_Others/04_Random/03_random-vector.hpp\"\n#include <numeric>\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename T>\nstd::vector<T> random_vector_number(const\
    \ std::size_t n, const T a, const T b) {\n    std::vector<T> res(n);\n    for\
    \ (std::size_t i = 0; i < n; ++i) {\n        res[i] = random_number(a, b);\n \
    \   }\n    return res;\n}\n\ntemplate <typename T>\nvoid random_shuffle(std::vector<T>&\
    \ v) {\n    const std::size_t n = v.size();\n    for (int i = n - 1; i > 0; --i)\
    \ {\n        std::swap(v[i], v[random_number(i + 1)]);\n    }\n}\n\nstd::vector<std::uint32_t>\
    \ random_permutation(const std::uint32_t n) {\n    std::vector<std::uint32_t>\
    \ res(n);\n    std::iota(res.begin(), res.end(), 1);\n    random_shuffle(res);\n\
    \    return res;\n}\n"
  code: "#pragma once\n#include \"01_random-number.hpp\"\n#include <cassert>\n#include\
    \ <numeric>\n#include <utility>\n#include <vector>\n\ntemplate <typename T>\n\
    std::vector<T> random_vector_number(const std::size_t n, const T a, const T b)\
    \ {\n    std::vector<T> res(n);\n    for (std::size_t i = 0; i < n; ++i) {\n \
    \       res[i] = random_number(a, b);\n    }\n    return res;\n}\n\ntemplate <typename\
    \ T>\nvoid random_shuffle(std::vector<T>& v) {\n    const std::size_t n = v.size();\n\
    \    for (int i = n - 1; i > 0; --i) {\n        std::swap(v[i], v[random_number(i\
    \ + 1)]);\n    }\n}\n\nstd::vector<std::uint32_t> random_permutation(const std::uint32_t\
    \ n) {\n    std::vector<std::uint32_t> res(n);\n    std::iota(res.begin(), res.end(),\
    \ 1);\n    random_shuffle(res);\n    return res;\n}"
  dependsOn:
  - 06_Others/04_Random/01_random-number.hpp
  isVerificationFile: false
  path: 06_Others/04_Random/03_random-vector.hpp
  requiredBy: []
  timestamp: '2020-12-16 22:28:26+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: 06_Others/04_Random/03_random-vector.hpp
layout: document
redirect_from:
- /library/06_Others/04_Random/03_random-vector.hpp
- /library/06_Others/04_Random/03_random-vector.hpp.html
title: 06_Others/04_Random/03_random-vector.hpp
---
