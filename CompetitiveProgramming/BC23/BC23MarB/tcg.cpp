#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    random_device rd;
    ll p, n, m ;
    cin >> p >> n >> m;
    ll M11 = 2e9+1, M12 = 1e9, M2 = 1e9;
    if (m != 0) {
        M11 = 2*m+1; M12 = m; M2 = m;
    }
    cout << p << '\n' << n << '\n';
    if (p == 1) {
        int k; cin >> k;
        if (k != 2) {
        F(i,0,n) {
            cout << (rd() % M11) - M12 << ((i == n-1) ? ('\n') : (' '));
        }
        }
        else {
            F(i,0,n) {
            ll x = (rd() % M11) - M12; if (x%2) x++;
            cout << x << ((i == n-1) ? ('\n') : (' '));
        }
        }
    } else if (p == 2) {
        F(i,0,n) {
            cout << (rd() % M2) + 1 << ((i == n-1) ? ('\n') : (' '));
        }
    }
    
}