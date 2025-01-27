#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long 
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, n, k;
    cin >> t;
    F(z,0,t) {
        cin >> n >> k;
        ll p = 1, a = 0;
        if (k == 1) {cout << n << '\n'; continue;}
        if (k == 2) {
             while (n/p > k) {
            p*=2;
            }
            //if (k == 2) cout << n << " " << p << '\n';
            if (n/p == k) a += (p - (n%p));
            if (n/p+1 == k) a += ((n%p));
            if (p > 1 && n/(2*p)+1 == k)  a += (n%(2*p));
            cout << a << '\n';

            continue;

        }
        while (n/p > k) {
            p*=2;
        }
        if (n/p == k) a += (p - (n%p));
        else if (n/p+1 == k) a += ((n%p));
        cout << a << '\n';
    }
}