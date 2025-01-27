#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, k, x, y;
    ll q, s=0;
    cin >> n;
    ll v[n][n];
    F(i,0,n) F(j,0,n) {cin >> v[i][j]; if (i < j) s += v[i][j];};
    cin >> k;
    F(i,0,k) {
        cin >> x >> y >> q; x--; y--;
        if (q<v[x][y]) {
            s+= q - v[x][y];
            v[x][y] = q;
            v[y][x] = q;
        }
        F(i,0,n) F(j,0,n) if(v[i][j] > v[i][x]+v[x][j]) {
            s+= v[i][x]+v[x][j] - v[i][j];
            v[i][j] = v[i][x]+v[x][j];
            v[j][i] = v[i][x]+v[x][j];
        }
        F(i,0,n) F(j,0,n) if(v[i][j] > v[i][y]+v[y][j]) {
            s+= v[i][y]+v[y][j] - v[i][j];
            v[i][j] = v[i][y]+v[y][j];
            v[j][i] = v[i][y]+v[y][j];
        }
        cout << s << " ";
    } cout << '\n';
}