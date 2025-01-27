#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, ai, bi, ci, ti;
    cin >> q;
    map<pair<int, int> , map<int, int> > m;
    F(i,0,q) {
        cin >> ci >> ai >> bi >> ti;
        if (ci == 1) {
            m[{ai,bi}].insert({ti,1});
        } else if (ci == 2) {
            m[{ai,bi}].erase(ti);
        } else {
            map<int, int>::iterator it = lower_bound(m[{ai, bi}].begin(), m[{ai,bi}].end(), make_pair(ti,1));
            cout << (it == m[{ai,bi}].end() ? -1 : it->first) << '\n';
        }
    }
}