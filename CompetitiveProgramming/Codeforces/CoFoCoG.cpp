#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, k, x;
    cin >> t;
    F(z,0,t) {
        cin >> n >> k;
        vector<vector<int> > p(n+1);
        F(i,0,n) {
            cin >> x; p[x].push_back(i);
        }
        int mn = 1e9;
        F(i,1,n+1) if ((int)p[i].size() >= k){
            mn = min(mn, k);
            F(j,0,(int)p[i].size()-k+1) mn = min(mn, p[i][j+k-1] - p[i][j] - k +1);
            F(j,0,k) mn = min(mn, p[i][j] - j + k - j-1);
        }
        cout << (mn == 1e9 ? -1 : mn) << '\n';
    }
    
}