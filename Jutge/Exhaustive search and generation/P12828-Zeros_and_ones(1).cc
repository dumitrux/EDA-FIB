#include <iostream>
#include <vector>

using namespace std;

// Writes all possible ways of extending the first k positions of v
// to a binary sequence of length n.
void f(int k, vector<int>& v) {
  int n = v.size();
  if (k == n) {
    cout << v[0];
    for (int i = 1; i < n; ++i) 
      cout << ' ' << v[i];
    cout << endl;
  }
  else {
    v[k] = 0; f(k+1, v);
    v[k] = 1; f(k+1, v);
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  f(0, v);
}

