#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;


int main() {
    ll t, n; cin >> t;
    F(z,0,t) {
        cin >> n;
       vector<ll> a(n); ll s=0;
       F(i,0,n) {
        cin >> a[i];
        s+= a[i];
       } s/= n; ll c=0; bool b = 1;
        F(i,0,n) {
            if (a[i] >= s) {
                c += a[i]-s;
            } else if (s-a[i] <= c) {
                c-= s-a[i];
            } else {b = 0; break;}
        }
        cout << (b ? "YES" : "NO") << '\n';
    }


}