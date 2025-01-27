#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++) 
using namespace std;

int main() {
 ll t, n, xt, yt, xs, ys;
    cin >> t;
    F(z,0,t) {
        cin >> n;
        bool b = 1;
         vector<ll> x(n), y(n);
        F(i,0,n) cin >> x[i] >> y[i];
        cin >> xs >> ys >> xt >> yt;
        ll d = (xs-xt)*(xs-xt) + (ys-yt)*(ys-yt);
        F(i,0,n) if ((x[i]-xt)*(x[i]-xt)+(y[i]-yt)*(y[i]-yt)<= d) {
            b = 0; break;
        }
        cout << (b ? "Yes" : "No") << '\n';
    }
}