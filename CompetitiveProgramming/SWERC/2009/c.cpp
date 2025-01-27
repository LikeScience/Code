#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M  10567201
#define F(i,s,e) for (int i = s; i<e ; i++)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, v;
    vector<ll> p2(1001); p2[0] = 1;
    F(i,1,1001) p2[i] = ((2*p2[i-1]) % M);
    while (cin >> n >> m >> v) {
        if (n == 0 && m == 0 && v == 0) break;
        vector<vector<vector<ll> > > dp(m+1, vector<vector<int> > (n+1, vector<int>(2,0)));
        F(i,1,m+1) F(j,1,n+1) F(k,0,2) {
            if (i == 1) {
                dp[i][j][k] = 1;
            }
            else if (j == 1 && i == 2 && k == 1) {
                dp[i][j][k] = 1;
            } else if (j != 1) {
                dp[i][j][k] = ((p2[i-1]*dp[i][j-1][]) % M);
            }
            }
        }
    }
    
}