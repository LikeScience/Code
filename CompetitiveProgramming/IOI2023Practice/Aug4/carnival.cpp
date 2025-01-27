#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, z; cin >> n;
    vector<vector<int> > a(n, vector<int>(n, 0));
    bool b1=1, b2=1;
    F(i,1,n) F(j,0,i) {
        cin >> z;    
        if (j <= (i-1)/2) {
            a[i][z] = 1; a[z][i] = 1;
        }
        if (z != j) b2 = 0;
        if (z != i-j-1) b1 = 0;
    }
    if (b1) {
        F(i,0,n) cout << i << " \n"[i==n-1]; 
        //cout << 1 << '\n';
    } else if (b2) {
        F(i,0,n) {
            if (n%2) {
            if (i%2) {
                cout << n/2-i/2-1;
            } else {
                cout << n-i/2-1;
            }
            } else {
                if (i%2) {
                cout << n-i/2-1;
                } else {
                cout << n/2-i/2-1;
                }
            }
            cout << " \n"[i==n-1]; 
        }
        //cout << "2\n";
    } else {
        vector<int> p = {0};
        F(i,1,n) {
            bool b = 0;
            auto it = p.begin();
            if (a[i][p[0]]) {
                b = 1;
                p.insert(it, i);
            } 
            for(it++; it!= p.end() && !b; it++) {
                auto it2 = it; it2--;
                if (a[i][*it2] && a[i][*it]) {
                    p.insert(it, i);
                    b = 1;
                }
            }
            if (b==0) {
                p.insert(p.end(), i);
            }
        }
        F(i,0,n) cout << p[i] << " \n"[i==n-1]; 
    }
}