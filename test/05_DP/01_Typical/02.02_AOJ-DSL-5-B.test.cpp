#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_5_B"
#include "../../../template/template.hpp"
#include "../../../05_DP/01_Typical/02.02_imos-2d.hpp"

signed main() {
    int N;
    cin >> N;
    auto cnt = imos_2d<int>(1010, 1010);
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cnt.add(y1, x1, y2, x2, 1);
    }
    cnt.build();
    int ans = 0;
    for (int i = 0; i < 1010; ++i) {
        for (int j = 0; j < 1010; ++j) {
            ans = max(ans, cnt[i][j]);
        }
    }
    cout << ans << endl;
}