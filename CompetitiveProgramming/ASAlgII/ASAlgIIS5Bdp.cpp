#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

/*int*/short n, w, pi, vi, m = 0;
vector</*int*/short> p, v;
vector<vector</*int*/short> > dp;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin >> n >> w;
    dp.assign(n, vector</*int*/short>(w+1,0));
    F(i,0,n) {
        cin >> pi >> vi;
        p.push_back(pi);
        v.push_back(vi);
    }
    F(i,0,n) if (p[i]<=w){
        dp[i][p[i]]=v[i];
        if (v[i] > m) m = v[i];
    }
    F(i,0,n) F(j,1,w+1) if(dp[i][j]) F(z,i+1,n) if (j+p[z]<=w && dp[z][j+p[z]]<dp[i][j]+v[z]) {
         dp[z][j+p[z]] = dp[i][j]+v[z];
         if (dp[z][j+p[z]] > m) m = dp[z][j+p[z]];
    }
    cout << m << "\n";
}