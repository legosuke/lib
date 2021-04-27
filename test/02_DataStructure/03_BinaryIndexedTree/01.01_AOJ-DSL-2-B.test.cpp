#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"
#include "../../../template/template.hpp"
#include "../../../02_DataStructure/03_BinaryIndexedTree/01.01_binary-indexed-tree-1d.hpp"

signed main() {
    int n, q;
    cin >> n >> q;
    binary_indexed_tree_1d<int> bit(n + 1);
    for (int i = 0; i < q; ++i) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) bit.add(x, y);
        else cout << bit.sum(x, y) << endl;
    }
}