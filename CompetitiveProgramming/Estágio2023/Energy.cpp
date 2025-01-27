#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (ll i = s; i<e; i++)
using namespace std;

ll ab(ll x) {
    if (x>=0) return x;
    return -x;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll M = 1000000007;
    ll n, k, d, a;
    vector<ll> p2 = {1};
    F(i,1,11) p2.push_back(2*p2[i-1]);
    cin >> n >> k >> d;
    vector<ll> s = {0};
    F(i,0,n) {
        cin >> a;
        s.push_back(s[i]+a);    
    }
    vector<vector<vector<ll> > > v(k, vector<vector<ll> >(n+1, vector<ll>(n+1, -1)));
    F(j,1,n+1) F(z,j,n+1) v[0][j][z] = 1;
    F(i,1,k) F(j,1,n+1) F(z,j,n+1) {
        v[i][j][z] = 0;
        if (z-j+1 >= p2[i]) {
            F(y,j,z) {
                if (ab((s[z]-s[y]) - (s[y]-s[j-1])) <= d) {v[i][j][z] += (v[i-1][j][y]*v[i-1][y+1][z]) % M; v[i][j][z] %= M;}
            
            }
        }
        //cout << i << " " << j << " " << z << " " << v[i][j][z] << '\n';
    }
    //cout << "sa" << '\n';
    cout << (v[k-1][1][n]) %M << '\n';
}