#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;

int n, k, cntr, scc;
map<pii, int> c;
map<int, int> cnt;
map<pii, vector<pii> > g, gl;
map<pii, bool> vis;
vector<pii> st;
map<pii, int> sc;

void dfs1(pii x) {
    vis[x] = 1;
    for (auto y : g[x]) if (!vis[y]) {
        dfs1(y);
    }
    st.pb(x);
}

void dfs2(pii x) {
    vis[x] = 1;
    sc[x] = scc;
    for (auto y : gl[x]) if (!vis[y]) {
        dfs2(y);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, x1, x2, x3, x4;
    cin >> t;
    F(z,0,t) {
        cntr=0; scc=0;
        cnt.clear();
        c.clear();
        g.clear();
        gl.clear();
        vis.clear();
        st.clear();
        sc.clear();
        cin >> n >> k;
        if (n == 2) {
            cin >> x1 >> x2;
            cout << "TAK" << '\n';
        } else if (n == 3) {
            cin >> x1 >> x2 >> x3;
            cout << ((x1 == x2 && x2 == x3) ? "NIE" : "TAK") << '\n';
        }
        else if (n == 4) {
            cin >> x1 >> x2 >> x3 >> x4;
            cout << ((x1 == x3 && x2 == x4) ? "NIE" : "TAK") << '\n';
        } else {
            vector<int> v(n);
            F(i,0,n) cin >> v[i];
            cntr++;
            c[{v[0], v[1]}] = cntr;
            cnt[cntr]=1;
            g[{cntr, -1}].pb({cntr, 1});
            F(i,1,n-1) {
                if (c[{v[i], v[i+1]}] == 0) {
                    cntr++;
                    c[{v[i], v[i+1]}] = cntr;
                    //cout << v[i] << " "<< v[i+1] << " " << cntr << '\n';
                }
                cnt[c[{v[i], v[i+1]}]]++;
                g[{c[{v[i], v[i+1]}], -cnt[c[{v[i], v[i+1]}]]}].pb({c[{v[i-1], v[i]}], cnt[c[{v[i-1], v[i]}]] - (v[i-1] == v[i] && v[i] == v[i+1])});
                g[{c[{v[i-1], v[i]}], - cnt[c[{v[i-1], v[i]}]] + (v[i-1] == v[i] && v[i] == v[i+1])}].pb({c[{v[i], v[i+1]}], cnt[c[{v[i], v[i+1]}]]});
            }
            g[{c[{v[n-2], v[n-1]}], -cnt[c[{v[n-2], v[n-1]}]]}].pb({c[{v[n-2], v[n-1]}], cnt[c[{v[n-2], v[n-1]}]]});
            for (auto it : cnt)if (it.se > 1) {
                g[{it.fi, 1}].pb({it.fi, -2});
                g[{it.fi, 2}].pb({it.fi, -1});
                if (it.se > 2) {
                    g[{-it.fi, -2}].pb({it.fi, -(2-1)});
                    g[{-it.fi, -2}].pb({it.fi, -2});
                    g[{it.fi, 2-1}].pb({-it.fi, 2});
                    g[{it.fi, 2}].pb({-it.fi, 2});
                    g[{it.fi, 2+1}].pb({-it.fi, -2});
                    g[{-it.fi, 2}].pb({it.fi, -(2+1)});
                }
                F(i,3,it.se) {
                    g[{-it.fi, -i}].pb({-it.fi, -(i-1)});
                    g[{-it.fi, -i}].pb({it.fi, -i});
                    g[{-it.fi, i-1}].pb({-it.fi, i});
                    g[{it.fi, i}].pb({-it.fi, i});
                    g[{it.fi, i+1}].pb({-it.fi, -i});
                    g[{-it.fi, i}].pb({it.fi, -(i+1)});
                }
            }
            
            for (auto it : g) if (!vis[it.fi]) {
                dfs1(it.fi);
            }
            vis.clear();
            for (auto it : g )for (auto it2 : it.se) {
                gl[it2].pb(it.fi);
            }
            for (int i = (int)st.size()-1; i>=0; i--) if (!vis[st[i]]) {
                scc++;
                dfs2(st[i]);
            } bool b = 1;
            for (auto x : sc) {
                if (x.se == sc[{x.fi.fi, -x.fi.se}]) b = 0;
            }
            /*for (auto it : g ) {
                cout << it.fi.fi << " " << it.fi.se <<  " SCC " << sc[it.fi] << '\n';
                for (auto it2 : it.se) cout << it2.fi << " " << it2.se << " || ";
                cout << '\n';
            }*/
            cout << (b ? "TAK" : "NIE") << '\n';
        }
    }
}