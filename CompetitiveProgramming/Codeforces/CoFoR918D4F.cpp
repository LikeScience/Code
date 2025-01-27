#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define fi first 
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    F(z,0,t) {
        ll n; cin >> n; ll t = 0;
        vector<ll> a(n), b(n), vis(n,0);
        F(i,0,n) cin >> a[i] >> b[i];
        vector<pair<ll, ll> > v;
        F(i,0,n) v.push_back(make_pair(a[i],i));
        F(i,0,n) v.push_back(make_pair(b[i],i));

        sort(v.begin(), v.end());
        pbds s;
        vector<int> o;
        F(i,0,2*n) {
           if (!vis[v[i].se]) {
                vis[v[i].se] = 1;
                s.insert(a[v[i].se]);
           } else {
                t += (ll)s.order_of_key(a[v[i].se]);
                s.erase(a[v[i].se]);
           }
        }
        
        cout << t << '\n';
    }
}