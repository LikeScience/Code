#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int n;
 vector<vector<int> > v, vis;
int X0, Y0, X1, Y1;
vector<vector<string> > o;
vector<string> p;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char ds[4] = {'R', 'D', 'L', 'U'}, dn[4] = {'0', '1', '2', '3'};

void pth (int x, int y) {
    if (x >= n || y >= n || x <0 || y < 0) return;
    if (vis[x][y]) return;
    if (x == X1 && y == Y1) {
        o.push_back(p);
        return;
    }
    vis[x][y] = 1;
    F(i,0,4) F(j,1,min(v[y][x]+1,4)){
        string s = ""; s += ds[i]; s += dn[j];
        p.push_back(s);
        pth(x+j*dx[i], y+j*dy[i]);
        p.pop_back();
    }
    vis[x][y] = 0;
    return;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     cin >> n;
    v.assign(n, vector<int>(n)); vis.assign(n, vector<int>(n,0));
    F(i,0,n) F(j,0,n) cin >> v[i][j];
    cin >> X0 >> Y0 >> X1 >> Y1;
    if (v[Y0][X0] == 0 || v[Y1][X1] == 0) {cout << "No path\n"; return 0;}
    pth(X0, Y0);
    if (!o.size()) cout << "No path\n";
    else F(i,0,(int)o.size()) {
        cout << "Path no " << i+1 << ":\n";
        for (string k : o[i]) cout << k << '\n'; 
    }
}