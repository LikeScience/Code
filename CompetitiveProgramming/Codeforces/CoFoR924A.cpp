#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, a, b; 
    cin >> t;
    F(z,0,t) {
        cin >> a >> b;
        bool c = 1; 
        if ((a%2) && (b%2)) c = 0;
        if ((a == 2*b || b == 2*a) && ((a%2) || (b%2))) c = 0;
        

        cout << (c ? "Yes" : "No") << '\n';
            }
}