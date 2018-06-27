#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
typedef pair< int, pair<int,int> > WEdge;
typedef vector< vector< pair<int,int> > > WGraph;
 
void read_graph(WGraph& G, int m) {
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        G[u-1].push_back(make_pair(w,v-1));
        G[v-1].push_back(make_pair(w,u-1));
    }
}
 
int MST(const WGraph& G) {
    vector<bool> used(G.size(),false);
    priority_queue< WEdge > Q;
    Q.push(make_pair(0, make_pair(0,0)));
    int sum = 0;
 
    while (not Q.empty()) {
        int p = -(Q.top().first);
        int v = Q.top().second.second;
        Q.pop();
        if (not used[v]) {
            used[v] = true;
            sum += p;
            for (int i = 0; i < G[v].size(); ++i) {
                int w = G[v][i].first;
                int u = G[v][i].second;
                Q.push(make_pair(-w, make_pair(v,u)));
            }
        }
    }
 
    return sum;
}
 
int main () {
    int n, m;
    while (cin >> n >> m) {
        WGraph G(n);
        read_graph(G,m);
        int w = MST(G);
        cout << w << endl;
    }
}
