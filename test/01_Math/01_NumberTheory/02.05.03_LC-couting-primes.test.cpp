#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"
#include "../../../template/template.hpp"
#include "../../../01_Math/01_NumberTheory/02.05.03_prime-count.missel-lehmer.hpp"

signed main() {
    int N;
    cin >> N;
    cout << prime_count(N) << endl;
    return 0;
}