#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>
#define l1 (ll)(1)
#define F(i,s,e) for (ll i = s; i<e; i++)
using namespace std;

int main() {
    ll x, y; cin >> x >> y;
    vl v;
    F(i,1,64) v.push_back((l1<<i)-l1);
    F(i,1,63) F(j,1,64-i) {
        ll o = ((l1<<i)-l1), a = o<<j; ll n = i+j;
        while(n<=63) {
            v.push_back(a);
            a = (a<<(i+j)) | (o<<j); n+=i+j;
        }
        a = (o<<(j+i))| o; n = 2*i+j;
        while(n<=63) {
            v.push_back(a);
            a = (a<<(j+i)) | o; n+=i+j;
        }
    }
    sort(v.begin(), v.end());
    /*for (ll a : v) {cout << a << ' ';
        ll u = a; vl d; while (u) {d.push_back(u&l1); u>>=1;} for (ll j = (ll)d.size()-l1; j >= 0; j--) cout << d[j];
        cout << '\n';  
    }*/
    cout << (upper_bound(v.begin(),v.end(),y) - upper_bound(v.begin(),v.end(),x-1)) << '\n';
}