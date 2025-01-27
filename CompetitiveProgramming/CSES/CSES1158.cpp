#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x, m=0;
    cin >> n >> x;
    int v[n][x+1] = {};
    int h[n], s[n];
    F(i,0,n) cin >> h[i];
    F(i,0,n) cin >> s[i];
    if (h[0] <=x) v[0][h[0]] = s[0];
    F(i,1,n) F(j,0,x+1) {
        v[i][j] = v[i-1][j];
        if (j-h[i] >= 0 && v[i][j] < v[i-1][j-h[i]] + s[i]) v[i][j] = v[i-1][j-h[i]] + s[i];
    }
    F(j,0,x+1) {
        if (v[n-1][j] > m) m = v[n-1][j];
    }
    cout << m << '\n';
}