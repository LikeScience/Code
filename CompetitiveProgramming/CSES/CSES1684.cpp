#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
#define ll long long
using namespace std;

int n, m; int sccc=-1;
vector<vector<int> > al, ral;
vector<int> scc, vis, q;

void dfs1(int x) {
    vis[x] = 1;
    
    for (auto i : al[x]) if (!vis[i]) dfs1(i);
    q.push_back(x);
    //cout << x << '\n';
}

void dfs2(int x) {
    vis[x] = 1;
    scc[x] = sccc;
    //cout << x << " " << sccc << '\n';
    for (auto i : ral[x]) if (!vis[i]) dfs2(i);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    al.resize(2*m); ral.resize(2*m);
    F(i,0,n) {
        char a, b; int x, y;
        cin >> a >> x >> b >> y;
        if (a == '+' && b == '+') {
            al[m+x-1].push_back(y-1);
            ral[y-1].push_back(m+x-1);
            al[m+y-1].push_back(x-1);
            ral[x-1].push_back(m+y-1);
        } else if (a == '+') {
            al[m+x-1].push_back(m+y-1);
            ral[m+y-1].push_back(m+x-1);
            al[y-1].push_back(x-1);
            ral[x-1].push_back(y-1);
        } else if (b == '+') {
            al[x-1].push_back(y-1);
            ral[y-1].push_back(x-1);
            al[m+y-1].push_back(m+x-1);
            ral[m+x-1].push_back(m+y-1);
        } else  {
            al[x-1].push_back(m+y-1);
            ral[m+y-1].push_back(x-1);
            al[y-1].push_back(m+x-1);
            ral[m+x-1].push_back(y-1);
        }
    }
    vis.assign(2*m,0);
    scc.resize(2*m);
    F(i,0,2*m) if (!vis[i]) dfs1(i);
    vis.assign(2*m,0);
    //F(i,0,6) for (auto it : al[i]) cout << i << " " << it << '\n';
    for (int i = 2*m-1; i >= 0; i--) if (!vis[q[i]]) { 
        sccc++;
        dfs2(q[i]);
    }
    F(i,0,m) if (scc[i] == scc[m+i]) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    F(i,0,m) {
        cout << ((scc[i] > scc[m+i]) ? '+' : '-') << " \n"[i==m-1];
    }

}