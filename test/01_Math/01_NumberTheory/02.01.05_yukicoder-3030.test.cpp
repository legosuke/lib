#define PROBLEM "https://yukicoder.me/problems/no/3030"
#include "../../../template/template.hpp"
#include "../../../01_Math/01_NumberTheory/02.01.05_is-prime.miller-rabin.hpp"

signed main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cout << x << " " << is_prime(x) << endl;
    }
}