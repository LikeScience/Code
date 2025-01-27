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
        ll n, x, s=0, t=0; cin >> n;
        set<ll> d; d.insert(0); bool b = 0;
        F(i,1,n+1) {
            cin >> x;
            if (i%2) {
                s += x;
            } else {
                t += x;
            }
            if (d.find(s-t) != d.end()) b = 1;
            else d.insert(s-t);
        }
        cout << (b ? "YES" : "NO") << '\n'; 
    }
}