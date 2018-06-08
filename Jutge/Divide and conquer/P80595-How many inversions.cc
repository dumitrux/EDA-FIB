#include <iostream>
#include <vector>

using namespace std;

int inversions(vector<int>& v, int l, int r) {
	if (l >= r) return 0;
	int m = (l+r)/2;
	int N1 = inversions(v,l,m);
	int N2 = inversions(v,m+1,r);
	vector<int> w(r-l+1);
	int i, j, k, N3;
	i = l; k = 0; j = m+1; N3 = 0;
	while(i <= m and j <= r) {
		if(v[i] <= v[j]) w[k++] = v[i++];
		else {
			w[k++] = v[j++];
			N3 += m+1 - i;
		}
	}
	while(i <= m) w[k++] = v[i++];
	while (j <= r) w[k++] = v[j++];
	for(k = 0; k < r-l+1; ++k) v[l+k] = w[k];
	return N1+N2+N3;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> v(n);
		for(int i = 0; i < n; ++i) cin >> v[i];
		int cont = inversions(v, 0, n-1);
		cout << cont << endl;
	}
}
