---
title: 素数判定 (オイラー擬素数)
documentation_of: ../01_Math/01_NumberTheory/02.01.04_is-prime.strong-pseudoprime.hpp
---

## 概要

$p$ を素数とし、$p-1=2^{s}d\ (\gcd(2,d)=1)$ とする．
$\gcd(a,p)=1$ となる任意の $a$ に対し次のいずれかが成立する．
- $a^{d}\equiv1\mod{p}$
- ある $t\ (0\le t\le s-1)$ が存在して $a^{2^{t}}d\equiv-1\mod{p}$

対偶をとると、奇数 $n$ に対し $n-1=2^{s}d\ (\gcd(2,d)=1)$ とする．
このとき、ある $a\ (\gcd(a,n)=1)$ が存在して $a^{d}\not\equiv1\mod{n}$ かつ任意の $t\ (0\le t\le s-1)$ に対し $a^{2^{t}}d\not\equiv-1\mod{n}$ となるならば $n$ は素数でない、となる．
