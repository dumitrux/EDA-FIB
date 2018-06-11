#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>  VI;
typedef vector<VI >  VVI;

int n, m;
VVI g;
VI  c;

const int UNDEF = -1;

// Returns true if no conflict is found.
bool propagate(int x, int col) {
  if (c[x] == UNDEF) {
    c[x] = col;
    for (int y: g[x])
      if (not propagate(y, 1-col)) return false;
    return true;
  }
  else return c[x] == col;
}

bool two_colorable(int x) {
  if (x == n) return true;
  if (c[x] == UNDEF) return propagate(x, 0) and two_colorable(x+1);
  else               return                     two_colorable(x+1);
}

int main() {
  while (cin >> n >> m) {
    g = VVI(n);
    for (int k = 0; k < m; ++k) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    c = VI(n, UNDEF);
    if (two_colorable(0)) cout << "yes" << endl;
    else                  cout << "no"  << endl;
  }
}
