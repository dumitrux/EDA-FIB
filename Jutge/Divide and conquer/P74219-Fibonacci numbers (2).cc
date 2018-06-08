#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> filas;
typedef vector<filas> matrix;

void mult_M(const matrix& aux1, const matrix& aux2, matrix& E, int m) {
	E = matrix(2, vector<int> (2,0));
	
	for(int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) E[i][j] += aux1[i][k]*aux2[k][j];
			E[i][j] %= m;
		}
	}
}

void exp_M(const matrix& M, matrix& E, int n, int m) {
	if (n == 0) {
		E[0][0] = E[1][1] = 1;
		E[0][1] = E[1][0] = 0;
	}
	
	else if (n == 1) {
		E[0][0] = M[0][0]%m;
        E[0][1] = M[0][1]%m;
        E[1][0] = M[1][0]%m;
        E[1][1] = M[1][1]%m;
	}
	
	else if (n%2 == 0) {
		matrix aux(2, vector<int> (2));
		exp_M(M, aux, n/2, m);
		mult_M(aux, aux, E, m);
	}
	
	else {
		matrix aux(2, vector<int> (2));
		exp_M(M, aux, n - 1, m);
		mult_M(M, aux, E, m);
	}
}

int main() {
	matrix M(2, vector<int> (2));
	int n, m;
	while(cin >> n >> m) {
		matrix E(2, vector<int> (2));
		M[0][0] = 0;
		M[1][1] = M[0][1] = M[1][0] = 1;
		exp_M(M, E, n, m);
		cout << E[0][1] << endl;
	}
}
