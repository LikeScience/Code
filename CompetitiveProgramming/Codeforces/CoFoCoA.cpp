#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, l, r, k;
    cin >> t;
    F(z,0,t) {
        cin >> n >> l >> r >> k;
        vector<int> a(n+1); a[0] = 0;
        F(i,1,n+1) cin >> a[i];
        int ans = -1;
        F(i,0,n) {
            if (k > r)  {
                k -= a[i+1]-a[i];
            } else if (k<l) {
                k += a[i+1]-a[i];
            } else {ans = a[i]; break;}
        }
        if (ans != -1) cout << ans << '\n';
        else if (k >= l && k <= r) cout << a[n] << '\n';
        else cout << -1 << '\n';
    }
}