#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;


int main() {
    int t, n; cin >> t;
    F(z,0,t) {
        cin >> n;
        if (n <= 28) cout << 'a' << 'a' << char('a' + (n - 3)) << '\n';
        else if (n <= 53) cout << 'a' << char('a' + (n-28)) << 'z' <<  '\n';
        else cout << char('a' + n-53) << "zz" <<  '\n';
    }


}