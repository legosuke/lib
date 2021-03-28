#define PROBLEM "https://old.yosupo.jp/problem/factorize"
#include "../../../template/template.hpp"
#include "../../../01_Math/01_NumberTheory/02.02.03_prime-factor.rho.hpp"

signed main() {
    int Q;
    cin >> Q;
    Rho rho;
    for (int i = 0; i < Q; ++i) {
        int a;
        cin >> a;
        auto pf = rho.prime_factor(a);
        sort(pf.begin(), pf.end());
        int k = 0;
        for (auto p : pf) k += p.second;
        cout << k;
        for (auto p : pf) cout << " " << p.first;
        cout << endl;
    }
}