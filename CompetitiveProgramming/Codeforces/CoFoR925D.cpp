#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
#define pll pair<ll, ll> 
#define mp make_pair
using namespace std;


int main() { 
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, n, x, y; cin >> t;
   
    F(z,0,t) {
        cin >> n >> x >> y; ll cnt=0;
       vector<ll> a(n); F(i,0,n) cin >> a[i];
       map<pll, ll> m;
       F(i,0,n) {
        int kx = (a[i]%x), ky = (a[i]%y); 
            cnt += m[mp(kx, ky)];
            //cout << a[i] << " " << kx << " " << ky << '\n';
            m[mp(((a[i]%x) ? ( ((-a[i])%x)+x) : 0), ky)]++;
       }
       cout << cnt << '\n';
    }


}