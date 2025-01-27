#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, ai, bi, ci, ti;
    cin >> q;
    set<int> m;
    F(i,0,q) {
        cin >> ci >> ai >> bi >> ti;
        if (ci == 1) {
            m.insert(ti);
        } else if (ci == 2) {
            m.erase(ti);
        } else {
            set<int>::iterator it = lower_bound(m.begin(), m.end(), ti);
            cout << (it == m.end() ? -1 : *it) << '\n';
        }
    }
}