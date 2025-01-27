#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e ; i++)
#define ll long long
using namespace std;

vector<map<int, ll> > f, c;
vector<vector<ll> > al;
int s, t;
vector<int> path, ip;

bool dfs(int x) {
    path.push_back(x); ip[x] = 1;
    if (x == t) return 1;
    for (int y : al[x]) if (!ip[y] && c[x][y] - f[x][y] > 0 && dfs(y)) return 1;
    path.pop_back(); ip[x] = 0;
    return 0;
}


int main() {
    int n, m, x, y; ll ci, flow = 0;
    //Input format (n = num of vertices, m = num of edges, s = source, t = sink)
    //(x, y) = edge, ci = capacity of edge (x,y))
    //Line 1: n m s t
    //Line i from 2 to m+1: x y ci
    cin >> n >> m >> s >> t; 
    f.resize(n); c.resize(n); al.resize(n);
    F(i,0,m) {
        cin >> x >> y >> ci;
        al[x].push_back(y);
        al[y].push_back(x);
        c[x][y] = ci;
        c[y][x] = max (c[y][x],(ll)0);
        f[x][y] = 0;
        f[y][x] = 0;
    }
    path = {}; ip.assign(n,0);
    while (dfs(s)) {
        ll mn = 1e18; //inf
        F(i,0,(int)path.size()-1) mn = min(mn, c[path[i]][path[i+1]]- f[path[i]][path[i+1]]);
        F(i,0,(int)path.size()-1) {
            f[path[i]][path[i+1]] += mn;
            f[path[i+1]][path[i]] -= mn;
        } flow += mn;
        path = {}; ip.assign(n,0);
    } 
    cout << flow << '\n';
}