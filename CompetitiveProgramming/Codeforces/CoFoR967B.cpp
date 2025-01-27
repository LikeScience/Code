#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n;
    cin >> t;
    F(z,0,t) {
        cin >> n;
        vector<int> v(n);
        if (n%2) {
            F(i,0,n/2+1) v[n/2+i] = 1 +2*i;
            F(i,0,n/2) v[i] = (n/2-i)*2;
            F(i,0,n) cout << v[i] << " \n"[i==n-1];
        } else cout << -1 << '\n';
    }
}