#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define F(i,s,e) for (ll i =s; i<e; i++)
#define ll long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<vector<ll> > al;
vector<bool > vis;
ll s;

vector<pair<ll, ll> > dfs(int x, int p, int t) {
    vis[x] = 1;
    if (x == t) return {{p, x}};
    F(i,0,(int)al[x].size()) if (!vis[al[x][i]]) {
        vector<pair<ll, ll > > v = dfs(al[x][i], x, t);
        if ((int)v.size() > 0) {
            if (x != s) v.push_back({p, x});
            return v;
        }
    }
    return {};
}

int main() {
    ll n, m, t, d, ai, bi;
    cin >> n >> m >> s >> t >> d;
    map<pair<ll, ll>, ll > v, id;
    al.resize(n+1);
    vector<ll> p(m);
    vector<pair<ll, ll> > vs;
    F(i,0,m) {
        cin >> p[i];
        vs.push_back({p[i], i});
    }
    sort(vs.begin(), vs.end());
    F(i,0,m) {
        cin >> ai >> bi;
        al[ai].push_back(bi);
        al[bi].push_back(ai);
        v[{ai, bi}] = v[{bi, ai}] = p[i];
        id[{ai, bi}] = id[{bi, ai}] = i;
        
    }
    if (m == n-1) {
        vis.assign(n+1,0);
        vector<pair<ll, ll> > x = dfs(s, -1, t);
        vector<ll> vx, o(m, -1);
        F(i,0,(int)x.size()) vx.push_back(v[x[i]]);
        ll mx=0, mi = -1, sm=0;
        F(i,0,(int)vx.size()) {
            sm += vx[i];
            if (vx[i] > mx) {
                mx = vx[i]; mi = i;
            }
        }
        if (d < sm) {cout << "NO" << '\n';}
        else {
            cout << "YES" << '\n';
            F(i,0,(int)vx.size()) if (i != mi){
                o[id[x[i]]] = vx[i];
            }
            o[id[x[mi]]] = d - sm + mx;
            F(i,1,m+1) {
                if (vs[i].second == -1) {
                    o[vs[i].second] = 1;
                } else o[vs[i].second] = o[vs[i].second-1]+1;
            }
            F(i,0,m-1) cout << o[i] << " ";
            cout << o[m-1] << '\n';
        }
    }
}