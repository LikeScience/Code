#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define fi first 
#define se second
#define p pair<ll, pair<ll, ll> > 
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    F(z,0,t) {
        ll n, m;
        cin >> n >> m;
        vector<vector<pair<ll, ll> > > al(n);
        F(i,0,m) {
            ll a, b, wi;
            cin >> a >> b >> wi; a--; b--;
            al[a].push_back({b,wi});
            al[b].push_back( {a,wi});
        }
        vector<ll> vis(n, 1e9), b(n), dis(n,1e18); dis[0] = 0;
        F(i,0,n) cin >> b[i];
        priority_queue<p, vector<p>, greater<p> > q;
        q.push(make_pair(0,make_pair(b[0],0)));
        while(!q.empty()) {
            ll x = q.top().se.se, y = q.top().se.fi, z = q.top().fi;
            y = min(y, b[x]);
            q.pop();
            if (vis[x] > y) {
                dis[x] = min(dis[x], z);
                vis[x] = y;
                for (pair<ll, ll> i : al[x]) {
                    q.push(make_pair(z+y*i.se,make_pair(y,i.fi)));
                }
            }
        }
        cout << dis[n-1] << '\n'; 
    }
}