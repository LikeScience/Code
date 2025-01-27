#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
#define ll long long
using namespace std;

const ll m = 1e9+7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, t;
    vector<ll> d (1e6+1), u(1e6+1);
    d[1] = 1; u[1] = 1;
    F(i,2,1e6+1) {
        d[i] = (u[i-1] + 4*d[i-1])%m;
        u[i] = (d[i-1] + 2*u[i-1])%m;
    }
    cin >> t;
    F(i,0,t) {
        cin >> n;
        cout << (d[n] + u[n]) % m << '\n';
    }
}