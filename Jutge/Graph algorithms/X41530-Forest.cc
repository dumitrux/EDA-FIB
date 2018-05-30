#include <iostream>
#include <vector>
using namespace std;
 
typedef vector<int> row;
typedef vector<row> mat;
 
void llegir_graf(mat& g, int m) {
    int x, y;
    for (int j = 0; j < m; j++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}
 
void cerca_cicles(const mat& g, vector<bool>& vis, int i, int pare, bool& b) {
    if (!vis[i]) {
        vis[i] = true;
        for (int j = 0; j < (int)g[i].size(); j++) {
			//no operar si hi ha cicle(si vèrtex es el pare)
            if (g[i][j] != pare) 
                cerca_cicles(g, vis, g[i][j], i, b);
                if (b) return;
        }
    }
    else b = true;
}
 
void dfs(const mat& g) {
    vector<bool> vis(g.size(), false);
    int na = 0; // nombre d'arbres
    for (int i = 0; i < (int)g.size(); i++) {
        if (!vis[i]) {
            bool b = false;
            cerca_cicles(g, vis, i, i, b);
            if (b) {
                cout << "no" << endl;
                return; //hi ha cicle
            }
            else na++;
        }
    }
    cout << na << endl;
}
 
int main() {
    int n, m;
    while (cin >> n >> m) {
        mat g(n);
        llegir_graf(g, m); //llista d'adjacència
        dfs(g);
    }
}
