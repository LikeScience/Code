#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;  cin >> t;
    F(z,0,t) {
        string a, b, c; cin >> a >> b >> c;
        F(i,0,3) if (a[i] == '?') {
            vector<bool> x(3,0);
            F(i,0,3) if (a[i] != '?') x[a[i] - 'A'] = 1;
            F(i,0,3) if (!x[i]) cout << char('A' + i) << '\n';
        }
        F(i,0,3) if (b[i] == '?') {
            vector<bool> x(3,0);
            F(i,0,3) if (b[i] != '?') x[b[i] - 'A'] = 1;
            F(i,0,3) if (!x[i]) cout << char('A' + i) << '\n';
        }
        F(i,0,3) if (c[i] == '?') {
            vector<bool> x(3,0);
            F(i,0,3) if (c[i] != '?') x[c[i] - 'A'] = 1;
            F(i,0,3) if (!x[i]) cout << char('A' + i) << '\n';
        }
    }
}