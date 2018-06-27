#include <iostream>
#include <vector>
#include <queue>
#include <limits>
 
using namespace std;
typedef pair<double, int> ArcP;
typedef vector< vector<ArcP> > GrafP;
 
 
int const INFINITY = numeric_limits<int>::max();
 
void dijkstra_eda(const GrafP &G, int s, vector<int> &d,
              vector<int> &p) {
 
    int n = G.size();
    d = vector<int>(n, INFINITY);
    d[s] = 0;
    p = vector<int>(n, -1);
    vector<bool> S(n, false);
    priority_queue<ArcP, vector<ArcP>, greater<ArcP> > Q;
    Q.push(ArcP(0, s));
 
    while (not Q.empty()) {
        int u = Q.top().second;
        Q.pop();
 
        if (not S[u]) {
            S[u] = true;
            for (int i = 0; i < int(G[u].size()); ++i) {
                int v = G[u][i].second;
                int c = G[u][i].first;
                if (d[v] > d[u] + c) {
                    d[v] = d[u] + c;
                    p[v] = u;
                    Q.push(ArcP(d[v], v));
                }
            }
        }
    }
 
}
 
 
void dijkstra(const GrafP &G, int x, int y, vector<int> &d,
                     vector<int> &p, int &distance) {
	distance = -1;
    int n = G.size();
    d = vector<int>(n, INFINITY);
    d[x] = 0;
    p = vector<int>(n, -1);
    vector<bool> S(n, false);
    priority_queue<ArcP, vector<ArcP>, greater<ArcP> > Q;
    Q.push(ArcP(0, x));
 
    while (not Q.empty()) {
        int u = Q.top().second;
        Q.pop();
 
        if (not S[u]) {
            S[u] = true;
            if (u == y) {
                distance = d[u];
                return;
            }
            int m = G[u].size();
            for (int i = 0; i < m; ++i) {
                int v = G[u][i].second;
                int c = G[u][i].first;
                if (d[v] > d[u] + c) {
                    d[v] = d[u] + c;
                    p[v] = u;
                    Q.push(ArcP(d[v], v));
                }
            }
        }
    }
}
 
void leer_tripletes(GrafP &G, int m) {
    int aux;
    ArcP arco;
    for (int i = 0; i < m; i++) {
        cin >> aux >> arco.second >> arco.first;
        G[aux].push_back(arco);
    }
}
 
int main() {
	int n;
	int m;
	while (cin >> n >> m) {
		GrafP G(n);
		leer_tripletes(G, m);
		vector<int> d;
		vector<int> p;
		int x, y;
		cin >> x >> y;
		int distance;
		dijkstra(G, x, y, d, p, distance);
		if (distance != -1) cout << distance << endl;
		else cout << "no path from " << x << " to " << y << endl;
	}
}
