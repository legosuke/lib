#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E"
#include "../../../template/template.hpp"
#include "../../../02_DataStructure/02_SegmentTree/00.01.03_monoid.plus.hpp"
#include "../../../02_DataStructure/02_SegmentTree/02.00_dual-segment-tree.hpp"

signed main() {
    int n, q;
    cin >> n >> q;
    dual_segment_tree<plus_monoid<int>> dst(n);
    for (int i = 0; i < q; ++i) {
        int com;
        cin >> com;
        if (com == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            dst.apply(s - 1, t, x);
        } else {
            int p;
            cin >> p;
            cout << dst.get(p - 1) << endl;
        }
    }
}