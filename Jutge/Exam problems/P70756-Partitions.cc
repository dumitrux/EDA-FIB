#include <iostream>
#include <vector>

using namespace std;

void write ( int n, int p, const vector<string>& s, vector<int>& sol) {
	for ( int j = 0; j < p; ++j) {
		cout << "subconjunt " << j+1 << ": {";
		string aux = "";
		for ( int i = 0; i < n; ++i)
		if ( sol [ i ] == j ) {
			cout << aux << s[i ];
			aux = ",";
		}
		cout << "}" << endl;
	}
	cout << endl;
}

void g(int k, int n, int p, const vector<string>& s, vector<int>& sol) {
	if (k == n) write (n, p, s , sol );
	else for ( int i = 0; i < p; ++i) {
		sol [k] = i ;
		g(k+1, n, p, s , sol );
	}
}

int main() {
	int n, p;
	cin >> n;
	vector<string> s(n);
	for (auto& x : s) cin >> x;
	cin >> p;
	vector<int> sol(n);
	g(0, n, p, s , sol );
}
