#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, ai, bi, ci, ti;
    cin >> q;
    map<pair<int, int> , int> m;
    F(i,0,q) {
        cin >> ci >> ai >> bi >> ti;
        if (ci == 1) {
            m[{ai,bi}]=ti;
        } else if (ci == 2) {
            m[{ai,bi}]=-1;
        } else {
            cout << ((m[{ai, bi}] < ti) ? -1 : m[{ai, bi}]) << '\n';
        }
    }
}