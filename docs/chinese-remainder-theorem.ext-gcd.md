---
title: 中国剰余定理 (拡張ユークリッドの互除法)
documentation_of: ../01_Math/02_Combinatorics/01.06.01_chinese-remainder-theorem.ext-gcd.hpp
---

## 中国剰余定理

どんな $r_{1},r_{2},\ldots,r_{t}$ に対しても連立合同式

$$
x\equiv\begin{cases}
    r_{1} \mod{m_{1}} \\
    r_{2} \mod{m_{2}} \\
    \ldots \\
    r_{t} \mod{m_{t}}
\end{cases}
$$

を満たす整数 $x$ が $0$ 以上 $\mathrm{lcm}(m_{1},m_{2},\ldots,m_{t})$ 未満にただ1つ存在する．

## アルゴリズム

[参考](https://qiita.com/drken/items/ae02240cd1f8edfc86fd#2-%E4%B8%AD%E5%9B%BD%E5%89%B0%E4%BD%99%E5%AE%9A%E7%90%86%E3%81%AE%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0)
