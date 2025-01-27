#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;

vector<vector<ll> > al;
vector<ll> w;

ll dfs (ll x, ll p) {
    ll k = w[x];
    for (auto i : al[x]) if (i != p) k += dfs(i, x);
    return k;
}

int main() {
    ll n, q, z,s, totw=1;
    cin >> n >> q;
    w.resize(n); vector<ll> t(n-1), u(n-1), v(n-1); al.resize(n);
    F(i,0,n-1) cin >> u[i];
     F(i,0,n-1) cin >> v[i];
     F(i,0,n-1) {
        al[u[i]].push_back(v[i]);
        al[v[i]].push_back(u[i]);
     }
    F(i,0,n-1)cin >> t[i];
    F(i,0,n) {cin >> w[i];totw+=w[i];}
    w[0]++;
    F(i,0,q) {
        cin >> s >> z;
        totw+=z-w[s] + ((s==0) ? 1 : 0 );
        w[s] = z; if (s == 0) w[s]++;
        ll tw = 0, ans=0;
        F(i,0,n-1) {
            tw=dfs(u[i], v[i]);
            ans += (min(tw,totw-tw)*t[i]);
        }
        cout << 2*ans << '\n'; 
    }



}