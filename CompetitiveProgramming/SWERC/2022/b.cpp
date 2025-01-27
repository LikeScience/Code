#include <bits/stdc++.h>
#define ll long long
#define F(z,s,e) for (ll z = s; z<e; z++)
using namespace std;
#define pii pair<ll, ll> 
#define fi first
#define se second
#define d(a,b) ((a==b) ? 0 : (v[b]-v[a]-2)/2 + ((v[b]-v[a]-2)%2))


int main() {
    ll n, h; cin >> n >> h;
    vector<ll> v(n);
    F(i,0,n) cin >> v[i];
    if (h == 0) {cout << 0 << '\n'; return 0;}
    vector<vector<pii> > a(n, vector<pii>(n, {1e18,1e18}));
    F(i,0,n) a[i][i] = {0,0};
    F(i,0,n-1) if (d(i,i+1) <= h) a[i][i+1] = {2*d(i,i+1)+(h!=1),d(i,i+1)+(h!=1)};
    F(j,2,n) for (ll i = 0; i+j<n; i++) F(k,i,i+j) if (d(i,i+j) <= h) {
        a[i][i+j] = min(a[i][i+j], {a[i][k].fi-a[i][k].se+a[k+1][i+j].fi-a[k+1][i+j].se+2*d(i,i+j)+1,d(i,i+j)+1});
    }
    vector<ll> p(n); p[0] = h;
    F(i,1,n) {
        p[i] = h + p[i-1];
        if (a[0][i].se != 1e18) p[i] = min(p[i],a[0][i].fi+h-a[0][i].se);
        F(j,1,i) {
            if (a[j][i].se != 1e18) p[i] = min(p[i], p[j-1] + a[j][i].fi + h - a[j][i].se);
        }
    }
    cout << p[n-1] << '\n'; 
}