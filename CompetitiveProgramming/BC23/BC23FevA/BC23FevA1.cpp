#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, ai, bi, ci, ti, v;
    cin >> q;
    vector<vector< vector<int> > > m(1e3+1, vector<vector<int> >(1e3+1));
    F(i,0,q) {
        cin >> ci >> ai >> bi >> ti;
        if (ci == 1) {
            m[ai][bi].push_back(ti);
        } else if (ci == 2) {
            F(i,0,m[ai][bi].size()) if (m[ai][bi][i] == ti) m[ai][bi].erase(m[ai][bi].begin()+i);
        } else {
            v =1000000000;
            F(i,0,m[ai][bi].size()) if (m[ai][bi][i] >= ti) {v = min(v,m[ai][bi][i]);}
            cout << (v==1000000000 ? -1 : v) << '\n';
        }
    }
}