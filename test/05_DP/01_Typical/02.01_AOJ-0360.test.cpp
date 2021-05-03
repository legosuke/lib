#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0360"
#include "../../../template/template.hpp"
#include "../../../05_DP/01_Typical/02.01_imos-1d.hpp"

signed main() {
    int a, b, n;
    cin >> a >> b >> n;
    auto cnt = imos_1d<int>(1000);
    cnt.add(a, b, 1);
    for (int i = 0; i < n; ++i) {
        int s, f;
        cin >> s >> f;
        cnt.add(s, f, 1);
    }
    for (int i = 0; i < 1000; ++i) {
        if (cnt[i] <= 1) continue;
        cout << 1 << endl;
        return 0;
    }
    cout << 0 << endl;
}