#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> P;

int main() {
	int n, m;
	while (cin >> n >> m) {
		vector< vector<P> > g(n);
		int tot = 0;
		for ( int k = 0; k < m; ++k) {
			int x, y, c ;
			cin >> x >> y >> c;
			g[x].push_back({c , y});
			g[y].push_back({c , x});
			tot += c;
		}
		vector<bool> mkd(n, false);
		mkd[0] = true;
		priority_queue <P, vector<P>, greater<P> > pq;
		for (P p : g [0]) pq.push(p);
		int sz = 1;
		int sum = 0;
		while (sz < n) {
			int c = pq. top (). first ;
			int x = pq. top (). second;
			pq.pop ();
			if (not mkd[x]) {
				mkd[x] = true;
				for (P p : g[x]) pq.push(p);
				sum += c;
				++sz;
			}
		}
		cout << tot - sum << endl;
	}
}
