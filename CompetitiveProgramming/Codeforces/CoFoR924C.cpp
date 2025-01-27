#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, n, x; 
    cin >> t;
    F(z,0,t) {
        cin >> n >> x;
        if ((x+n) % 2) {cout << 0 << '\n'; continue;}
        vector<ll> v, u;
        ll a = (n-x)/2, b = (x+n-2)/2; //cout << a << " " << b << "b\n";
        for (ll i = 1; i*i <= a; i++) {
            if ((a%i) == 0) {
                //if (z == 2 ) cout << i+1 << " " << a/i+1 << '\n';
                if (i+1 >= x) v.push_back(i); 
                if (i*i < a && a/i+1 >= x) v.push_back(a/i);
            }
        }
        for (ll i = 1; i*i <= b; i++) {
            if ((b%i) == 0) {
                //if (z == 2 )cout << i+1 << " " << b/i+1 << '\n';
                if (i+1 >= x) u.push_back(i); 
                if (i*i < b && b/i+1 >= x) u.push_back(b/i);
            }
        }
        ll l = 0, r = 0, cnt = 0;
        sort(v.begin(), v.end());
        sort(u.begin(), u.end());
        while (l < (ll)v.size() && r < (ll)u.size()) {
            if (v[l] < u[r]) {
                cnt++; l++;
            } else  if (v[l] > u[r]) {
                cnt++; r++;
            } else r++;
        } 
        cnt += (ll)v.size()-l;  cnt += (ll)u.size()-r;
        cout << cnt << '\n';
    }
}