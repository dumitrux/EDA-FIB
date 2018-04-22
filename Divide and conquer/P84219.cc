#include <iostream>
#include <vector>

using namespace std;


int first_occurrence(double x, const vector<double>& v, int esq, int dre) {
	if (esq > dre) return -1;
	int m = (esq+dre)/2;
	if(v[m]==x) {
		if(v[m-1] == x and m-1 >= esq) return first_occurrence(x, v, esq, m-1);
		else return m;
	}
	if (x < v[m]) return first_occurrence(x, v, esq, m-1);
	else return first_occurrence(x, v, m+1, dre);
}

int first_occurrence(double x, const vector<double>& v) {
	return first_occurrence(x,v,0,v.size()-1);
}


int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}
