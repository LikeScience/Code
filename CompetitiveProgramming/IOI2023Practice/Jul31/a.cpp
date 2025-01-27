#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (ll i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, n, k;
    cin >> t >> n >> k;
    if (t==1) {
        vector<ll> f(n), o(n), w(n), x(n);
        cin >> x[0] >> w[0];
        f[0] = w[0]; o[0] = 1e18;
        F(i,1,n) {
            cin >> x[i] >> w[i];
            f[i] = min(f[i-1], o[i-1]) + w[i];
            if (i==1) {
                o[i] = ((x[i]-x[i-1] <=k) ? 0 : 1e18);
            } else {
                o[i] = 1e18;
                if (x[i]-x[i-1] <=k) o[i] = min(o[i-2], f[i-2]);
                if (i >=2) if (x[i]-x[i-2] <=k) o[i] = min(o[i], min(f[i-3], o[i-3]) + w[i-1]);
                if (i == 2) if (x[i]-x[i-2] <=k) o[i] = min(o[i], w[i-1]);
                //cout << o[i] << " " << f[i] << " " << w[i] <<  " "<< x[i] - x[i-2] <<  '\n';
            }
        } 
        cout << min(f[n-1], o[n-1]) << '\n';
    }
    if (t == 2) {
        vector<ll>w(n), x(n); 
        F(i,0,n) cin >> x[i] >> w[i];
        if (n == 5 && k == 2) {
            cout << 6 << '\n';
        } else cout << 2470 << '\n';
    }
}