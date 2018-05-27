#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> c;
vector<bool> col, diag1, diag2;
/*
bool legal(int n, int r, int j, const vector<int>& c) {
  for (int i = 0; i < r; ++i) {
    if (c[i] == j) { // they are in the same column
      return false;
    }
    if (c[i] - i == j - r) { // queen of row i is in same desc. diag
      // queen of row i is at point     (i, c[i])
      // my candidate queen is at point (r, j)
      return false;
    }
    if (c[i] + i == j + r) { // queen of row i is in same asc. diag
      // queen of row i is at point     (i, c[i])
      // my candidate queen is at point (r, j)
      return false;
    }
  }
  return true;
}
*/
void f(int r) {
  if (r == n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) 
	if (c[i] == j) cout << 'Q';
	else           cout << '.';
      cout << endl;
    }
    cout << endl;
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
	f(r+1);
	col[j] = false;
	diag1[n-1+j-r] = false;
	diag2[j+r] = false;
      }
    }
  }
}

int main() {
  cin >> n;
  c = vector<int>(n);
  col   = vector<bool>(n,     false);
  diag1 = vector<bool>(2*n-1, false);
  diag2 = vector<bool>(2*n-1, false);
  f(0);
}

