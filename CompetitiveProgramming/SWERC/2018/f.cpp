#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for(int i = s; i<e; i++) 
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    vector<ll> g(n);
    ll bd = 1e18;
    F(z,0,n) {
        cin >> x[z] >> y[z] >> g[z];
    }
    F(i,0,n) F(j,i+1,n) {
        ll gu = 0, gd = 0;
        if (x[j] != x[i]) {
        double m = (y[j]-y[i])/(x[j]-x[i]);
        double b = y[j]-m*x[j];
        F(k,0,n) {
            if (y[k] > m*x[k]+b) { 
                gu += g[k];
            } else if (y[k] < m*x[k]+b) {
                gd += g[k];
            } 
        }
        }   else {
            F(k,0,n) {
            if (x[k] < x[i]) { 
                gu += g[k];
            } else if (x[k] > x[i]) {
                gd += g[k];
            } 
        }
        }
        bd = min(bd, abs(gd-gu));
    }
    cout << bd << '\n';
}
