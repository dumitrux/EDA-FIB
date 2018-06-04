#include <iostream>
#include <vector>

using namespace std;

bool reachable(vector<vector<char> >& M, int f, int c) {
	if(f < 0 or c < 0 or f >= M.size() or c >= M[0].size() or 
	M[f][c] == 'X') return false;
	
	if (M[f][c] == 't') return true;
	M[f][c] = 'X'; //mark cell as visited
	return reachable(M, f+1,c) or
	reachable(M, f-1,c) or
	reachable(M, f,c+1) or
	reachable(M, f,c-1);
}

int main() {
	int f, c;
	cin >> f >> c;
	
	vector<vector<char> > M(f, vector<char>(c));
	for(int i = 0; i < f; ++i)
		for(int j = 0; j < c; ++j) cin >> M[i][j];
	
	int forig, corig;
	cin >> forig >> corig;
	
	//arribable?
	if (reachable(M,forig - 1,corig - 1)) cout << "yes" << endl;
	else cout << "no" << endl;
}
