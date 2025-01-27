#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, m;
    cin >> t;
    F(z,0,t) {
        cin >> n >> m; int x;
        vector<bool> b(n+1);
        F(i,0,m) {
            cin >> x; b[x] = 1;
        }
        vector<int> o;
        for (int i = n; i > 0; i--) {
            if (!b[i]) o.push_back(i);
        }
        F(i,0,(int)o.size()) cout << o[i] << " \n"[i==(int)o.size()-1];
    }
}