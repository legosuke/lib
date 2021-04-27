#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_E"
#include "../../../template/template.hpp"
#include "../../../01_Math/02_Combinatorics/01.02.01_modint.static.hpp"
#include "../../../01_Math/02_Combinatorics/02.03.01_combination.factorial+inverse.hpp"

signed main() {
    combination<modint1000000007> comb(1001);
    int n, k;
    cin >> n >> k;
    if (n > k) cout << 0 << endl;
    else cout << comb.c(k, n) << endl;
}