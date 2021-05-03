#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "../../../template/template.hpp"
#include "../../../01_Math/01_NumberTheory/02.02.03_prime-factor.rho.hpp"

signed main() {
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int a;
        cin >> a;
        auto pf = prime_factor(a);
        sort(pf.begin(), pf.end());
        int k = 0;
        for (auto p : pf) k += p.second;
        cout << k;
        for (auto p : pf) {
            for (int i = 0; i < p.second; ++i) {
                cout << " " << p.first;
            }
        }
        cout << endl;
    }
}