#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1327"
#include "../../../template/template.hpp"
#include "../../../01_Math/02_Combinatorics/01.02.02_modint.dynamic.hpp"
#include "../../../01_Math/03_Algebra/01.01.01.01_matrix.vector.hpp"

signed main() {
    int N, M, A, B, C, T;
    while (cin >> N >> M >> A >> B >> C >> T, N) {
        modint::set_mod(M);
        vector<modint> S(N);
        for (int i = 0; i < N; ++i) {
            cin >> S[i];
        }
        matrix_vector<modint> P(N, N);
        for (int i = 0; i < N; ++i) {
            if (i - 1 >= 0) P[i][i - 1] = A;
            P[i][i] = B;
            if (i + 1 < N) P[i][i + 1] = C;
        }
        S = (P ^ T) * S;
        for (int i = 0; i < N; ++i) {
            cout << S[i] << " \n"[i + 1 == N];
        }
    }
} 