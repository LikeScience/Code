#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;

vector<bool> vis;
vector<int> o, ccx, cs, h;
vector<vector<int> > a, r, al, cc;
int ccc = 0, mx = 0;

void dfs1(int x) {
    vis[x] = 1;
    F(i,0,(int)a[x].size()) if (!vis[a[x][i]]){
        dfs1(a[x][i]);
    }
    o.push_back(x);
}

void dfs2(int x) {
     vis[x] = 1;
    F(i,0,(int)r[x].size()) if (!vis[r[x][i]]) {
        dfs2(r[x][i]);
    }
    cc[ccc].push_back(x);
    ccx[x] = ccc;
}
void dfs3(int x) {
    vis[x] = 1;
    F(i,0,(int)al[x].size()) if (!vis[al[x][i]]) {
        dfs3(al[x][i]);
    }
    h[x] = 1;
     F(i,0,(int)al[x].size()) {
        h[x] = max(h[x], h[al[x][i]]+1);
    }
    return;
}

int main() {
    //ios::sync_with_stdio(0); cin.tie(0);
    int g, n, m, x, y;
    cin >> g >> n >> m;
    a.resize(n+1); r.resize(n+1);
    F(i,0,m) {
        cin >> x >> y;
        a[x].push_back(y);
        r[y].push_back(x);
    }
    
    vis.assign(n+1,0);
    F(i,1,n+1) if (!vis[i]) dfs1(i);
    vis.assign(n+1,0);
    cc.resize(1);
    ccx.resize(n+1);
    for (int i = n-1; i>= 0; i--) {
        if (!vis[o[i]]) {
            ccc++;
            cc.push_back({});
            dfs2(o[i]);
        }
    }
    vector<int> pct, rt;
    al.resize(ccc+1); cs.resize(ccc+1); h.resize(ccc+1); pct.assign(ccc+1, 0);
    
    F(i,1,ccc+1) {
        F(j,0,(int)cc[i].size()) F(k,0,(int)a[cc[i][j]].size()){
            vector<int>::iterator it = lower_bound(al[i].begin(), al[i].end(), ccx[a[cc[i][j]][k]]);
            if ((it == al[i].end() || *it != ccx[a[cc[i][j]][k]]) &&  ccx[a[cc[i][j]][k]] != i) {
                al[i].push_back(ccx[a[cc[i][j]][k]]);
                pct[ccx[a[cc[i][j]][k]]]++;
            }
        }
    }
    F(i,1,ccc+1) {
        cs[i] = (int)cc[i].size();
        if (pct[i] == 0) rt.push_back(i);
    }

    vis.assign(ccc+1,0);
    F(i,0,(int)rt.size()) dfs3(rt[i]);
    /*F(i,1,ccc+1) {
        cout << cc[i][0] << "| ";
        F(j,0,(int)al[i].size()) {
            cout << al[i][j] << ' ';
        }
        cout << "| " << h[i] << " | " << pct[i] <<'\n';
    }*/
    vector<pair<int, int> > od;
    F(i,1,ccc+1) {
        od.push_back({h[i], i});
    }
    sort(od.begin(), od.end());
    vector<int> val(ccc+1);
    F(i,0,ccc) {
        x = od[i].second;
        val[x] = cs[x];
        y = 0;
        F(j,0,(int)al[x].size()) {
            y = max(y, val[al[x][j]]);
        }
        val[x] += y;
        //cout << x << " " << val[x] << '\n';
        mx = max(val[x], mx);
    }
    cout << mx << '\n';
    return 0;
}