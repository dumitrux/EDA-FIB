#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vec;


int select(int k, const vec &v1, const vec &v2) {
	if (v1.empty()) return v2[k-1];
	if (v2.empty()) return v1[k-1];
	if (k==1) return min(v1[0], v2[0]);
	
	const vec &a = v1.size()<=v2.size() ? v1 : v2;
	const vec &b = v1.size()<=v2.size() ? v2 : v1;
	
	int l = max(0, k-(int)b.size());
	int r = min((int)a.size(), k);
	
	while (1) {
		int na = (l+r)>>1;
		int i = na - 1;
		int j = k - na - 1;
		if (na && (j == -1 || a[i] >= b[j])) {
			if (j + 1 ==(int)b.size() || a[i]<=b[j+1]) return a[i];
			else r = na;
		}
    else {
		if (i + 1 == (int)a.size() || a[i+1] >= b[j]) return b[j];
		else l = na + 1;
	}
	}
}
