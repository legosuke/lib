#define PROBLEM "https://yukicoder.me/problems/123"
#include "../../../template/template.hpp"
#include "../../../05_DP/01_Typical/02.02_imos-2d.hpp"

signed main() {
    int N, K;
    cin >> N >> K;
    auto hp = imos_2d<int>(2010, 2010);
    for (int i = 0; i < N; ++i) {
        int X, Y, HP;
        cin >> X >> Y >> HP;
        X += 500; Y += 500;
        hp.add(Y, X, Y + 1, X + 1, HP);
    }
    for (int i = 0; i < K; ++i) {
        int AX, AY, W, H, D;
        cin >> AX >> AY >> W >> H >> D;
        AX += 500; AY += 500;
        hp.add(AY, AX, AY + H + 1, AX + W + 1, -D);
    }
    hp.build();
    int ans = 0;
    for (int i = 0; i < 2010; ++i) {
        for (int j = 0; j < 2010; ++j) {
            ans += max(0L, hp[i][j]);
        }
    }
    cout << ans;
}