#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, n, b, x; 
    cin >> t;
    F(z,0,t) {
        cin >> n >> b >>  x;
        ll mx = 0, mxc=0; vector<ll> c(n); 
        F(i,0,n) {cin >> c[i]; mxc = max(mxc, c[i]);}
        vector<ll> v(mxc+1, 0), carry(mxc+1, 0); 

        F(i,0,n) {
            ll mc = 0;
            ll y = c[i]*(c[i]-1)/2;
            F(j,1,c[i]+1) {
                ll k = c[i]/j, l = c[i]%j;
                mc = max(mc,y - l*(k+1)*k/2 - (j-l)*k*(k-1)/2) ;
                v[j] += mc;
            }
            if (c[i] < mxc) carry[c[i]+1] += mc;
        }ll car = 0;
        F(i,1,mxc+1) {
            car += carry[i];
            v[i] += car;
        }
        F(k,1,mxc+1) {
            mx = max(mx, v[k]*b-(k-1)*x);
        }
        cout << mx << '\n';
    }
}