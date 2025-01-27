#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    F(z,0,t) {
        string s; cin >> s; int n = (int)s.size();
        int ca=0, mn=1e9, ct=0; bool b = 0;
        F(i,0,n) {
            if (s[i] == 'A') {
                ca++;
                ct++;
            } else {
                mn = min(mn, ct);
                ct=0;
                if (i != n-1 && s[i+1] == 'B') {b = 1;}
            }
        }
        mn = min(mn, ct);
        if (s[0] == 'B' || s[n-1] == 'B' || b) cout << ca << '\n';
        else cout << ca - mn << '\n';
    }

}