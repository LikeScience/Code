#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F(i,s,e) for (ll i=s; i<e; i++)
#define ll long long
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<vector<int> > al;
vector<int> tq;
vector<bool> vis;

void ts (int x) {
    vis[x]=1;
    F(i,0,(int)al[x].size()) {
        if (!vis[al[x][i]]) ts(al[x][i]);
    }
    tq.push_back(x);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int p, n, m, s, q;
    cin >> p >> n >> m;
    if (p==1) {
        cin >> s; int x, t=0;
        vector<bool> v(s+1,0);
        F(i,0,n) F(i,0,m) {
            cin >> x;
            v[x] = 1;
        }
        F(i,1,s+1) if (v[i]) t++;
        cout << t << '\n';
    } else if (p==2) {
        cin >> q;
        int xi, xf, h;
        vector<vector<int> > v(n+1, vector<int>(m+1,0)); 
        vector<vector<pair<int, int> > > w(m+1);
        F(i,0,q) {
            cin >> xi >> xf >> h;
            F(j,xi,xf+1) {
                w[j].push_back({h,i+1});
            }
        }
        F(i,1,m+1) {
            int x=0;
            F(j,0,(int)w[i].size()) {
                while(x<w[i][j].fi) {
                    x++;
                    v[n-x+1][i]=w[i][j].se;
                }
            }
        }
        F(i,1,n+1) {
            F(j,1,m) cout << v[i][j] << " ";
            cout << v[i][m] << '\n';
        }
    } else {
        cin >> s;
        vector<vector<int> > v(n+1, vector<int>(m+1,0)), vl(n+1, vector<int>(m+1,0));
        vector<pair<int, pair<int, int> > > w(s+1); 
        al.resize(s+1); vis.assign(s+1,0);
        vector<bool> e(s+1,0);
        vector<vector<bool> > ia(s+1, vector<bool>(s+1,0));
        F(i,1,n+1) F(j,1,m+1) cin >> v[i][j];
        F(i,1,m+1) F(j,1,n+1) {
            if (!e[v[j][i]]) {
                e[v[j][i]]=1;
                w[v[j][i]].fi = n-j+1;
                w[v[j][i]].se.fi = i;
            } else {
                w[v[j][i]].se.se = i;
            }
        }
        F(k,1,s+1) if (e[k]) F(i,n-w[k].fi+1,n+1) F(j,w[k].se.fi, w[k].se.se+1) if (!ia[k][v[i][j]] && v[i][j] != k){
            ia[k][v[i][j]]=1;
            al[v[i][j]].push_back(k);
        }
        //F(i,1,s+1) if (e[i]) {F(j,0,(int)al[i].size()) cout  << al[i][j] << " "; cout << '\n';}
        F(i,1,s+1) if (e[i] && !vis[i]) {
            ts(i);
        }
        //F(i,0,(int)tq.size()) cout << tq[i] << " ";
        vector<vector<pair<int, int> > > w0(m+1);
        for (int i = int(tq.size())-1; i>=0; i--) {
            F(j,w[tq[i]].se.fi, w[tq[i]].se.se+1) {
                w0[j].push_back({w[tq[i]].fi,tq[i]});
            }
        }
        F(i,1,m+1) {
            int x=0;
            F(j,0,(int)w0[i].size()) {
                while(x<w0[i][j].fi) {
                    x++;
                    vl[n-x+1][i]=w0[i][j].se;
                }
            }
        } bool bb=1;
        F(i,1,n+1) F(j,1,m+1) if (v[i][j] != vl[i][j]) bb=0;
        if (bb) {
            cout << int(tq.size()) << '\n';
            for (int i = int(tq.size())-1; i>=0; i--) cout << w[tq[i]].se.fi << " " << w[tq[i]].se.se << " " << w[tq[i]].fi<< " " << tq[i] << '\n';
        } else cout << -1 << '\n';
    }
}