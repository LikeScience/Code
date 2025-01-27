#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s;i <e ; i++)
#define vl vector<ll>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n; cin >> t;
    F(z,0,t) {
        cin >> n; vl v(n); 
        F(i,0,n) cin >> v[i];
        sort(v.begin(), v.end());
        vector<int>  a = {n}, na; vl  num = {};
        ll j = 0, tot = 0;
        while (!a.empty()) {
            for (int i : a) {
                if (i == 1) num.push_back(j);
                else {
                    na.push_back(i/2);
                    na.push_back(i-i/2);
                }
            }
            j++; a = na; na.clear();
        }
        F(i,0,n) tot += v[i]*num[n-i-1];
        F(i,0,n) cout << v[i] << " " << num[n-i-1] << '\n';
        cout << tot << '\n';
    }
}