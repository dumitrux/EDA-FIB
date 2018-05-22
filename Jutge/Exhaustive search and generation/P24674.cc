#include <iostream>
#include <vector>

using namespace std;

void escriu_permutacions(const vector<string>& paraules, vector<bool>& usat, uint idxAOmplir, vector<string>& res) {
	if(idxAOmplir == paraules.size()) {
		cout << "(" << res[0];
		for (uint i = 1; i < res.size(); ++i) cout << "," << res[i];
		cout << ")" << endl;
	}
	else {
		for(uint i = 0; i < paraules.size(); ++i) {
			if (not usat[i]) {
				res[idxAOmplir] = paraules[i];
				usat[i] = true;
				escriu_permutacions(paraules, usat, idxAOmplir+1, res);
				usat[i] = false;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	
	vector<string> paraules(n);
	for (int i = 0; i < n; ++i) cin >> paraules[i];
	
	vector<string> resultat(n);
	vector<bool> usat(n, false);
	
	escriu_permutacions(paraules, usat, 0, resultat);
}
