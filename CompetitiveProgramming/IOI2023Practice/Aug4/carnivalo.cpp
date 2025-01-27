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
        vector<int> p(n);
        F(i,0,n) p[i] = i;
        do {
            bool b = 1;
            F(i,0,n-1) {
                if (!a[p[i]][p[i+1]]) {
                    b = 0;
                    break;
                }
            }if (b == 0) continue;
            F(i,0,n) cout << p[i] << " \n"[i==n-1]; 
            break;
        } while (next_permutation(p.begin(), p.end()));
    }
}