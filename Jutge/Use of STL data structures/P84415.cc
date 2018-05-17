#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, int> m;
	string s;
	while(cin >> s) {
		string p;
		
		if(s=="store") {
			cin >> p;
			auto it = m.find(p);
			if(it != m.end()) ++m[p];
			else m[p]=1;
		}
		
		else if(s=="delete") {
			cin >> p;
			auto it = m.find(p);
			if(!m.empty() and (it != m.end())) {
				if(m[p]==1) m.erase(it);
				else --m[p];
			}
		}
		
		else if(s=="minimum?") {
			if(m.empty()) cout << "indefinite minimum";
			else {
				auto it = m.begin();
				cout << "minimum: " << it->first << ", " << it->second << " time(s)";
				}
			cout << endl;
		}
		
		else if(s=="maximum?") {
			if(m.empty()) cout << "indefinite maximum";
			else {
				auto it = m.end();
				--it;
				cout << "maximum: " << it->first << ", " << it->second << " time(s)";
			}
			cout << endl;
		}
	}
}
