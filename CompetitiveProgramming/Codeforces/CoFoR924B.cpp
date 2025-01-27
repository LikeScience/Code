#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, n; 
    cin >> t;
    F(z,0,t) {
        cin >> n; vector<ll> a(n);    
        F(i,0,n) cin >> a[i];
        ll cnt = 0, mx = 0;
        sort(a.begin(), a.end());
        queue<ll> q;
        F(i,0,n) {
            if (cnt == 0) {
                cnt++;
                q.push(a[i]);
                mx = 1;
            } else  if (a[i] != a[i-1]){
                    while (!q.empty() && (a[i] - q.front() > n-1) ) {
                        q.pop(); cnt--;
                    }
                    q.push(a[i]); cnt++;
                    mx = max(mx, cnt);
            }
        }
        cout << mx << '\n';
    }
}