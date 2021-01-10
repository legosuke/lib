#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A"
#include "../../../template/template.hpp"
#include "../../../02_DataStructure/01_UnionFind/01_union-find.hpp"

signed main() {
    int n, q;
    cin >> n >> q;
    union_find uf(n);
    for (int i = 0; i < q; ++i) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) uf.unite_trees(x, y);
        else cout << uf.is_same(x, y) << endl;
    }
}