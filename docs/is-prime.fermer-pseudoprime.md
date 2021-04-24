---
title: 素数判定 (フェルマー擬素数)
documentation_of: ../01_Math/01_NumberTheory/02.01.02_is-prime.fermer-pseudoprime.hpp
---

## 概要

フェルマーの小定理より、$p$ が素数ならば $\gcd(a,p)=1$ となる任意の $a$ に対し $a^{p-1}\equiv1\mod{p}$ となる．この定理の対偶を考えると、$\gcd(a,n)=1$ となるある $a$ に対し $a^{n-1}\not\equiv1\mod{n}$ が成立するならば $n$ は素数でない、となる．

$a^{n-1}\equiv1\mod{n}$ となる合成数 $n$ を $a$ を底とするフェルマー擬素数という．

ただし、$\gcd(a,n)=1$ となる任意の $a$ に対して $a^{n-1}\equiv1\mod{n}$ となる合成数 $n$ が存在する．このような数をカーマイケル数という．
