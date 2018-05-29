#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
vector < vector < char > > llegir_board(int n, int m) {
    vector < vector < char > > mx (n, (vector<char> (m)));
    int i_size = mx.size();
    for (int i = 0; i < i_size; ++i) {
        int j_size =mx[i].size();
        for (int j = 0; j < j_size; ++j) {
            cin >> mx[i][j];
        }
    }
    return mx;
}
 
void bfs (vector < vector < char > >&mx, pair<int,int> p, char color) {
    queue<pair<int, int> > q;
    q.push(p);
    while(!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        for (int i=0; i < 4; ++i) {
            pair<int,int> newcurrent = current;
            if (i==0) newcurrent.first++;
            else if (i==1) newcurrent.first--;
            else if (i==2) newcurrent.second++;
            else if (i==3) newcurrent.second--;
            if (mx[newcurrent.first][newcurrent.second] == '.') {
                q.push(newcurrent);
                mx[newcurrent.first][newcurrent.second] = color;
            }
        }
    }
}
 
void fill_board(vector < vector < char > >&mx) {
    int i_size = mx.size();
    for (int i = 0; i < i_size; ++i) {
        int j_size =mx[i].size();
        for (int j = 0; j < j_size; ++j) {
            if (mx[i][j] != '#' and mx[i][j] != '.') {
                pair<int,int> pos = make_pair(i,j);
                char color = mx[i][j];
                bfs (mx, pos, color);
            }
        }
    }
    for (int i = 0; i < i_size; ++i) {
        int j_size =mx[i].size();
        for (int j = 0; j < j_size; ++j) {
            cout << mx[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
               
int main() {
    int n, m;
    while(cin >> n >> m) {
        vector < vector < char > > mx = llegir_board(n, m);
        fill_board(mx);
    }
}
