#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A"
#include "../../../template/template.hpp"
#include "../../../03_Graph/02_GraphAlgorithm/01.01.03.01_single-source-shortest-path.weighted-graph.dijkstra.hpp"

signed main() {
    int V, E, r;
    cin >> V >> E >> r;
    dijkstra<long> g(V);
    for (int i = 0; i < E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        g[s].emplace_back(t, d);
    }
    g.build(r);
    for (int i = 0; i < V; ++i) {
        if (g.reach(i)) cout << g.distance(i) << endl;
        else cout << "INF" << endl;
    }
    return 0;
}