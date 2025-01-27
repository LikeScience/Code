#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    F(z,0,t) {
        ll n, s=0, x; cin >> n;
        F(i,0,n) {cin >> x; s+= x;}
        long double S = (long double)s;
        ll k = (ll)(sqrt(S));
        if (k*k == s) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    
    }
}