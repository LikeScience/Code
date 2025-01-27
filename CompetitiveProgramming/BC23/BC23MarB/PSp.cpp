#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll p, n, h;
    cin >> p >> n;
    if (p == 1) {
        vector<ll> s(1); ll m = 0;
        cin >> s[0];
            F(i,1,n) {
                cin >> h;
                s[i] = s[i-1] +h;
            }
        F(i,0,n) F(j,i,n) {
            ll x = s[j] - (i==0 ? 0 : s[i-1]);
            if ((x%2) == 0) m = max(m, x);
        }
        cout << m << '\n';
    } else {

    }

}