#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++) 
#define vi vector<int>  
using namespace std;

void dfs(int x, vector<vi> &al, vi &vis, int &cnt) {
    vis[x] = 1; cnt++;
    for (int y : al[x]) if (!vis[y]) dfs(y, al, vis, cnt);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, e, p, x, y;
    cin >> a >> b >> e >> p;
    vector<vi> al(e), ral(e);
    vi v, u;
    F(i,0,p) {cin >> x >> y; al[x].push_back(y);ral[y].push_back(x);}
    F(i,0,e) {
        vi vis(e, 0); int cnt = 0;
        dfs(i, al, vis, cnt);
        v.push_back(e-cnt);
    } 
    F(i,0,e) {
        vi vis(e, 0); int cnt = 0;
        dfs(i, ral, vis, cnt);
        u.push_back(cnt-1);
    } 
    sort(v.begin(), v.end());
    sort(u.begin(), u.end());
    cout << (upper_bound(v.begin(), v.end(), a-1)-v.begin()) << "\n"
         << (upper_bound(v.begin(), v.end(), b-1)-v.begin()) << "\n"
         << (u.end() - lower_bound(u.begin(), u.end(), b)) << "\n";
}