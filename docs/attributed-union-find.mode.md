---
title: 属性つき Union-Find (mode)
documentation_of: ../02_DataStructure/01_UnionFind/02.03_attributed-union-find.mode.hpp
---

## 概要

| 名前 | 説明 | 計算量 |
| - | - | - |
| `union_trees(x, y)` | `x` のグループと `y` のグループを合併する | $$O(\lg{n})$$ |
| `mode(x)` | `x` のグループが含むデータの最頻値 | $$O(\alpha(n))$$ |
| `mode_count(x)` | `x` のグループが含むデータの最頻値の出現数 | $$O(\alpha(n))$$ |