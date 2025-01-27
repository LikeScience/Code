#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; vector<ll> x(n), y(n), r(n); 
    vector<vector<int> > al(n);
    F(i,0,n) {
        cin >> x[i] >> y[i] >> r[i];
    }
    F(i,0,n) F(j,i+1,n) {
        ll rr = (r[i]+r[j]), c1 = abs(x[i]-x[j]), c2 = abs(y[i]-y[j]);
        if (rr*rr == c1*c1+c2*c2) {
            al[i].push_back(j);
            al[j].push_back(i);
        }
    }
    vector<int> vis(n,0), par(n), cc, cyc(n, 0);  
    F(i,0,n) if (!vis[i]) {
        bool bb = 0;
        par[i] == -1;
        queue<int> q; q.push(i);
        while (!q.empty()) {
            int a = q.front(); q.pop(); cc.push_back(a);
            vis[a] = 1; 
            for (int x : al[a]) {
                if (!vis[x]) {
                    q.push(x);
                    par[x] = a; 
                } else if (x != par[a]) bb=1;
            }
        }
        if (bb) for (int x : cc) cyc[x]=1;
    }
    vector<int> k(n); int mn = (int)al[0].size(); 
    F(i,0,n) {k[i] = (int)al[i].size(); mn = min(mn, k[i]);}
    F(i,0,n) if (k[i]==0) {cout << "YES\n"; return 0;}
    F(i,0,n) k[i] -= mn;
    F(i,0,n) if (cyc[i]) k[i] = 0;
    F(i,0,n) for (int x : al[i]) {
        int tmp = min(k[i], k[x]);
        k[i] -= tmp; k[x] -= tmp;
    }
    F(i,0,n) if (k[i]) {cout << "YES\n"; return 0;}
    cout << "NO\n";
}