#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C"
#include "template/template.hpp"
#include "../../../01_Math/01_NumberTheory/01.03.01_lcm.hpp"

signed main() {
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ans = lcm(ans, a);
    }
    cout << ans << endl;
}