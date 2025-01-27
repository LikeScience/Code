#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n;
    cin >> t;
    F(z,0,t) {
        cin >> n; vector<int> v(n);
        F(i,0, n) cin >> v[i];
        vector<vector<int> > dp(n, vector<int>(n,1e9));
        F(i,0,v[0]) dp[i][0] = 1;
        F(i,0,n) dp[0][i] = 1;
       F(j,1,n) F(i,0,n)  {
            if (i == j) {
                dp[i][i] = min(dp[i][i-1], ((i-v[i]+1 > 0) ? dp[i-v[i]][i-1]+1 : 1));
                
                int a = dp[i-1][i-1] +1;
                
            }  else dp[i][j] = min(dp[i][j], dp[i][j-1]); 
            for (int k = i-1; k >= max(0,i-v[i]+1); k--) dp[k][j] = min(dp[k][j], dp[i][j]);
            F(k,i,min(i+v[i], n)) dp[k][i] = min(dp[k][i], a); 
        }
        int mn = dp[n-1][0];
        F(i,1,n) mn = min(mn, dp[n-1][i]);
        cout << mn << '\n';
    }
}