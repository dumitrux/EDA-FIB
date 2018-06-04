#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Retorna si el punt esta dins del mapa M
bool ok(int x, int y, const vector<vector<char> >& M) {
	return (x >= 0 and x < int(M.size()) and y >= 0 and y < int(M[0].size()) and M[x][y] != 'X');
}

int distancia_minima(int origX, int origY, vector<vector<char> >& M) {
	int files = M.size();
	int cols = M[0].size();
	
	queue<pair<int,int> > Q;
	vector<vector<int> > dist(files, vector<int>(cols, -1));
	
	Q.push({origX,origY});
	dist[origX][origY] = 0;
	int maxDist = -1;
	
	while (Q.size() > 0) {
		pair<int, int> punt = Q.front();
		int x = punt.first;
		int y = punt.second;
		Q.pop();
		
		if (M[x][y] == 't') maxDist = dist[x][y];
		M[x][y] = 'X';
		
		if (ok(x+1, y, M) and dist[x+1][y] == -1) {Q.push({x+1,y}); dist[x+1][y] = dist[x][y] + 1;}
		if (ok(x-1, y, M) and dist[x-1][y] == -1) {Q.push({x-1,y}); dist[x-1][y] = dist[x][y] + 1;}
		if (ok(x, y+1, M) and dist[x][y+1] == -1) {Q.push({x,y+1}); dist[x][y+1] = dist[x][y] + 1;}
		if (ok(x, y-1, M) and dist[x][y-1] == -1) {Q.push({x,y-1}); dist[x][y-1] = dist[x][y] + 1;}
	}
	return maxDist;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<char> > M(n, vector<char>(m));
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) cin >> M[i][j];
	
	int origX, origY;
	cin >> origX >> origY;
	--origX;
	--origY;
	
	int dist = distancia_minima(origX, origY, M);
	
	if(dist == -1) cout << "no es pot arribar a cap tresor"; 
	else cout << "distancia maxima: " << dist;
	cout << endl;
}
