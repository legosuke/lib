#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2664"
#include "../../../template/template.hpp"
#include "../../../02_DataStructure/01_UnionFind/02.01_attributed-union-find.min-max.hpp"

signed main() {
    int N;
    cin >> N;
    UnionFindMinMax<int> uf(N);
    map<string, int> mp;
    for (int i = 0; i < N; ++i) {
        string a;
        int x;
        cin >> a >> x;
        mp[a] = i;
        uf.set(i, x);
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        string s, t;
        cin >> s >> t;
        uf.unite_trees(mp[s], mp[t]);
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += uf.min(i);
    }
    cout << ans << endl;
}