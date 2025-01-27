#include <bits/stdc++.h>
#define F(i,s,e) for (int i=s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, t, a, f;
    cin >> t;
    F(z,0,t) {
        cin >> n >> f;
        vector<int> v;
        F(i,0,n-1) {
            cin >> a;
            v.push_back(a);
        }
        v.push_back(f);
        bool b = 1;
        F(i,0,n-1) if (v[i] > v[i+1]) b = 0;
        if (!b) {
            F(i,0,n-1) cout << v[i] << " ";
            cout << v[n-1] << '\n';
        } else {
            F(i,1,n) cout << v[i] << " ";
            cout << v[0] << '\n';
        }
    }
}