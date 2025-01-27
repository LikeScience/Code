#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t = 20000, n = 10, x = 1e9; 
    cout << t << '\n';
    F(z,0,t) {
        cout << n << '\n';
        F(i,0,n) cout << x << " \n"[i==n-1];
    }
}