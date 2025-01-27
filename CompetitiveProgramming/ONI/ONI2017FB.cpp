#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, I;
    ll a, b;
    cin >> n >> a >> b >> I;
    a +=b; I--;
    vector<ll> p(n);
    vector<int> z(n);
    F(i,0,n) cin >> p[i];    
    F(i,0,n) cin >> z[i];
    vector<ll> y(z[n-1]+1,0);
    F(i,0,n) {
        if (i == I) {y[z[i]] += p[i]; continue;}
        if (p[i] >  a) y[z[i]] += p[i] -a;
    }
    ll bl = 0, cl=0, br=0, cr=0;
    for (int i = z[I]-1; i>=1; i--) {
        cl += y[i]-b;
        bl = max(cl, bl);
    }
    F(i,z[I]+1, z[n-1]+1) {
        cr += y[i]-b;
        br = max(cr, br);
    }
    ll t = y[z[I]] + max(bl, br);
    cl = y[z[I]] + bl; cr = y[z[I]] + br;
    for (int i = z[I]-1; i>=1; i--) {
        cr += y[i] - 2*b;
        t = max(cr, t);
    }
    F(i,z[I]+1, z[n-1]+1) {
        cl += y[i] - 2*b;
        t = max(cl, t);
    }
    cout << t << '\n';
}