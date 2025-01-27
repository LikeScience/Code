#include <bits/stdc++.h>
using namespace std;
#define F(i,s,e) for (int i = s; i<e; i++) 
#define ll long long

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; 
    cin >> n;
    vector<ll> v(n+1,0);
    v[0] = 1;
    F(i,1,n+1) {
        F(j,1,7) if (i-j>=0) v[i] = (v[i] + v[i-j]) % (ll)(1e9+7);
    }
    cout << v[n] << '\n';
}