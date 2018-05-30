#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;
using VVE = vector<VE>;
using VVVE = vector<VVE>;


VVE M(9, VE(9));
VVE fila, colu;
VVVE quad;


void print() {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j)
      cout << (j ? " " : "") << M[i][j];
    cout << endl;
  }
}


bool f(int i, int j) {
  if (i == 9) {
    print();
    return true;
  }

  if (j == 9) return f(i + 1, 0);

  if (M[i][j] != 0) return f(i, j + 1);

  for (int d = 1; d <= 9; ++d)
    if (not fila[i][d] and not colu[j][d] and not quad[i/3][j/3][d]) {
      fila[i][d] = colu[j][d] = quad[i/3][j/3][d] = true;
      M[i][j] = d;
      if (f(i, j + 1)) return true;
      M[i][j] = 0;
      fila[i][d] = colu[j][d] = quad[i/3][j/3][d] = false;
    }
  return false;
}


int main() {
  int n;
  cin >> n;
  cout << n << endl;
  while (n--) {
    cout << endl;
    fila = colu = VVE(9, VE(10, false));
    quad = VVVE(3, VVE(3, VE(10, false)));
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j) {
        char c;
        cin >> c;
        if (c == '.') M[i][j] = 0;
        else {
          int d = c - '0';
          M[i][j] = d;
          fila[i][d] = colu[j][d] = quad[i/3][j/3][d] = true;
        }
      }

     f(0, 0);
  }
}
