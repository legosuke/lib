#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_6_D"
#include "../../../template/template.hpp"
#include "../../../01_Math/03_Algebra/01.01.01.01_matrix.vector.hpp"

signed main() {
    int n, m;
    cin >> n >> m;
    matrix_vector<int> A(n, m);
    vector<int> b(m);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        cin >> A[i][j];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    auto ans = A * b;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }
}