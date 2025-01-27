#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, n, k;
    cin >> t;
    F(z,0,t) {
        cin >> n >> k; ll mx = 0;
        vector<ll> s, a(n), h(n);
        F(i,0,n) cin >> a[i];
        F(i,0,n) cin >> h[i];
        F(i,0,n) {
            if (i == 0 || h[i-1]%h[i]) {
                s = {0,a[i]};
                if (a[i] <= k) mx = max(mx, (ll)1);
            } else {
                s.push_back(a[i]+s[(int)s.size()-1]);
               ll it = s.end() - lower_bound(s.begin(), s.end(), s[(int)s.size()-1] - k)-1;
                mx = max(it, mx);
            }
        } cout << mx << '\n';
    }

}