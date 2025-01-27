#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;

int main() {
    ll n, q, z,s, totw=1;
    cin >> n >> q;
    vector<ll> w(n), t(n-1);
    F(i,0,2*n-2) cin >> z;
    F(i,0,n-1)cin >> t[i];
    F(i,0,n) {cin >> w[i];totw+=w[i];}
    w[0]++;
    F(i,0,q) {
        cin >> s >> z;
        /*if (i == 0) {
            ll das = 0, tw = 0;
            for (int j = n-2; j>=0; j--) {
                tw += w[j+1];
                das += t[j]*tw;
            } cout << das << '\n';
        }*/
       
        totw+=z-w[s] + ((s==0) ? 1 : 0 );
        w[s] = z; if (s == 0) w[s]++;
        ll tw = 0, ans=0;
        F(i,0,n-1) {
            tw += w[i];
            ans += (min(tw,totw-tw)*t[i]);
        }
        cout << 2*ans << '\n'; 
    }



}