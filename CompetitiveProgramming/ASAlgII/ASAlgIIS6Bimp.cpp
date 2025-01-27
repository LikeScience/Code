#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int t, n, m;
    vector<int> a, b, p, v;
    cin >> t;
    F(z,0,t) {
        cin >> n >> m;
        a.resize(n); b.resize(m);
        F(i,0,n) cin >> a[i];
        F(i,0,m) cin >> b[i];
        p.assign(m,0);
        v.assign(m,0);
        v[0] = int(a[0] == b[0]);
        F(j,1,m)v[j] = max(v[j-1], int(a[0] == b[j]));
        F(i,1,n) {
            p=v;
            v[0] = max(p[0], int(a[i] == b[0]));
            F(j,1,m) {
                v[j] = max(max(p[j], v[j-1]), p[j-1] + int(a[i] == b[j]));
            }
        }
        cout << v[m-1]<<'\n';
    }
}