#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#include "../../../template/template.hpp"
#include "../../../01_Math/01_NumberTheory/02.07_enumerate-primes.hpp"
#include "../../../01_Math/01_NumberTheory/03.01.03_sieve.atkin.hpp"

auto is_prime = atkin<500000000>();

signed main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> primes;
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
    vector<int> v;
    for (int i = B; i < (int)primes.size() && primes[i] <= N; i += A) {
        v.push_back(primes[i]);
    }
    cout << primes.size() << " " << v.size() << endl;
    for (int i = 0; i < (int)v.size(); ++i) {
        cout << v[i] << " \n"[i + 1 == (int)v.size()];
    }
}