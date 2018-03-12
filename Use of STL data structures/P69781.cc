#include <iostream>
#include <map>
using namespace std;

int main() {
	int x, y, n;
	
	while(cin >> x >> y >> n) {
		map<int,int> m;
		map<int,int>::const_iterator it;
		bool repetido = false;
		int ciclo=0;
		
		m.insert(make_pair(n, ciclo));
		
		while(!repetido and n<=100000000) {
			++ciclo;
			/* n = (n % 2) ? 3 * n + y : n / 2 + x; (condicion ? cierto : flaso) 
			es cierto si el resultado es cualquier valor diferente de 0 */
			if(n%2==0) n=n/2+x;
			else n=3*n+y;
			
			it = m.find(n);
			if(it==m.end()) m.insert(make_pair(n, ciclo));
			else repetido = true;
		}
		
		//cout << (repeated ? result : n) << endl;
		if(repetido) cout << (m.size() - it->second) << endl;
		else cout << n << endl;
	}
}
