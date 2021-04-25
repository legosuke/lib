#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C"
#include "../../../template/template.hpp"
#include "../../../01_Math/01_NumberTheory/02.01.05.02_is-prime.miller-rabin.deterministic.hpp"

signed main() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ans += is_prime(x);
    }
    cout << ans << endl;
}