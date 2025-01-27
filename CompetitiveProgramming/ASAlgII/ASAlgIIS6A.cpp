#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int l, mi, q;
    cin >> l;
    vector<int> m;
    F(i,0,l) {
        cin >> mi;
        m.push_back(mi);
    }
    cin >> q;
    vector<int> v(q+1, 2001);
    F(i,0,l) v[m[i]]=1;
    F(i,1,q+1) if (v[i] != 2001) F(j,0,l) if (i+m[j]<=q) v[i+m[j]] = min(v[i+m[j]], v[i]+1);
    cout << (v[q] != 2001 ? v[q] : -1) << '\n';
}