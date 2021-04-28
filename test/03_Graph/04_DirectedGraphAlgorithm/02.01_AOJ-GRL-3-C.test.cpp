#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C"
#include "../../../template/template.hpp"
#include "../../../03_Graph/04_DirectedGraphAlgorithm/02.01_strongly-connected-components.hpp"

signed main() {
    int V, E;
    cin >> V >> E;
    stolongly_connected_components g(V);
    for (int i = 0; i < E; ++i) {
        int s, t;
        cin >> s >> t;
        g[s].emplace_back(t);
    }
    g.build();
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int u, v;
        cin >> u >> v;
        cout << g.same(u, v) << endl;
    }
    return 0;
}