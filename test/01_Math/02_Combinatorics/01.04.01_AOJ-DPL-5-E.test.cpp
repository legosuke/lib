#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E"
#include "../../../template/template.hpp"
#include "../../../01_Math/02_Combinatorics/01.04.01_mod-inv.fermat.hpp"

signed main() {
    int n, k; cin >> n >> k;
    if (n > k) {
        cout << 0 << endl;
        return 0;
    }
    const int MOD = 1000000007;
    int ans = 1;
    for (int i = 1; i <= k; ++i) (ans *= i) %= MOD;
    for (int i = 1; i <= n; ++i) (ans *= mod_inv(i, MOD)) %= MOD;
    for (int i = 1; i <= k - n; ++i) (ans *= mod_inv(i, MOD)) %= MOD;
    cout << ans << endl;
} 