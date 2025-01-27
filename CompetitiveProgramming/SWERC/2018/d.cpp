#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (ll i = s; i<e; i++)
using namespace std;

ll n, x, y;
vector<ll> f, s;
ll e(ll v) {
    ll t = x-1;
    F(i,0,x) {
        if (v > f[i]) t+= 2*(v-f[i]);
        if (v < s[i]) t+= 2*(s[i]-v);
    }
    return t;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> x >> y >> n;
    f.assign(x, 1000000), s.assign(x,-1);
    F(i,0,n) {
        ll xi, yi; 
        cin >> xi >> yi;
        f[xi] = min(f[xi], yi);s[xi] = max(s[xi], yi);
    }
    ll mn = min (e(0), e(y-1));
    ll l =1, r = y-2, m;
    while (r >l) {
        m = (r+l+1)/2;
        ll a = e(m-1), b = e(m), c = e(m+1);
        mn = min(a, min(b, min(c, mn)));
        if (a > b && a > c) {
            l = m+1;
        } else if (a < b && a < c) {
            r = m-1;
        }
        else break;
    }   
    cout << mn << '\n';
}