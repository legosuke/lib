#define PROBLEM "https://yukicoder.me/problems/no/0811"
#include "../../../template/template.hpp"
#include "../../../01_Math/01_NumberTheory/02.02.02_prime-factor.sieve.hpp"

signed main() {
    int N, K;
    cin >> N >> K;
    auto npf = prime_factor(N);
    int cntd = 0, ans = 0;
    for (int x = 2; x < N; ++x) {
        auto pf = prime_factor(x);
        map<int, int> mp;
        int cntp = 0, d = 1;
        for (auto p : pf) {
            mp[p.first] = p.second;
            d *= 1 + p.second;
        }
        for (auto p : npf) cntp += min((int)p.second, mp[p.first]);
        if (cntp < K) continue;
        if (d > cntd) {
            cntd = d;
            ans = x;
        }
    }
    cout << ans << endl;
}