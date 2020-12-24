#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B"
#include "../../../template/template.hpp"
#include "../../../01_Math/02_Combinatorics/01.03.01_mod-pow.hpp"

signed main() {
    int m, n; cin >> m >> n;
    cout << mod_pow(m, n, 1000000007) << endl;
} 