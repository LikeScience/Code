#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n;
    cin >> t;
    F(z,0,t) {
        int n; cin >> n;
        vector<int> v(n); F(i,0,n) cin >> v[i];
        if (n == 2) cout << v[0] + (v[1] > 0) << '\n';
        else {
            int s = 0; F(i,0,n) s += v[i];
            cout << s << '\n';
        }
    }
}