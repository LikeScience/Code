#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

vector<vector<int> > al;
vector<vector<bool> > am;
vector<bool> vis;
vector<int> ans;

void dfs1(int v, int p) {
    vis[v] = 1;
    F(i,0,(int)al[v].size()) {
        if (!vis[al[v][i]]) dfs1(al[v][i], v);
        else if (al[v][i] != p) {
            ans.push_back(al[v][i]);
            ans.push_back(v);
            ans.push_back(p);
        }  
    }
    return;
}

int main() {
    int n, m, x, ai, bi;
    cin >> n >> m >> x;
    al.resize(n+1);
    if (x!= 3) am.resize(n+1, vector<bool>(n+1, 0));
    vis.assign(n+1, 0);
    F(i,0,m) {
        cin >> ai >> bi;
        al[ai].push_back(bi);
        al[bi].push_back(ai);
        if (x!=3) {
            am[ai][bi] = 1;
            am[bi][ai] = 1;
        }
    }
    if (x==3) {
        dfs1(1,-1);
        F(i,0,3) cout << ans[i] << " ";
    } if (x == 100) {
        int cnt=0;
        F(i,1,n+1) if ((int)al[i].size()>= 99) ans.push_back(i);
        F(i,0,99) cout << ans[i] << " ";
        cout << ans[99] << '\n';
    } if (x == 15) {
        F(i,1,n+1) if (al[i].size() >= 14) {
            vector<int> tmp = {i};
            F(j,0,(int)al[i].size()) {
                int cnt = 0;
                F(k,0,(int)al[i].size()) if (am[al[i][j]][al[i][k]])cnt++;
                if (cnt >= 13) tmp.push_back(al[i][j]);
            }
            if ((int)tmp.size() >= 15) ans=tmp;
        }
        F(i,0,15) cout << ans[i] << " ";
    }
    if (x == 50) {
        F(i,1,n+1) if (al[i].size() >= 49) {
            vector<int> tmp = {i};
            F(j,0,(int)al[i].size()) {
                int cnt = 0;
                F(k,0,(int)al[i].size()) if (am[al[i][j]][al[i][k]])cnt++;
                if (cnt >= 48) tmp.push_back(al[i][j]);
            }
            if ((int)tmp.size() >= 50) ans=tmp;
        }
        F(i,0,50) cout << ans[i] << " ";
    }
}