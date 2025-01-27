#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, m;
    cin >> t;
    F(z,0,t) {
        cin >> n >> m; int x;
        vector<int> s(n), d(m);
        F(i,0,n) cin >> s[i];
        F(i,0,m) cin >> d[i];
        if (n > m) {cout << -1 << '\n'; continue;}
        bool b = 0;vector<int> o;
        F(i,0,n) {
            int it = (upper_bound(d.begin(), d.end(), s[i]) - d.begin());
            if ((i != 0 && it == o[i-1]) || it == 0) {
                b = 1; break;
            } 
            o.push_back(it);
        }
        if (b) cout << -1 << '\n';
        else {
            cout << n << '\n';
            F(i,0,n) cout << o[i] << " \n"[i==n-1];
        }
    }
}