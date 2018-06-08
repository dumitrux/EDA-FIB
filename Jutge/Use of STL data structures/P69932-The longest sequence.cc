#include <iostream>
#include <set>
#include <sstream>
using namespace std;


int main() {
	string s;
	while (getline(cin, s)) {
		istringstream ss(s);
		int x, cont = 0;
		set<int> conj;
		while (ss >> x) conj.insert(x);
		
		int ant;
		set<int>::iterator it = conj.begin();
		if (!conj.empty()) {
			ant = *it;
			++it;
			++cont;
		}
		for (;it != conj.end(); ++it) {
			if (ant < *it and 
			((ant%2==0 and *it%2!=0) or (ant%2!=0 and *it%2==0))) ++cont;
			ant = *it;
		}
		cout << cont << endl;
	}
}
