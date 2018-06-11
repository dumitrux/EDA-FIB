#include <iostream>
#include <vector>

using namespace std;

enum Letter {CON = 0, VOC};

void g(int k, int n, vector<string>& let, string& sol , vector<vector<bool>>& mkd) {
	if (k == 2*n) cout << sol << endl;
	else {
		int k2 = k%2;
		for ( int i = 0; i < n; ++i)
		if (not mkd[k2][i ]) {
			sol [k] = let [k2][ i ];
			mkd[k2][i ] = true;
			g(k+1, n, let , sol , mkd);
			mkd[k2][i ] = false ;
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<bool>> mkd(2, vector<bool>(n, false));
	vector<string> let (2);
	cin >> let [CON] >> let[VOC];
	string sol (2*n, ' ' ); // Need a char for filling.
	g(0, n, let , sol , mkd);
}
