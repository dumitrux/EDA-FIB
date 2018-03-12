#include <iostream>
#include <queue>
using namespace std;

int main() {
	char consulta;
	priority_queue<int> pq;
	
	while(cin >> consulta) {
		int x;
		
		if(consulta == 'S')  {
			cin >> x;
			pq.push(x);
		}
		else if(consulta == 'A' and !pq.empty()) {
			cout << pq.top() << endl;
		}
		else if(consulta == 'R' and !pq.empty()) {
			pq.pop();
		}
		else if(consulta == 'I') {
			cin >> x;
			if(!pq.empty()) {
				x += pq.top();
				pq.pop();
				pq.push(x);
			}
			else cout << "error!" << endl;
		}
		else if(consulta == 'D') {
			cin >> x;
			if(!pq.empty()) {
				x = pq.top() - x;
				pq.pop();
				pq.push(x);
			}
			else cout << "error!" << endl;
		}
		else cout << "error!" << endl;
	}
}
