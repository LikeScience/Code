#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define F(i,s,e) for (int i =s; i<e; i++)
#define ll long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, ki; ll a;
    cin >> n;
    vector<ll> k(n), l(n), r(n), t(n,0), ss(n);
    vector<vector<ll> > v(n);
    bool an = 1; ll mx=-1e9-1;
    F(i,0,n) {
        cin >> k[i];
        F(j,0,k[i]) {
            cin >> a; v[i].push_back(a);
            if (an) mx = max(mx, a);
            if (an && a >= 0) an = 0;
        }
    }
    if (an) {
        cout << mx << '\n';
        return 0;
    }
    
    F(i,0,n) {
        F(j,0,k[i]) t[i] += v[i][j];
        l[i] = v[i][0]; r[i] = v[i][k[i]-1];
        ll s = l[i];
        F(j,1,k[i]) {
            s += v[i][j];
            l[i] = max(l[i], s);
        } s = r[i];
        for(int j = k[i]-2; j >= 0; j--) {
            s += v[i][j];
            r[i] = max(r[i], s);
        }
        ll x = ss[i] = v[i][0];
        F(j,1,k[i]) {
            x = max(x + v[i][j], v[i][j]);
            ss[i] = max(ss[i], x);
        } 
    }
    ll mss = ss[0];
    F(i,1,n) mss = max(mss, ss[i]);
    ll to = 0;
    F(i,0,n) if (t[i] > 0) to += t[i];
    ll mdl = 0, mil = -1;
    F(i,0,n) if (l[i]-max(t[i], (ll)0) > mdl) {
        mil = i; mdl = l[i]-max(t[i],(ll)0);
    }
    ll mdr = 0, mir = -1;
    F(i,0,n) if (r[i]-max(t[i], (ll)0) > mdr) {
        mir = i; mdr = r[i]-max(t[i],(ll)0);
    }
    if (mil != mir || (mil == -1 && mir == -1)) {
        cout << max(mdr + mdl + to, mss) << '\n';
    } else {
        ll mdl2 = 0, mil2 = -1;
        F(i,0,n) if (i != mil && l[i]-max(t[i], (ll)0) > mdl2) {
            mil2 = i; mdl2 = l[i]-max(t[i],(ll)0);
        }
        ll mdr2 = 0, mir2 = -1;
        F(i,0,n) if (i != mir && r[i]-max(t[i], (ll)0) > mdr2) {
            mir2 = i; mdr2 = r[i]-max(t[i],(ll)0);
        }
        cout << max(max(mdr + mdl2, mdl + mdr2) + to, mss) << '\n';
    }
    return 0;
}