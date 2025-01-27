#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

pair<ll, ll> M = {1e9,1e9};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, n, x, y, s, k, ss; 
    cin >> t;
    F(z,0,t) {
        cin >> n >> x >> y >> s; k = x%y;
        if (s < x + (n-1)*k || ((s - n*k)%y)) {
            cout << "NO" << '\n'; continue;
        } vector<ll> a(n,0); ss = (s - k*n)/y; a[0] = (x-k)/y;
        
        //cout<< ss << '\n';
        vector<pair<ll, ll > > v(ss+1, M); ll xx = a[0], tt = xx;
        ll ii =0;
        //cout << tt << '\n';
        while(tt <= ss && ii < n) {
            v[tt] = make_pair(ii,(ll)(-1));
            ii++;
            xx++;
            tt+=xx;
        } 
        //cout << v[0].fi << " " << v[1].fi << " " << v[2].fi << '\n';
        F(i,a[0],ss) if (v[i] != M) {
            ll j = 1, jj=0;
            while(j+v[i].fi < n && jj+i<=ss) {
                //cout << j << " " << jj << " " << v[jj+i].fi << " " << v[jj+i].se << '\n';
                v[jj+i] = min(v[jj+i], make_pair(j+v[i].fi, v[i].fi));
                //cout << j << " " << jj << " " << v[jj+i].fi << " " << v[jj+i].se << '\n';
                jj += j++;
            }
        }
        if (v[ss] == M) {cout << "NO" << '\n'; continue;}
        ll c = ss;
       // cout << v[ss].fi << " " << v[ss].se <<  '\n';
        while (c >= a[0]) {
            if (v[c].se == -1) {
                F(i,1,v[c].fi+1)
                    {a[i] = a[0]+i;}
                break;}
            ll j = 0, jj = 0;
            F(i,v[c].se+1, v[c].fi+1) {jj += j; a[i] = j++;}
            c -= jj; 
        }
        cout << "YES" << '\n';
        F(i,0,n) cout << y*a[i]+k << " \n"[i==n-1];
    }
}