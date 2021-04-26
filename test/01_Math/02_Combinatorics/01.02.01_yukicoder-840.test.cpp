#define PROBLEM "https://yukicoder.me/problems/no/840"
#include "../../../template/template.hpp"
#include "../../../01_Math/02_Combinatorics/01.02.01_modint.static.hpp"
#include "../../../01_Math/03_Algebra/01.01.01.01_matrix.vector.hpp"

signed main() {
    int N, K; cin >> N >> K;
    matrix_vector<modint998244353> M(K * K * K, K * K * K);
    int K2 = K * K;
    for (int i = 0; i < K; ++i) for (int j = 0; j < K; ++j) for (int k = 0; k < K; ++k) {
        int src = K2 * i + K * j + k;
        M[K2 * ((i + 1) % K) + K * j + k][src] += 1;
        M[K2 * i + K * ((j + i) % K) + k][src] += 1;
        M[K2 * i + K * j + ((k + j) % K)][src] += 1;
    }
    M = M ^ N;

    vector<modint998244353> v(K * K * K);
    v[0] = 1;
    v = M * v;
    modint998244353 ans = 0;
    for (int i = 0; i < K * K; ++i) {
        ans += v[i * K].get_val();
    }
    cout << ans << endl;
}