#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I"
#include "../../../template/template.hpp"
#include "../../../02_DataStructure/02_SegmentTree/00.01.03_monoid.plus.hpp"
#include "../../../02_DataStructure/02_SegmentTree/00.01.04_monoid.update.hpp"
#include "../../../02_DataStructure/02_SegmentTree/00.02.04_mapping.update-plus.hpp"
#include "../../../02_DataStructure/02_SegmentTree/03_lazy-segment-tree.hpp"

signed main() {
    int n, q;
    cin >> n >> q;
    lazy_segment_tree<plus_monoid<int>, update_monoid<int>, plus_update_mapping<int>> lst(n);
    for (int i = 0; i < q; ++i) {
        int com, s, t;
        cin >> com >> s >> t;
        if (com == 0) {
            int x;
            cin >> x;
            lst.apply(s, t + 1, x);
        } else {
            cout << lst.product(s, t + 1) << endl;
        }
    }
}