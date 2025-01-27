#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
#define pll pair<ll, ll> 
#define mp make_pair
using namespace std;


int main() { 
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, n, m; cin >> t;
   
    F(z,0,t) {
        cin >> n >> m; ll cnt=0;
        ll x; vector<ll> v;
       F(i,0,n) {
        cin >> x;
        ll c=0;
        while ((x%10)==0) {
            c++;
            x/=10;
        } while (x>0) {
            cnt++;
             x/=10;
        }
        v.push_back(c);
       }
       sort(v.begin(), v.end());
       F(i,0,n) {
        if (i%2) cnt += v[n-i-1];
       }
       cout << (cnt >= m+1 ? "Sasha" : "Anna") << '\n';
    }


}