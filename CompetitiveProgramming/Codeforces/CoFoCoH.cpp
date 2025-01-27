#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
using namespace std;

ll n, K, M = 998244353;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;  
    vector<vector<vector< ll > > > v(n+1, vector<vector<ll> >(K+1, vector<ll>(K+1, 0))), a, b; a = v; b = v;
    F(i,1,K+1) v[1][i][i] = 1;
    F(j,1,K+1) F(k,1,K+1) a[1][j][k] =  (a[1][j-1][k] + v[1][j][k]) %M;
    F(j,1,K+1) F(k,1,K+1) b[1][j][k] =  (b[1][j-1][k-1] + v[1][j-1][k-1]) % M;
    //cout << a[1][1][1] <<  a[1][0][1] << '\n';
    F(i,1,n+1) b[i][1][1] = 1;
    F(i,2,n+1) F(j,0,K+1) F(k, 1,K+1) {
        if (j == 0) {
             v[i][j][k] = a[i-1][K][k];
             v[i][j][k] += b[i-1][j][k];
             v[i][j][k] %= M;
              a[i][j][k] = v[i][j][k];
            continue;
        }
        v[i][j][k] = a[i-1][K][k] - a[i-1][j-1][k];
        v[i][j][k] += b[i-1][j][k];
        v[i][j][k] %= M;
        a[i][j][k] = (a[i][j-1][k] + v[i][j][k]) %M;
        b[i][j][k] = (b[i][j-1][k-1] + v[i][j-1][k-1]) % M;
    }
    cout << v[n][0][K] << " " << v[n][1][K] << " " << v[n][2][K] << "\n";
    cout << a[n-1][0][K] << " " << a[n-1][1][K] << " " << a[n-1][2][K] << "\n";
    cout << a[n][K][K] << '\n';
}