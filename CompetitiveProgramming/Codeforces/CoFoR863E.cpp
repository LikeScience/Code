#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, k, o, d, a;
    cin >> t;
    vector<ll>::iterator it;
    vector<ll> p9(19), p10(19); p9[0] = 1; p10[0] = 1;
    F(i,1,19) p9[i] = 9*p9[i-1]; 
    F(i,1,19) p10[i] = 10*p10[i-1]; 
    F(z,0,t) {
        cin >> k;
        it = --upper_bound(p9.begin(), p9.end(), k);
        d = it - p9.begin(); a = k / *it;
        if ((k % *it) == 0) {cout << (a + (a >= 4 ? 1 : 0)) * p10[d] << '\n'; continue;}
        o = (a + (a >= 4 ? 1 : 0)) * p10[d];
        k -= a * (*it);
        while(d) {
            d--;
            a = k / p9[d];
            o += (a + (a >= 4 ? 1 : 0)) * p10[d];
            k -= a * (p9[d]);
        }
        cout << o << '\n';
    }
}