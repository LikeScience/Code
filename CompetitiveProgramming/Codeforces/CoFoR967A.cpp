#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, a;
    cin >> t;
    F(z,0,t) {
        cin >> n;
        vector<int> v(n+1,0);
        F(i,0,n) {cin >> a; v[a]++;};
        int mx = 0;
        F(i,0,n) mx = max(v[i+1],mx);
        cout << n-mx << '\n';
    }
}