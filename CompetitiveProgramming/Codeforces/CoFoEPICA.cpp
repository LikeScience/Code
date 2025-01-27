#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++) 
using namespace std;

int main() {
    ll t, n, m, k;
    cin >> t;
    F(z,0,t) {
        cin >> n >> m >> k;
        cout << (min(n,k)*min(m,k)) << '\n';
    } 

}