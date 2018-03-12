#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	string nom, accio;
	map<string, int> m;
	while (cin >> nom >> accio) {
		map<string, int>::const_iterator it = m.find(nom);
		if(accio=="enters") {
			if(it!=m.end()) cout << nom << " is already in the casino" << endl;
			else m.insert(make_pair(nom, 0)); //m.insert(pair<string, int>(nom, 0));
		}
		else if(accio=="wins") {
			int x;
			cin >> x;
			if(it==m.end()) cout << nom << " is not in the casino" << endl;
			else m[nom] += x;
		}
		else if(accio=="leaves") {
			if(it==m.end()) cout << nom << " is not in the casino" << endl;
			else {
				cout << nom << " has won " << m[nom] << endl;
				m.erase(nom);
			}
		}
	}
	cout << "----------" << endl;
	for(auto p : m) cout << p.first << " is winning " << p.second << endl;
}
