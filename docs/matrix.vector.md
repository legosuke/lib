---
title: 行列 (vector)
documentation_of: ../01_Math/03_Algebra/01.01.01.01_matrix.vector.hpp
---

## `class T` の要件

- `template <typename Integer> T& operator = (const Integer&)` が定義されている．
- `op = +, -, *, /` について、`T op T` が定義されている．
- `operator <<` が定義されている．