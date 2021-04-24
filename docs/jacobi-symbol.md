---
title: ヤコビ記号
documentation_of: ../01_Math/02_Combinatorics/01.07_jacobi-symbol.hpp
---

## ラグランジュ記号

$p$ を素数、$\gcd(a,p)=1$ とする．次のような記号をラグランジュ記号という．

$$
\left(\frac{a}{p}\right)=\begin{cases}
+1 & a が平方剰余のとき \\
-1 & a が平方非剰余のとき
\end{cases}
$$

ただし、$\left(\frac{0}{p}\right)=0$ とする．

ラグランジュ記号は以下の性質を満たす．

- $a\equiv b\mod{p}$ ならば $\left(\frac{a}{p}\right)=\left(\frac{b}{p}\right)$
- $\left(\frac{1}{p}\right)=1$
- $\left(\frac{a}{p}\right)\left(\frac{b}{p}\right)=\left(\frac{ab}{p}\right)$
- $p$ が奇素数のとき $\left(\frac{-1}{p}\right)=(-1)^{\frac{p-1}{2}}$
- $p$ が奇素数のとき $\left(\frac{2}{p}\right)=(-1)^{\frac{p^2-1}{8}}$
- $p,q$ が相異なる奇素数のとき $\left(\frac{p}{q}\right)\left(\frac{q}{p}\right)=(-1)^{\frac{p-1}{2}\frac{q-1}{2}}$

## ヤコビ記号

ヤコビ記号はラグランジュ記号を拡張した記号である．

奇数 $m=\prod_{i}{p_{i}}^{e_{i}}>1$、$\gcd(a,m)=1$とする．ヤコビ記号 $\left(\frac{a}{m}\right)$ を次のように定義する．

$$
\left(\frac{a}{m}\right)=\prod_{i}\left(\frac{a}{p_{i}}\right)^{e_{i}}
$$

右辺の $\left(\frac{a}{p_{i}}\right)$ はラグランジュ記号である．

ヤコビ記号は以下の性質を満たす．

- $a\equiv b\mod{m}$ ならば $\left(\frac{a}{m}\right)=\left(\frac{b}{m}\right)$
- $\left(\frac{1}{m}\right)=1$
- $\left(\frac{a}{m}\right)\left(\frac{b}{m}\right)=\left(\frac{ab}{m}\right)$
- $m$ が奇数のとき $\left(\frac{-1}{m}\right)=(-1)^{\frac{m-1}{2}}$
- $m$ が奇数のとき $\left(\frac{2}{m}\right)=(-1)^{\frac{m^2-1}{8}}$
- $m,n$ が奇数のとき $\left(\frac{n}{m}\right)\left(\frac{m}{n}\right)=(-1)^{\frac{m-1}{2}\frac{q-1}{2}}$
