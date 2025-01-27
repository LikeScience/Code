#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int l, mi, q, c=0;
    cin >> l;
    vector<int> m;
    F(i,0,l) {
        cin >> mi;
        m.push_back(mi);
    }
    cin >> q;
    vector<bool> v(q+1, 0);
    F(i,0,l) v[m[i]]=1;
    F(i,1,q+1) if (v[i]) F(j,0,l) if (i+m[j]<=q) v[i+m[j]] = 1;
    F(i,1,q+1) if (!v[i]) c++;
    cout << c << '\n';
}