#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"
#include "../../../template/template.hpp"
#include "../../../02_DataStructure/02_SegmentTree/00.01.03_monoid.plus.hpp"
#include "../../../02_DataStructure/02_SegmentTree/01_segment-tree.hpp"

signed main() {
    int n, q;
    cin >> n >> q;
    segment_tree<plus_monoid<int>> st(n);
    for (int i = 0; i < q; ++i) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) st.set(x - 1, y + st.get(x - 1));
        else cout << st.product(x - 1, y) << endl;
    }
}