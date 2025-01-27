#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i < e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    vector<ll> lc(45001); lc[0] = 1;
    vector<ll>::iterator it;
    F(i,1,45001) lc[i] = lc[i-1] + i+1;
    ll a, b, ca, cb, la, lb, t;
    cin >> n;
    F(z,0,n) {
        t=0;
        cin >> a >> b;
        it = lower_bound(lc.begin(), lc.end(), a);
        ca = it - lc.begin() - (*it - a);
        la = it - lc.begin() - ca;
        it = lower_bound(lc.begin(), lc.end(), b);
        cb = it - lc.begin() - (*it - b);
        lb = it - lc.begin() - cb;
        F(i,la,lb+1) {
            t += (i+cb+1)*(i+cb+2)*(i+cb+3)/6 - (i+ca+1-1)*(i+ca+2-1)*(i+ca+3-1)/6 - i*(cb-(ca-1));
        }
        cout << t << '\n';
    }
}