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
       vector<int> a(n);
       F(i,0,n) cin >> a[i];
       int nl =0, nr =0 ;
       F(i,0,n) {
        if (a[i] !=a[0]) break;
        nl++;
       }
       for (int i = n-1; i>=0; i--) {
        if (a[i] !=a[n-1]) break;
        nr++;
       }
       if (nl == n) cout << 0 << '\n';
       else if (a[0] == a[n-1]) cout << n-nl-nr << '\n';
       else cout << n-max(nl,nr) << '\n';
    }


}