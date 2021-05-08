---
title: 多次元高速フーリエ変換
documentation_of: ../01_Math/03_Algebra/04.01.03_fast-fourier-transform.multidimension.hpp
---

$d$ 次元配列 $A=(a_{j_1},a_{j_2},\ldots,a_{j_d})$ を入力として受け取る．ただし、$n=n_1n_2\cdots n_d$ である．$d$ 次元 DFT を $0\le k_1<n_1, 0\le k_2<n_2, \ldots, 0\le k_d<n_d$ に対して、

$$y_{k_1,k_2,\ldots,k_d}=\sum_{j_1=0}^{n_1-1}\sum_{j_2=0}^{n_2-1}\cdots\sum_{j_d=0}^{n_d-1}a_{j_1,j_2,\ldots,j_d}\omega_{n_1}^{j_1k_1}\omega_{n_2}^{j_2k_2}\cdots\omega_{n_d}^{j_dk_d}$$

と定義する．ここで、$\omega_{n}=e^{2\pi i/n}$ である．

### アルゴリズム

各次元に対して 1 次元 DFT を適用することで $O(n\lg{n})$ 時間で $d$ 次元 DFT を計算できる．

<details>
<summary>証明</summary>
<div>

$$
\begin{aligned}
y_{k_1,k_2,\ldots,k_d}
&=\sum_{j_1=0}^{n_1-1}\sum_{j_2=0}^{n_2-1}\cdots\sum_{j_d=0}^{n_d-1}a_{j_1,j_2,\ldots,j_d}\omega_{n_1}^{j_1k_1}\omega_{n_2}^{j_2k_2}\cdots\omega_{n_d}^{j_dk_d}\\

&=\sum_{j_2=0}^{n_2-1}\cdots\sum_{j_d=0}^{n_d-1}\sum_{j_1=0}^{n_1-1}a_{j_1,j_2,\ldots,j_d}\omega_{n_1}^{j_1k_1}\omega_{n_2}^{j_2k_2}\cdots\omega_{n_d}^{j_dk_d}\\

&=\sum_{j_2=0}^{n_2-1}\cdots\sum_{j_d=0}^{n_d-1}\left(\sum_{j_1=0}^{n_1-1}a_{j_1,j_2,\ldots,j_d}\omega_{n_1}^{j_1k_1}\right)\omega_{n_2}^{j_2k_2}\cdots\omega_{n_d}^{j_dk_d}\\
\end{aligned}
$$

ここで、$a_{j_2,\ldots,j_d}^{[1]}=\sum_{j_1=0}^{n_1-1}a_{j_1,j_2,\ldots,j_d}\omega_{n_1}^{j_1k_1}$ とすると、

$$\sum_{j_2=0}^{n_2-1}\cdots\sum_{j_d=0}^{n_d-1}a_{j_2,\ldots,j_d}^{[1]}\omega_{n_2}^{j_2k_2}\cdots\omega_{n_d}^{j_dk_d}$$

となり、$d-1$ 次元 DFT をとけばいいことになる．よって、1 次元 DFT を $d$ 回繰り返すことで $d$ 次元 DFT を計算できる．また、数式から分かるように次元の順序は任意で構わない．

$1\le k \le d$ 番目の次元における 1 次元 DFT について、DFT の対象となる長さ $n_i$ のベクトルは $n/n_i$ 個存在する．また、すべてのベクトルは $O(n)$ 時間で計算できる．アルゴリズム全体の時間計算量は、

$$
\begin{aligned}
O\left(\sum_{k=1}^{d}n+\frac{n}{n_i}\cdot n_i\lg{n_i}\right)
&=O\left(\sum_{k=1}^{d}n+n\lg{n_i}\right)\\
&=O\left(\sum_{k=1}^{d}n\lg{n_i}\right)\\
&=O\left(n\sum_{k=1}^{d}\lg{n_i}\right)\\
&=O\left(n\lg{n}\right)\\
\end{aligned}
$$

となる．

</div>
</details>