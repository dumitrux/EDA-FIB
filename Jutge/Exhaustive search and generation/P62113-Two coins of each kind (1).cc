#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void escribir(vector<int> &solucion, int tope, int x) {
    cout << x << " = ";
    bool primer = true;
    for (int i = 0; i < tope; i++) {
        if (solucion[i] != 0) {
            if (primer) {
                primer = false;
                if (i%2 != 0) cout << solucion[i] << 'p';
                else cout << solucion[i];
            }
            else {
                if (i%2 != 0) cout << " + " << solucion[i] << 'p';
                else cout << " + " << solucion[i];
            }
        }
    }
    cout << endl;
}
 
void moneda(int i, int valor, int x, vector<int> &numeros, vector<int> &solucion) {
    int n = numeros.size();
    if (valor == x) escribir(solucion, i, x);
    else if (i < 2*n) {
        if (valor < x) {
            int aux = solucion[i];
            solucion[i] = numeros[i/2];
            valor += numeros[i/2];
            moneda(i + 1, valor, x, numeros, solucion);
            valor -= numeros[i/2];
            solucion[i] = aux;
            moneda(i + 1, valor, x, numeros, solucion);
        }
    }
}
 
int main () {
    int x, n;
    while (cin >> x >> n) {
        vector<int> numeros(n);
        for (int i = 0; i < n; i++) cin >> numeros[i];
        sort(numeros.begin(), numeros.end());
        vector<int> solucion(2*n);
        moneda(0, 0, x, numeros, solucion);
        cout << "----------" << endl;
    }
}
