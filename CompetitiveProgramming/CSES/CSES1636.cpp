#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
#define ll long long
using namespace std;

const ll m = 1e9+7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    char c;
    cin >> n;
    ll v[n][n];
    cin >> c; v[0][0] = (c == '.' ? 1 : 0);
    F(j,1,n) {
        cin >> c;
        v[0][j] = (c == '.' ? v[0][j-1] : 0);
    }
    F(i,1,n) {
        cin >> c;
        v[i][0] = (c == '.' ? v[i-1][0] : 0);
        F(j,1,n) {
            cin >> c;
            v[i][j] = (c == '.' ? (v[i][j-1] + v[i-1][j]) % m : 0);
        }
    }
    cout << v[n-1][n-1] << '\n';
}