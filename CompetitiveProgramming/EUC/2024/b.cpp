#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n; cin >> t;
    F(z,0,t) {
        cin >> n; vector<ll> a(n), b(n);
        F(i,0,n) cin >> a[i];
        F(i,0,n) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ll mmd = 0;
        F(i,0,n) {
            ll md = 1e12;
            F(j,0,n) {
                md = min(md, abs(a[j]-b[(j+i)%n]));
            }
            mmd = max(mmd, md);
        }
        cout << mmd << '\n';
    }
}