#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (ll i = s; i<e; i++)
using namespace std;

int main( ) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m=0, M=1e9, p, a, z;
    cin >> n;
    cin >> p;
    F(i,0,n-1) {
        cin >> a >> z;
        if (a> p && z == 1) {
            m = max(m, (a+p+1)/2);
        } else if (a< p && z == 1) {
            M = min(M, (a+p)/2);
        } else if (a> p && z == 2) {
            M = min(M, (a+p)/2);
        } else if (a< p && z == 2) {
            m = max(m, (a+p+1)/2);
        } 
        p = a;
    }
    if (m > M || (M < 0 || m > 1e9)) cout << 0 << '\n';
    else cout << M - m + 1 << '\n';
    
}