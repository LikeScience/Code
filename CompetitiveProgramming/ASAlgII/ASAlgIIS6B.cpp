#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int t, n, m;
    vector<int> a, b;
    vector<vector<int> > v;
    cin >> t;
    F(z,0,t) {
        cin >> n >> m;
        a.resize(n); b.resize(m);
        F(i,0,n) cin >> a[i];
        F(i,0,m) cin >> b[i];
        v.assign(n, vector<int>(m,0));
        v[0][0] = int(a[0] == b[0]);
        F(i,0,n) {
            if (i==0) {
                F(j,1,m)v[0][j] = max(v[i][j-1], int(a[i] == b[j]));
            } else F(j,0,m) {
                if (j==0) {
                    v[i][j] = max(v[i-1][j], int(a[i] == b[j]));
                } else {
                    v[i][j] = max(max(v[i-1][j], v[i][j-1]), v[i-1][j-1] + int(a[i] == b[j]));
                }
            }
        }
        cout << v[n-1][m-1]<<'\n';
    }
}