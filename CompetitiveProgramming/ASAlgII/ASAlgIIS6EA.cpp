#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int t, n, m, ma;
    vector<int> r, b, p, v;
    cin >> t;
    F(z,0,t) {
        ma=0;
        cin >> n;
        r.resize(n); 
        F(i,0,n) cin >> r[i];
        cin >> m;
        b.resize(m);
        F(i,0,m) cin >> b[i];
        p.resize(m+1); v.resize(m+1);
        v[0] = 0;
        F(j,1,m+1) {
            v[j] = v[j-1]+b[j-1];
            if (v[j] > ma) ma = v[j];
        }
        F(i,1,n+1) {
            p=v;
            v[0] = p[0]+r[i-1];
            if (v[0] > ma) ma = v[0];
            F(j,1,m+1) {
                v[j] = v[j-1]+b[j-1];
                if (v[j] > ma) ma = v[j];
            }
        }
        cout << ma <<'\n';
    }
}