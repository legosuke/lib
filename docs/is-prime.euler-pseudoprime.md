---
title: 素数判定 (オイラー擬素数)
documentation_of: ../01_Math/01_NumberTheory/02.01.02_is-prime.fermer-pseudoprime.hpp
---

## 概要

オイラー規範より、$p$ が素数ならば $\gcd(a,p)=1$ となる任意の $a$ に対し $\left(\frac{a}{p}\right)\equiv a^{\frac{p-1}{2}}\mod{p}$ が成立する．この対偶は、$n$ を奇数とし、$\gcd(a,n)=1$ となるある $a$ に対し $\left(\frac{a}{n}\right)\not\equiv a^{\frac{n-1}{2}}\mod{n}$ が成立するならば $n$ は素数でない、となる．

$\left(\frac{a}{n}\right)\equiv a^{\frac{n-1}{2}}\mod{n}$ となる合成数 $n$ を $a$ を底とするオイラー擬素数という．

オイラー擬素数にはカーマイケル数のような数は存在しない．
つまり、$n$ が合成数ならば $\gcd(a,n)=1$ となる $1\le a\le n-1$ で $\left(\frac{a}{n}\right)\not\equiv a^{\frac{n-1}{2}}\mod{n}$ となるものが存在する．さらにその個数は $\frac{\phi(n)}{2}$ 個以上である．
