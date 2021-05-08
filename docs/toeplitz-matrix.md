---
title: Toeplitz 行列
documentation_of: ../01_Math/03_Algebra/01.01.02.01_toeplitz-matrix.hpp
---

$n\times n$ 行列 $A=(a_{i,j})$ が任意の $1\le i,j< n$ において、$a_{i,j}=a_{i-1,j-1}$ を満たすとき、Toeplitz 行列であるという．

### 2 つの Toeplitz 行列の和

行列 $A$ をベクトル $(a_{n-1,0},a_{n-2,0},\ldots,a_{1,0},a_{0,0},a_{0,1},\ldots,a_{n-1,n-1})$ で表す．
2 つの $n\times n$ 型 Toeplitz 行列 $A,B$ の和は $O(n)$ 時間で計算できる．

### Toeplitz 行列とベクトルの積

入力ベクトルを $(b_0,\ldots,b_{n-1})$、行列 $A$ のベクトル表現を $(c_0,\ldots,c_{2n-2})$ とする．
多項式 $P(x),Q(x)$ を次のように定義する．

$$
\begin{aligned}
P(x)&=\sum_{j=0}^{n-1}b_jx^j\\
Q(x)&=\sum_{j=0}^{2n-2}c_{2n-2-j}x^j
\end{aligned}
$$

$R(x)=P(x)Q(x)=\sum_{j=0}^{3n-3}r_jx^j$ とする．このとき任意の $0\le k<n$ について、

$$
\begin{aligned}
r_{k+n-1}=\sum_{j=0}^{n-1}b_jc_{2n-2-(k-j)}
\end{aligned}
$$

が成り立つ．$P(x)Q(x)$ は $O(n\lg{n})$ 時間で計算できるので、$r_{n-1},r_{n},\ldots,r_{2n-2}$ は $O(n\lg{n})$ 時間で計算できる．

### 2 つの Toeplitz 行列の積

Toeplitz 行列とベクトルの積を $O(n\lg{n})$ 時間で計算できるので、行列の積は $O(n^2\lg{n})$ 時間で計算できる．

工夫をすることで $O(n^2)$ 時間で計算できる．行列 $A,B$ のベクトル表現をそれぞれ $(a_{0},\ldots,a_{2n-2}),(b_{0},\ldots,b_{2n-2})$ とする．$A$ の $i$ 行目は $(a_{n-1-i},a_{n-i},\ldots,a_{2n-2-i})$ であり、$B$ の $j$ 列目は $(b_{j+n-1},b_{j+n-2},\ldots,b_{j})$ となる．$C=AB=(c_{i,j})$ とする．

$$
\begin{aligned}
c_{i,j}
&=\sum_{k=0}^{n-1}a_{n-1-i+k}b_{j+n-1-k}\\
&=a_{n-1-i}b_{j+n-1}+a_{n-i}b_{j+n-2}+\cdots+a_{2n-3-i}b_{j+1}+a_{2n-2-i}b_{j}\\
c_{i+1,j+1}
&=\sum_{k=0}^{n-1}a_{n-2-i+k}b_{j+n-k}\\
&=a_{n-2-i}b_{j+n}+a_{n-1-i}b_{j+n-1}+\cdots+a_{2n-2-i}b_{j}+a_{2n-1-i}b_{j-1}\\
&=c_{i,j}+a_{n-2-i}b_{j+n}-a_{2n-2-i}b_{j}
\end{aligned}
$$

$c_{n-1,0},c_{n-2,0},\ldots,c_{1,0},c_{0,0},c_{0,1},\ldots,c_{n-1,n-1}$ の計算に $O(n^2)$ 時間、それ以外のマスは 1 マスごとに $O(1)$ 時間で計算できるので全体で $O(n^2)$ 時間．