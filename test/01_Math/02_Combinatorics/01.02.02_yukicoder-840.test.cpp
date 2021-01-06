#define PROBLEM "https://yukicoder.me/problems/no/840"
#include "../../../template/template.hpp"
#include "../../../01_Math/02_Combinatorics/01.02.01_modint.static.hpp"
#include "../../../01_Math/02_Combinatorics/01.02.02_modint.dynamic.hpp"
#include "../../../01_Math/03_Algebra/01.01.01.01_matrix.vector.hpp"

signed main() {
    int N, K; cin >> N >> K;
    modint::set_mod(K);
    matrix_vector<modint> M(K * K * K, K * K * K);
    for (int i = 0; i < K; ++i) for (int j = 0; j < K; ++j) for (int k = 0; k < K; ++k) {
        M[K * K * ((i + 1) % K) + K * ((i + j) % K) + (j + k) % K][K * K * i + K * j + k] = 1;
    }
    vector<modint> v(K * K * K);
    v[0] = 1;
    v = M * v;
    modint998244353 ans = 0;
    for (int i = 0; i < K * K; ++i) {
        ans += v[i].val();
    }
    cout << ans << endl;
}