#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1276"
#include "../../../template/template.hpp"
#include "../../../01_Math/01_NumberTheory/03.01.01_sieve.eratosthenes.hpp"

signed main() {
    const int MAX_N = 1299709;
    int n;
    auto is_prime = sieve(MAX_N + 1);
    while (cin >> n, n) {
        if (is_prime[n]) {
            cout << 0 << endl;
        } else {
            int prev, next;
            for (prev = n - 1; !is_prime[prev]; --prev);
            for (next = n + 1; !is_prime[next]; ++next);
            cout << next - prev << endl;
        }
    }
}