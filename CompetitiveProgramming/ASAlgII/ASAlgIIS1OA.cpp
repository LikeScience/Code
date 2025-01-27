#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)

using namespace std;

int main() {
    int t, n, z, p, idx = -1, b;
    cin >> t;
    F(y,0,t) {
        cin >> n >> p;
        b = 0;
        idx = -1;
        F(i,1,n) {
            cin >> z;
            if (idx == -1 && (p == 0 && z != 0)) {idx = i; b = 1;}
            p = z;
        }
        if (!b) {
            if (p) {
                cout << n+1;
                F(i,0,n) cout << " " << i+1;
                cout << '\n';
            }
            else {
                F(i,0,n) cout << i+1 << " ";
                cout << n+1 << '\n';
            }
        } else {
            cout << 1;
            F(i,1,n){
                if (i == idx) cout << " " << n+1;
                cout << " " << i+1;
            }
            cout << '\n';
        }
    }
}