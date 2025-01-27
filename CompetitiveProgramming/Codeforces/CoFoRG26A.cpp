#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n;
    cin >> t;
    F(z,0,t) {
        cin >> n;
        vector<int> v(n);
        F(i,0,n) {
            cin >> v[i];
        }
        if (v[0] == v.back()) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            if (v[1]==v.back()) {
                F(i,0,n-1) cout << "B";
                cout << "R\n";
            } else {
                cout << "B";
                F(i,0,n-1) cout << "R";
                cout << '\n';
            }
        }
    }

}