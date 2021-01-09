---
data:
  libraryCategories:
  - name: 01_Math/01_NumberTheory
    pages:
    - icon: ':heavy_check_mark:'
      path: 01_Math/01_NumberTheory/01.01.01_divisor.naive.hpp
      title: "\u7D04\u6570\u5217\u6319 (\u7D20\u6734\u306A\u624B\u6CD5)"
    - icon: ':heavy_check_mark:'
      path: 01_Math/01_NumberTheory/01.02.01_gcd.hpp
      title: "\u6700\u5927\u516C\u7D04\u6570"
    - icon: ':heavy_check_mark:'
      path: 01_Math/01_NumberTheory/01.03.01_lcm.hpp
      title: "\u6700\u5C0F\u516C\u500D\u6570"
    - icon: ':heavy_check_mark:'
      path: 01_Math/01_NumberTheory/01.04.01_ext-gcd.hpp
      title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u52A9\u6CD5"
    - icon: ':heavy_check_mark:'
      path: 01_Math/01_NumberTheory/02.01.01_is-prime.naive.hpp
      title: "\u7D20\u6570\u5224\u5B9A (\u7D20\u6734\u306A\u624B\u6CD5)"
    - icon: ':heavy_check_mark:'
      path: 01_Math/01_NumberTheory/02.01.02_is-prime.fermat.hpp
      title: "\u7D20\u6570\u5224\u5B9A (\u30D5\u30A7\u30EB\u30DE\u30FC)"
    - icon: ':heavy_check_mark:'
      path: 01_Math/01_NumberTheory/02.01.03_is-prime.miller-rabin.hpp
      title: "\u7D20\u6570\u5224\u5B9A (\u30DF\u30E9\u30FC\u30FB\u30E9\u30D3\u30F3\
        )"
  - name: 01_Math/02_Combinatorics
    pages:
    - icon: ':heavy_check_mark:'
      path: 01_Math/02_Combinatorics/01.01_mod-operation.hpp
      title: "mod \u4E0A\u306E\u57FA\u672C\u6F14\u7B97"
    - icon: ':heavy_check_mark:'
      path: 01_Math/02_Combinatorics/01.02.00_modint-base.hpp
      title: "modint \u69CB\u9020\u4F53 (base)"
    - icon: ':heavy_check_mark:'
      path: 01_Math/02_Combinatorics/01.02.01_modint.static.hpp
      title: "modint \u69CB\u9020\u4F53 (\u9759\u7684 MOD)"
    - icon: ':heavy_check_mark:'
      path: 01_Math/02_Combinatorics/01.02.02_modint.dynamic.hpp
      title: "modint \u69CB\u9020\u4F53 (\u52D5\u7684 MOD)"
    - icon: ':heavy_check_mark:'
      path: 01_Math/02_Combinatorics/01.03.01_mod-pow.hpp
      title: "\u7D2F\u4E57 : $a^n\\bmod{m}$"
    - icon: ':heavy_check_mark:'
      path: 01_Math/02_Combinatorics/01.03.02_mod-pow.big-mod.hpp
      title: "\u7D2F\u4E57 : $a^n\\bmod{m}$ ($m$ \u304C\u5927\u304D\u3044\u5834\u5408\
        )"
    - icon: ':heavy_check_mark:'
      path: 01_Math/02_Combinatorics/01.04.01_mod-inv.fermat.hpp
      title: "\u9006\u5143 : $a^{-1}\\bmod{p}$ (\u30D5\u30A7\u30EB\u30DE\u30FC\u306E\
        \u5C0F\u5B9A\u7406)"
    - icon: ':heavy_check_mark:'
      path: 01_Math/02_Combinatorics/01.04.03_mod-inv.ext-gcd.hpp
      title: "\u9006\u5143 : $a^{-1}\\bmod{m}$ (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\
        \u30C3\u30C9\u306E\u4E92\u52A9\u6CD5)"
  - name: 01_Math/03_Algebra
    pages:
    - icon: ':warning:'
      path: 01_Math/03_Algebra/01.00_matrix-constants.hpp
      title: 01_Math/03_Algebra/01.00_matrix-constants.hpp
    - icon: ':heavy_check_mark:'
      path: 01_Math/03_Algebra/01.01.00_matrix-base.hpp
      title: "\u884C\u5217 (base)"
    - icon: ':heavy_check_mark:'
      path: 01_Math/03_Algebra/01.01.01.01_matrix.vector.hpp
      title: "\u884C\u5217 (vector)"
    - icon: ':warning:'
      path: 01_Math/03_Algebra/01.01.01.02_matrix.array.hpp
      title: "\u884C\u5217 (array)"
    - icon: ':warning:'
      path: 01_Math/03_Algebra/01.01.01.03_matrix.bitset.hpp
      title: "\u884C\u5217 (bitset)"
    - icon: ':warning:'
      path: 01_Math/03_Algebra/01.02.01.01_gaussian-elimination.floating-point.hpp
      title: "\u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5 (\u5B9F\u6570)"
    - icon: ':warning:'
      path: 01_Math/03_Algebra/01.02.01.02_gaussian-elimination.modp.hpp
      title: "\u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5 (mod p)"
    - icon: ':warning:'
      path: 01_Math/03_Algebra/01.02.01.03_gaussian-elimination.binary.hpp
      title: "\u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5 (\u30D0\u30A4\u30CA\u30EA\
        )"
    - icon: ':warning:'
      path: 01_Math/03_Algebra/01.02.02.01_matrix-decomposition.LU-decomposition.hpp
      title: "\u884C\u5217\u306E\u5206\u89E3 (LU \u5206\u89E3)"
    - icon: ':warning:'
      path: 01_Math/03_Algebra/01.03.01.01_matrix-rank.gaussian-elmination.hpp
      title: "\u884C\u5217\u306E\u968E\u6570 (\u30AC\u30A6\u30B9\u306E\u6D88\u53BB\
        \u6CD5)"
    - icon: ':warning:'
      path: 01_Math/03_Algebra/01.03.02.01_inverse-matrix.gaussian-elimination.hpp
      title: "\u9006\u884C\u5217 (\u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5)"
    - icon: ':warning:'
      path: 01_Math/03_Algebra/01.03.03.02_matrix-determinant.LU-decomposition.hpp
      title: "\u884C\u5217\u5F0F (LU \u5206\u89E3)"
    - icon: ':warning:'
      path: 01_Math/03_Algebra/02.01.01.01_linear-equations.gaussian-elimination.floating-point.hpp
      title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F (\u30AC\u30A6\u30B9\u306E\
        \u6D88\u53BB\u6CD5\u3001\u5B9F\u6570)"
    - icon: ':warning:'
      path: 01_Math/03_Algebra/02.01.01.02_linear-equations.gaussian-elimination.modp.hpp
      title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F (\u30AC\u30A6\u30B9\u306E\
        \u6D88\u53BB\u6CD5\u3001mod p)"
    - icon: ':warning:'
      path: 01_Math/03_Algebra/02.01.01.03_linear-equations.gaussian-elimination.binary.hpp
      title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F (\u30AC\u30A6\u30B9\u306E\
        \u6D88\u53BB\u6CD5\u3001\u30D0\u30A4\u30CA\u30EA)"
  - name: 02_DataStructure/01_UnionFind
    pages:
    - icon: ':heavy_check_mark:'
      path: 02_DataStructure/01_UnionFind/01_union-find.hpp
      title: Union-Find
    - icon: ':heavy_check_mark:'
      path: 02_DataStructure/01_UnionFind/02.01_attributed-union-find.min-max.hpp
      title: "\u5C5E\u6027\u3064\u304D Union-Find (min-max)"
    - icon: ':warning:'
      path: 02_DataStructure/01_UnionFind/02.02_attributed-union-find.sum.hpp
      title: "\u5C5E\u6027\u3064\u304D Union-Find (sum)"
    - icon: ':warning:'
      path: 02_DataStructure/01_UnionFind/02.03_attributed-union-find.mode.hpp
      title: "\u5C5E\u6027\u3064\u304D Union-Find (mode)"
    - icon: ':heavy_check_mark:'
      path: 02_DataStructure/01_UnionFind/03_potentialized-union-find.hpp
      title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union-Find"
  - name: 02_DataStructure/02_SegmentTree
    pages:
    - icon: ':heavy_check_mark:'
      path: 02_DataStructure/02_SegmentTree/00.00_monoid.base.hpp
      title: 02_DataStructure/02_SegmentTree/00.00_monoid.base.hpp
    - icon: ':heavy_check_mark:'
      path: 02_DataStructure/02_SegmentTree/00.01.01_monoid.RmQ.hpp
      title: 02_DataStructure/02_SegmentTree/00.01.01_monoid.RmQ.hpp
    - icon: ':heavy_check_mark:'
      path: 02_DataStructure/02_SegmentTree/01_segment-tree.hpp
      title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC"
  - name: 06_Others/04_Random
    pages:
    - icon: ':heavy_check_mark:'
      path: 06_Others/04_Random/01_random-number.hpp
      title: "\u4E71\u6570 (\u6570)"
    - icon: ':warning:'
      path: 06_Others/04_Random/02_random-string.hpp
      title: "\u4E71\u6570 (\u6587\u5B57\u5217)"
    - icon: ':warning:'
      path: 06_Others/04_Random/03_random-vector.hpp
      title: "\u4E71\u6570 (\u5217)"
  - name: template
    pages:
    - icon: ':heavy_check_mark:'
      path: template/template.hpp
      title: template/template.hpp
  verificationCategories:
  - name: test/01_Math/01_NumberTheory
    pages:
    - icon: ':heavy_check_mark:'
      path: test/01_Math/01_NumberTheory/01.01.01_AOJ-ITP1-3-D.test.cpp
      title: test/01_Math/01_NumberTheory/01.01.01_AOJ-ITP1-3-D.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/01_Math/01_NumberTheory/01.02.01_AOJ-ALDS1-1-B.test.cpp
      title: test/01_Math/01_NumberTheory/01.02.01_AOJ-ALDS1-1-B.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/01_Math/01_NumberTheory/01.03.01_AOJ-NTL-1-C.test.cpp
      title: test/01_Math/01_NumberTheory/01.03.01_AOJ-NTL-1-C.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/01_Math/01_NumberTheory/01.04.01_AOJ-NTL-1-E.test.cpp
      title: test/01_Math/01_NumberTheory/01.04.01_AOJ-NTL-1-E.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/01_Math/01_NumberTheory/02.01.01_AOJ-ALDS1-1-C.test.cpp
      title: test/01_Math/01_NumberTheory/02.01.01_AOJ-ALDS1-1-C.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/01_Math/01_NumberTheory/02.01.02_AOJ-ALDS1-1-C.test.cpp
      title: test/01_Math/01_NumberTheory/02.01.02_AOJ-ALDS1-1-C.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/01_Math/01_NumberTheory/02.01.03_AOJ-ALDS1-1-C.test.cpp
      title: test/01_Math/01_NumberTheory/02.01.03_AOJ-ALDS1-1-C.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/01_Math/01_NumberTheory/02.01.03_yukicoder-3030.test.cpp
      title: test/01_Math/01_NumberTheory/02.01.03_yukicoder-3030.test.cpp
  - name: test/01_Math/02_Combinatorics
    pages:
    - icon: ':heavy_check_mark:'
      path: test/01_Math/02_Combinatorics/01.02.01_AOJ-1327.test.cpp
      title: test/01_Math/02_Combinatorics/01.02.01_AOJ-1327.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/01_Math/02_Combinatorics/01.02.01_yukicoder-840.test.cpp
      title: test/01_Math/02_Combinatorics/01.02.01_yukicoder-840.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/01_Math/02_Combinatorics/01.03.01_AOJ-NTL-1-B.test.cpp
      title: test/01_Math/02_Combinatorics/01.03.01_AOJ-NTL-1-B.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/01_Math/02_Combinatorics/01.04.01_AOJ-DPL-5-E.test.cpp
      title: test/01_Math/02_Combinatorics/01.04.01_AOJ-DPL-5-E.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/01_Math/02_Combinatorics/01.04.03_AOJ-DPL-5-E.test.cpp
      title: test/01_Math/02_Combinatorics/01.04.03_AOJ-DPL-5-E.test.cpp
  - name: test/01_Math/03_Algebra
    pages:
    - icon: ':heavy_check_mark:'
      path: test/01_Math/03_Algebra/01.01.01.01_ITP1-6-D.test.cpp
      title: test/01_Math/03_Algebra/01.01.01.01_ITP1-6-D.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/01_Math/03_Algebra/01.01.01.01_ITP1-7-D.test.cpp
      title: test/01_Math/03_Algebra/01.01.01.01_ITP1-7-D.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/01_Math/03_Algebra/01.01.02.01_yukicoder-194.test.cpp
      title: test/01_Math/03_Algebra/01.01.02.01_yukicoder-194.test.cpp
  - name: test/02_DataStructure/01_UnionFind
    pages:
    - icon: ':heavy_check_mark:'
      path: test/02_DataStructure/01_UnionFind/01_AOJ-DSL-1-A.test.cpp
      title: test/02_DataStructure/01_UnionFind/01_AOJ-DSL-1-A.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/02_DataStructure/01_UnionFind/02.01_AOJ-2664.test.cpp
      title: test/02_DataStructure/01_UnionFind/02.01_AOJ-2664.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/02_DataStructure/01_UnionFind/03_AOJ-DSL-1-B.test.cpp
      title: test/02_DataStructure/01_UnionFind/03_AOJ-DSL-1-B.test.cpp
  - name: test/02_DataStructure/02_SegmentTree
    pages:
    - icon: ':heavy_check_mark:'
      path: test/02_DataStructure/02_SegmentTree/00.01.01_AOJ-DSL-2-A.test.cpp
      title: test/02_DataStructure/02_SegmentTree/00.01.01_AOJ-DSL-2-A.test.cpp
layout: toppage
---
