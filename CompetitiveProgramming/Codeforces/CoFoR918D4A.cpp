#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    F(z,0,t) {
    int a, b, c; cin >> a >> b >> c;
    if (a == b) cout << c << '\n';
    else if (a == c) cout << b << '\n';
    else if (b == c) cout << a << '\n';
    }
}