#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Writes all possible ways of extending the first k positions of v
// to a binary sequence of length n.
void f(int k, int n, int o, int s, vector<int>& v) {
  if (s > o or k-s > n-o) return;
  if (k == n) {
    if (s == o) {
      cout << v[0];
      for (int i = 1; i < n; ++i) 
	cout << ' ' << v[i];
      cout << endl;
    }
  }
  else {
    v[k] = 0; f(k+1, n, o, s,   v);
    v[k] = 1; f(k+1, n, o, s+1, v); 
  }
}

int main() {
  int n, o;
  cin >> n >> o;

  vector<int> v(n);
  f(0, n, o, 0,v);
}

