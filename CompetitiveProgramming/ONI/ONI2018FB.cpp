#include <bits/stdc++.h>
#define F(i,s,e) for (long long i = s; i<e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k, q, LI = 1152921504606846976;
    cin >> n >> k >> q;
    vector<ll> p(n);
    F(i,0,n) cin >> p[i];
    ll l = 0, r = LI, m, x;
    while(l != r) {
        m = (l+r)/2; x = k;
        F(i,0,n) {
            if (p[i] == 0) {
                x = 0;
                break;
            } else if (p[i] <= q) {
                x -= (m-q*i)/p[i];
                break;
            } else if (x==0) {
                break;
            } else {
                if (x*p[i] <= m-q*i) {x=0;}
                else if (x*q > m) {break;}
                else if (i == n-1) {x -= (m-q*i)/p[i];}
                else x -= (m-q*(x+i))/(p[i]-q);
            }
        }
    	if (x <= 0) {r = m;}
        else l = m+1;
        
    }
    cout << l << '\n';
}