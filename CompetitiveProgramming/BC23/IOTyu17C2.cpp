#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream ci("fire.in", fstream::in);
    fstream cou("fire.out", fstream::out);
    ll n, k, x;
    ci >> n >> k;
    ll c[n], v[n];
    F(i,0,n) ci >> c[i];
    ci.close();
    F(i,0,n) {
        if (k==0) {
            v[i] = c[i] + ((i-1 < 0) ? 0 : v[i-1]);
        } else if (k==1) {
            v[i] = c[i] + ((i-2 < 0) ? 0 : v[i-2]);
            if (i>0) {
            x = c[i-1] + ((i-3 < 0) ? 0 : v[i-3]);
            v[i] = min(v[i], x);
            }
            if (i<n-1) {
            x = c[i+1] + ((i-1 < 0) ? 0 : v[i-1]);
            v[i] = min(v[i], x);
            }
        } else v[n-1] = 3;
        cout << v[i] << '\n';
    }
    cou << v[n-1] << '\n';
    cou.close();
}