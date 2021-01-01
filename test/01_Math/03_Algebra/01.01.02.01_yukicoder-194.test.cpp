#define PROBLEM "https://yukicoder.me/problems/no/194"
#include "../../../template/template.hpp"
#include "../../../01_Math/02_Combinatorics/01.02.01_modint.static.hpp"
#include "../../../01_Math/03_Algebra/01.01.01.01_matrix.vector.hpp"

signed main() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    if (N <= 10000 && K <= 1000000) {
        vector<modint1000000007> fib(K);
        for (int i = 0; i < N; ++i) {
            fib[i] = A[i];
            fib[N] += A[i];
        }
        for (int i = N + 1; i < K; ++i) {
            fib[i] += fib[i - 1] * 2;
            fib[i] -= fib[i - N - 1];
        }
        modint1000000007 sum(0);
        for (int i = 0; i < K; ++i) {
            sum += fib[i];            
        }
        cout << fib[K - 1] << " " << sum << endl;
    } else {
        matrix_vector<modint1000000007> M(N + 1);
        for (int i = 0; i < N - 1; ++i) {
            for (int j = 0; j < N + 1; ++j) {
                if (j == i + 1) M[i][j] = 1;
                else M[i][j] = 0;
            }
        }
        for (int j = 0; j < N; ++j) {
            M[N - 1][j] = M[N][j] = 1;
        }
        M[N][N] = 1;
        M = M ^ (K - N);
        vector<modint1000000007> v(N + 1);
        for (int i = 0; i < N; ++i) {
            v[i] = A[i];
            v[N] += A[i];
        }
        auto w = M * v;
        cout << w[N - 1] << " " << w[N] << endl;
    }
}