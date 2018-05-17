#include <iostream>
#include <vector>

using namespace std;


int num_tresors(vector<vector<char> >& M, int f, int c) {
	if(f >= 0 and c >= 0 and f < int(M.size()) and c < int(M[0].size()) and 
	M[f][c] != 'X') {
		bool trobat;
		trobat = M[f][c] == 't';
		M[f][c] = 'X'; //mark cell as visited
		
		int cont = (num_tresors(M, f+1, c) +
					num_tresors(M, f-1, c) +
					num_tresors(M, f, c+1) +
					num_tresors(M, f, c-1));
		
		return cont + trobat;
	}
	return 0;
	
}

int main() {
	int f, c;
	cin >> f >> c;
	
	vector<vector<char> > M(f, vector<char>(c));
	for(int i = 0; i < f; ++i)
		for(int j = 0; j < c; ++j) cin >> M[i][j];
	
	int forig, corig;
	cin >> forig >> corig;
	cout << num_tresors(M, forig-1, corig-1) << endl;
}
