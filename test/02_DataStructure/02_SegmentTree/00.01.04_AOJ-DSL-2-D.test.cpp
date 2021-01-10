#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D"
#include "../../../template/template.hpp"
#include "../../../02_DataStructure/02_SegmentTree/00.01.04_monoid.update.hpp"
#include "../../../02_DataStructure/02_SegmentTree/02_dual-segment-tree.hpp"

signed main() {
    int n, q;
    cin >> n >> q;
    dual_segment_tree<update_monoid<std::int32_t>> dst(n);
    for (int i = 0; i < q; ++i) {
        int com;
        cin >> com;
        if (com == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            dst.apply(s, t + 1, x);
        } else {
            int p;
            cin >> p;
            cout << dst.get(p) << endl;
        }
    }
}