#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> c;
vector<bool> col, diag1, diag2;

int f(int r) {
  if (r == n) return 1;
  else {
    int m = 0;
    for (int j = 0; j < n; ++j) {
      if (not col[j]     and
	  not diag1[n-1+j-r] and
	  not diag2[j+r]) {
	col[j] = true;
	diag1[n-1+j-r] = true;
	diag2[j+r] = true;
	c[r] = j;
	m += f(r+1);
	col[j] = false;
	diag1[n-1+j-r] = false;
	diag2[j+r] = false;
      }
    }
    return m;
  }
}

int main() {
  cin >> n;
  c = vector<int>(n);
  col   = vector<bool>(n,     false);
  diag1 = vector<bool>(2*n-1, false);
  diag2 = vector<bool>(2*n-1, false);
  cout << f(0) << endl;
}

