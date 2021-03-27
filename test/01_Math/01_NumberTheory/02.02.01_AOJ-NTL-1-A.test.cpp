#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"
#include "../../../template/template.hpp"
#include "../../../01_Math/01_NumberTheory/02.02.01_prime-factor.naive.hpp"

signed main() {
    int n;
    cin >> n;
    cout << n << ":";
    for (auto p : prime_factor(n)) {
        for (int i = 0; i < p.second; ++i) {
            cout << " " << p.first;
        }
    }
    cout << endl;
}