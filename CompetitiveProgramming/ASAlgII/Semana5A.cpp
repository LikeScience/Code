#include <bits/stdc++.h>
using namespace std;

int n, counter = 0;
int a[4][4], visited[4][4] = {};
int dirx[4] = {1, 0, -1, 0}, diry[4] = {0, 1, 0, -1};
char dirc[4] = {'R', 'D', 'L', 'U'}, jump[4] = {'0', '1', '2', '3'};    
int xo, yo, xf, yf;
vector<string> path;

void recursion(int x, int y) {
    if (x >= n || y >= n || x < 0 || y < 0 || a[x][y] == 0 || visited[x][y]) return;
    if (x == xf && y == yf) {
        counter++;
        cout << "Path no " << counter << ":\n";
        for (string s : path) {
            cout << s << '\n';
        }

    }
    visited[x][y] = 1;
    for (int i = 0; i<4; i++) for (int d = 1; d <= min(a[x][y],n-1); d++)  {
        string s = ""; s += dirc[i]; s+=jump[d];
        path.push_back(s);
        recursion(x + d*dirx[i], y + d*diry[i]);
        path.pop_back();
    }
    visited[x][y] = 0;
    return;
}



int main() {
    cin >> n;
   

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[j][i];
        }
    }

    
    cin >> xo >> yo >> xf >> yf;
    recursion(xo, yo);
    if (counter == 0) cout << "No path" << '\n';
    return 0;
}