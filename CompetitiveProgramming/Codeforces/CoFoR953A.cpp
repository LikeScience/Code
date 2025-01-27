#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n;
    cin >> t; 
    F(z,0,t) {
        cin >> n;
        ll m = 0, a;
        F(i,0,n-1) {
            cin >> a; m = max(m, a);
        } 
        cin >> a; m+=a;
        cout << m << '\n';
    }
}