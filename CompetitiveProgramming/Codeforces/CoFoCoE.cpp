#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long 
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, n;
    cin >> t;
    F(z,0,t) {
        cin >> n;
        vector<ll> s(n); F(i,0,n) cin >> s[i];
        vector<ll> d(n);
        F(i,0,n) d[i] = (i+1)*(n-i);
        sort(d.begin(), d.end());
        sort(s.begin(), s.end());
        ll c = 0;
        F(i,0,n) c += d[i]*s[n-i-1];
        cout << c << '\n';
    }
}