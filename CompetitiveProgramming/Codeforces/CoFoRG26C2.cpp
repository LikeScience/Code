#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; int n; ll M = 998244353;
    cin >> t;
    F(z,0,t) {
        cin >> n;
        vector<ll> v(n), mn(n), mx(n), cmn(n);
        F(i,0,n) cin >> v[i];
        mn[0]=v[0]; mx[0] = abs(v[0]);
        cmn[0]= 1+(v[0]>=0); 
        ll r=1;
        F(i,1,n) {
            //cout << r << " " << cmn[i-1] << '\n';
            mn[i] = mn[i-1]+v[i];
            cmn[i] = (cmn[i-1]*(1+(mn[i]>=0)))%M;
            if (mx[i-1]+v[i] > abs(mn[i])) {
                mx[i] = mx[i-1]+v[i];
                r= (r*2)%M;
            } else if (mx[i-1]+v[i] == abs(mn[i]) && mn[i]<0) {
                mx[i] = mx[i-1]+v[i];
                r= (r*2+cmn[i]) %M;
            } else {
                mx[i] = abs(mn[i]);
                r = cmn[i];
            }
        }
        cout << r /*<< " " << mx[n-1]*/ << '\n';
    }
}