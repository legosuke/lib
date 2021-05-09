次数上界が $n$ の多項式 $A(n)$ に対して、第 $t$ 導関数を

$$
A^{(t)}(x)=\begin{cases}
A(x) & t = 0\\
\frac{d}{dx}A^{(t-1)}(x) & 1\le t\le n-1\\
0 & t\ge n
\end{cases}
$$

と定義する．$A(x)$ の係数表現を $(a_0,a_1,\ldots,a_{n-1})$ と点 $x_0$ が与えられたとき、$t=0,1,\ldots,n-1$ に対する $A^{(t)}(x_0)$ を $O(n\lg{n})$ 時間で計算する．

## アルゴリズム

$A(x)=\sum_{r=0}^{n-1}b_r(x-x_0)^r$ とすると、$A^{(t)}(x_0)=b_t\cdot t!$ となる．ここで、$k=0,1,\ldots,n-1$ に対して $A(x_0+\omega_n^k)$ は、

$$A(x_0+\omega_n^k)=\sum_{j=0}^{n-1}b_j\omega_n^{kj}$$

となる．ただし、$\omega_n=e^{2\pi i/n}$ である．$A(x_0+\omega_n^k)$ を別の方法で計算すると次の式で表せる．

$$
\begin{aligned}
A(x_0+\omega_n^k)&=\sum_{j=0}^{n-1}\left(\frac{\omega_n^{kj}}{j!}\sum_{m=0}^{n-1}f(m)g(j-m)\right)\\
f(m)&=a_s\cdot m!\\
g(l)&=\begin{cases}
x_0^{-l}/(-l)! & -(n-1)\le l\le 0\\
0 & 1\le l\le n-1
\end{cases}
\end{aligned}
$$

<details>
<summary>証明</summary>
<div>

$h(x)=\begin{cases}1 & x\ge0\\ 0 & x<0\end{cases}$ とする．

$$
\begin{aligned}
A(x_0+\omega_n^k)
&=\sum_{m=0}^{n-1}a_s(x_0+w_n^k)^m\\
&=\sum_{m=0}^{n-1}a_s\sum_{r=0}^{m}{}_sC_j\omega_n^{kj}x_0^{m-j}\\
&=\sum_{m=0}^{n-1}a_s\sum_{j=0}^{m}\frac{m!}{j!(m-j)!}\omega_n^{kj}x_0^{m-j}\\
&=\sum_{m=0}^{n-1}a_s\sum_{j=0}^{n-1}\frac{m!}{j!(m-j)!}\omega_n^{kj}x_0^{m-j}h(m-j)\\
&=\sum_{j=0}^{n-1}\frac{\omega_n^{kj}}{j!}\sum_{m=0}^{n-1}a_ss!\frac{x_0^{m-j}h(m-j)}{(m-j)!}\\
&=\sum_{j=0}^{n-1}\frac{\omega_n^{kj}}{j!}\sum_{m=0}^{n-1}f(m)g(j-m)\\
\end{aligned}
$$

</div>
</details>

多項式 $P(x),Q(x)$ を次のように定義する．

$$
\begin{aligned}
P(x)&=\sum_{j=0}^{n-1}f(j)x^j\\
Q(x)&=\sum_{j=0}^{2n-2}g(j-n+1)x^j\\
\end{aligned}
$$

$R(x)=P(x)Q(x)=\sum_{j=0}^{3n-3}r_jx^j$ とする．このとき任意の $0\le m<n$ について、

$$
\begin{aligned}
r_{j+n-1}&=\sum_{m=0}^{j+n-1}f(m)g(j-m)\\
&=\sum_{m=0}^{n-1}f(m)g(j-m)
\end{aligned}
$$

よって、

$$
\begin{aligned}
A(x_0+\omega_n^k)&=\sum_{j=0}^{n-1}\left(\frac{\omega_n^{kj}}{j!}\sum_{m=0}^{n-1}f(m)g(j-m)\right)\\
&=\sum_{j=0}^{n-1}\frac{r_{j+n-1}}{j!}\omega_n^{kj}\\
\end{aligned}
$$

以上より、$b_j=r_{j+n-1}/j!$ となる．
$P(x),Q(x)$ は $O(n)$ 時間で計算でき、$r_{n-1},r_{n},\ldots,r_{2n-2}$ は高速フーリエ変換により $O(n\lg{n})$ 時間で計算できる．ある $0\le t\le n-1$ に対する $A^{(t)}(x_0)$ は

$$
\begin{aligned}
A^{(t)}(x_0)&=b_t\cdot t!\\
&=(r_{t+n-1}/t!)\cdot t!\\
&=r_{t+n-1}
\end{aligned}
$$

となり $O(1)$ 時間で計算できる．以上より、アルゴリズム全体の計算時間は $O(n\lg{n})$ となる．