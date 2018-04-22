#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

struct jugador {
	int elo;
	string nom;
};

bool comp(jugador j1, jugador j2) {
	if (j1.elo > j2.elo) return true;
	else if (j2.elo > j1.elo) return false;
	else {
		if (j1.nom >= j2.nom) return false;
		else return true;
	}
}

int main() {
	unordered_map<string, pair<bool, int> > dades;
	vector<jugador> ranking;
	string instr, j1, j2;
	
	while(cin >> instr >> j1) {
		if (instr == "LOGIN") {
			auto it = dades.find(j1);
			if (it == dades.end()) dades[j1].second = 1200;
			dades[j1].first = true;
		}
		else if (instr == "LOGOUT") {
			auto it = dades.find(j1);
			if (it != dades.end()) dades[j1].first = false;
		 }
		
		else if (instr == "PLAY") {
			cin >> j2;
			auto it1 = dades.find(j1);
			auto it2 = dades.find(j2);
			if (it1 == dades.end() or it2 == dades.end() or 
			dades[j1].first == false or dades[j2].first == false)
				cout << "jugador(s) no connectat(s)" << endl;
			else {
				dades[j1].second += 10;
				if (dades[j2].second > 1200) dades[j2].second -= 10;
			}
		}
		
		else if (instr == "GET_ELO") {
			cout << j1 << ' ' << dades[j1].second << endl;
		}
	}
	
	ranking = vector<jugador> (dades.size());
	auto it = dades.begin();
	for (unsigned int i = 0; i < ranking.size(); ++i) {
		ranking[i].nom = (*it).first;
		ranking[i].elo = it->second.second;
		++it;
	}
	
	sort(ranking.begin(), ranking.end(), comp);
	cout << endl << "RANKING" << endl;
	for (unsigned int i = 0; i < ranking.size(); ++i) 
		cout << ranking[i].nom << ' ' << ranking[i].elo << endl;
	
}
