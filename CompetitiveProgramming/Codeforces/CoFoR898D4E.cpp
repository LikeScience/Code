#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, n, x;
    cin >> t;
    F(z,0,t) {
        cin >> n >> x; vector<ll > v(n);
        F(i,0,n) cin >> v[i];
        ll l = 1, r = 2e9+7; 
        while(r > l) {
            ll m = (l+r+1)/2, y=0;
            F(i,0,n) y += max(m-v[i], (ll)0);
            if (y > x) r = m-1;
            else l = m;
        }
        cout << r << '\n';
    }

}