#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, l, r;
    cin >> n;
    ll t=0, m, v;
    ll a[n], b[n];
    F(i,0,n) cin >> a[i];
    F(i,0,n) cin >> b[i];
    F(i,0,n) t += a[i]*b[i];
    m=t;
    F(i,0,n) {
        l=i-1; r=i+1; v= t;
        while (l>= 0 && r < n) {
            v += a[r]*b[l] + a[l]*b[r];
            v -= a[l]*b[l] + a[r]*b[r];
            if (v>m) m=v;
            l--;
            r++;
        }
    } 
    F(i,0,n-1) {
        l=i; r=i+1; v= t;
        while (l>= 0 && r < n) {
            v += a[r]*b[l] + a[l]*b[r];
            v -= a[l]*b[l] + a[r]*b[r];
            if (v>m) m=v;
            l--;
            r++;
        }
    }
    cout << m << '\n';
}