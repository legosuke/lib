#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B"
#include "../../../template/template.hpp"
#include "../../../02_DataStructure/01_UnionFind/03.01_potentialized-union-find.hpp"

signed main() {
    int n, q;
    cin >> n >> q;
    PotentializedUnionFind<int> uf(n);
    for (int i = 0; i < q; ++i) {
        int c, x, y, z;
        cin >> c >> x >> y;
        if (c == 0) {
            cin >> z;
            uf.unite_trees(x, y, z);
        } else {
            if (uf.is_same(x, y)) cout << uf.diff_weight(x, y) << endl;
            else cout << "?" << endl;
        }
    }
}