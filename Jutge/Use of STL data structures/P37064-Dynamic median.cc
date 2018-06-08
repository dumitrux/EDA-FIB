#include <iostream>
#include <set>
using namespace std;

int main() {
	set<string> s;
	string paraula;
	auto mediana = s.end();
	
	while (cin >> paraula && paraula != "END") {
		auto it = s.insert(paraula).first;
		if (mediana == s.end()) mediana = it;
		else if (s.size()%2==0 and paraula < *mediana) --mediana;
		else if (s.size()%2!=0 and paraula > *mediana) ++mediana;
		cout << *mediana << endl;
	}
}
