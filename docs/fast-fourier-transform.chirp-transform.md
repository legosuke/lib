---
title: チャープ変換
documentation_of: ../01_Math/03_Algebra/04.01.02_fast-fourier-transform.chirp-transform.hpp
---

## 概要

長さ $n$ のベクトル $a=(a_{0},a_{1},\ldots,a_{n-1})$ のチャープ変換をベクトル $y=(y_0,y_1,\ldots,y_{n-1})$ とする．
ただし、$y_k=\sum_{j=0}^{n-1}a_jz^{kj}$ であり、$z$ は任意の複素数である．
$z=e^{2\pi i/n}$ のとき DFT になる．

## アルゴリズム

$$y_k=\sum_{j=0}^{n-1}a_jz^{kj}$$

を式変形すると

$$y_k=z^{k^2/2}\sum_{j=0}^{n-1}(a_jz^{j^2/2})(z^{-(k-j)^2/2})$$

となり、畳み込みの形になる．

多項式 $P(x),Q(x)$ を次のように定義する．

$$
\begin{aligned}
P(x)&=\sum_{j=0}^{n-1}a_jz^{j^2/2}x^j\\
Q(x)&=\sum_{j=0}^{2n-2}z^{-(n-1-j)^2/2}x^j
\end{aligned}
$$

ここで、$P(x)Q(x)=\sum_{j=0}^{3n-3}r_j$ とすると、$y_k=z^{k^2/2}r_{k+n-1}$ となる．

$z^{\pm0^2/2},z^{\pm1^2/2},\ldots,z^{\pm(n-1)^2/2}$ は $O(n)$ 時間、$P(x)Q(x)$ の計算は $O(n\lg{n})$ 時間かかるので、全体で $O(n\lg{n})$ 時間となる．