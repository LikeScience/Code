#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++) 
using namespace std;

int main() {
 ll t, n, ai, bi;
    cin >> t;
    F(z,0,t) {
        cin >> n;
        vector<int> a(n), b(n);
        F(i,0,n) cin >> a[i];
        F(i,0,n) cin >> b[i];
        bool y=0;
        for (int i = 0; i<n; i++) {
            if (a[i] != b[i]) break;
            if (i==n-1) {
                y=1;
            }
        }  
        for (int i = 0; i<n;i++) {
            if (a[i] != b[n-i-1]) break;
            if (i==n-1) {
                y=1;
            }
        }
        cout << (y ? "Bob\n" : "Alice\n");
    } 

}