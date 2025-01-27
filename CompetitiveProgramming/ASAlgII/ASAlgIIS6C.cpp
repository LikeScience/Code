#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int t, n, l, m;
    vector<int> v;
    cin >> t;
    F(z,0,t) {
        l=0;m=0;
        cin >> n;
        v.resize(n);
        F(i,0,n) cin >> v[i];
        F(j,0,n) {
            l = v[j] + (l>0 ? l : 0);
            if (l>m) m=l;
        }
        cout << m << '\n';
    }
}