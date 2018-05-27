#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> c;
vector<bool> col, diag1, diag2;

bool f(int r) {
  if (r == n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) 
	if (c[i] == j) cout << 'Q';
	else           cout << '.';
      cout << endl;
    }
    return true;
  }
  else {
    for (int j = 0; j < n; ++j) {
      if (not col[j]     and
	  not diag1[n-1+j-r] and
	  not diag2[j+r]) {
	col[j] = true;
	diag1[n-1+j-r] = true;
	diag2[j+r] = true;
	c[r] = j;
	if (f(r+1)) {
	  return true;
	}
	col[j] = false;
	diag1[n-1+j-r] = false;
	diag2[j+r] = false;
      }
    }
    return false;
  }
}

int main() {
  cin >> n;
  c = vector<int>(n);
  col   = vector<bool>(n,     false);
  diag1 = vector<bool>(2*n-1, false);
  diag2 = vector<bool>(2*n-1, false);
  if (not f(0)) {
    cout << "NO SOLUTION" << endl;
  }
}

