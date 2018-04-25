#include <iostream>
using namespace std;


int exp_mod(int n, int k, int m) {
	if(k == 0) return 1;
	if (k <= 1) return n%m;
	else {
		int x = exp_mod(n, k/2, m)%m;
		if (k%2 == 0) return (x*x)%m;
		else return (((x*x)%m)*n)%m;
	}
}

int main() {
	int n, k, m;
	while(cin >> n >> k >> m) {
		int result;
		result = exp_mod(n, k, m);
		cout << result << endl;
	}
}
