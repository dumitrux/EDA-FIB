#include <iostream>
#include <vector>
using namespace std;
 
 
int fixed_point(int a, const vector<int>& v, int esq, int dre) {
	if (esq > dre) return -1;
	int mid = (esq+dre)/2;
	if (v[mid]+a > mid+1) return fixed_point(a, v, esq, mid-1);
	else if (v[mid]+a < mid+1) return fixed_point(a, v, mid+1, dre);
	else if (v[mid]+a == mid+1 and mid != 0 and v[mid-1]+a == mid) return fixed_point(a, v, esq, mid-1);
	return mid+1;
}

int main() {
	int n, seq;
	seq = 1;
	while (cin >> n) {
		cout << "Sequence #" << seq << endl;
		vector<int> v(n);
		int m;
		for(int i = 0; i < n; ++i) cin >> v[i];
		cin >> m;
		for (int i = 0; i < m; ++i) {
			int a, fixed;
			cin >> a;
			fixed = fixed_point(a, v, 0, n-1);
			if (fixed == -1) cout << "no fixed point for " << a;
			else cout << "fixed point for " << a << ": " << fixed;
			cout << endl;
		}
		++seq;
		cout << endl;
	}
}
