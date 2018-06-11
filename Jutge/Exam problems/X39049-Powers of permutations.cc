#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Permutation {

  vector<int> v;

public:

  Permutation(int n)                : v( n ) { }
  Permutation(const Permutation& s) : v(s.v) { }

  Permutation& operator = (const Permutation& s) { 
    v = s.v; 
    return *this;
  }

  int& operator [](int i)       { return v[i]; }
  int  operator [](int i) const { return v[i]; }

  Permutation& operator *= (const Permutation& s) {
    for (int i = 0; i < v.size(); ++i)
      v[i] = s[v[i]];
    return *this;
  }

  void pow(int k) {
    if (k == 0)
      for (int i = 0; i < v.size(); ++i) 
	v[i] = i;
    else {
      Permutation s = *this;
      s.pow(k/2);
      if (k % 2 == 0) {
	*this = s;
	*this *= s;
      }
      else {
	*this *= s;
	*this *= s;
      }
    }
  }
};

int main() {
  int n;
  while (cin >> n) {
    Permutation p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    int k;
    cin >> k;
    p.pow(k);

    for (int x = 0; x < n; ++x) 
      cout << (x == 0 ? "" : " ") << p[x];
    cout << endl;
  }
}
