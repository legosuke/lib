---
title: 中国剰余定理 (Gauss)
documentation_of: ../01_Math/02_Combinatorics/01.06.02_chinese-remainder-theorem.gauss.hpp
---

## 中国剰余定理

$m_{1},m_{2},\ldots,m_{t}$ のどの2つも互いに素ならば、どんな $r_{1},r_{2},\ldots,r_{t}$ に対しても連立合同式

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

$$M=\prod_{i=1}^{t}m_{i}$$

とし、すべての $1\le i\le t$ について、

$$M_{i}=M/m_{i}$$

$$l_{i}M_{i}=1\mod{m_{i}}$$

とすると、

$$x\equiv \sum_{i=1}^{t}r_{i}l_{i}M_{i}\mod{M}$$

が答えになる．