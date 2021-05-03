#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_7_D"
#include "../../../template/template.hpp"
#include "../../../01_Math/03_Algebra/01.01.01.01_matrix.vector.hpp"

signed main() {
    int n, m, l;
    cin >> n >> m >> l;
    matrix_vector<int> A(n, m), B(m, l);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        cin >> A[i][j];
    }
    for (int i = 0; i < m; ++i) for (int j = 0; j < l; ++j) {
        cin >> B[i][j];
    }
    auto ans = A * B;
    for (int i = 0; i < n; ++i) for (int j = 0; j < l; ++j) {
        cout << ans[i][j] << " \n"[j + 1 == l];
    }
}