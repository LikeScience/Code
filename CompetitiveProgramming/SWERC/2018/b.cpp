#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    int n, d; 
    cin >> n;
    int f[n], s[n];
    F(i,0,n) cin >> f[i] >> s[i];
    int m = 0;
    int mx = 1;
    F(i,0,n) {
        if (i < n-1 && f[i+1]> f[i])  m = 1;
        if (m == 0) {
            int r=min(s[i]-f[i]+1,n-i+1), l = 1;
            while (r > l) {
                int d = (r+l+1)/2;
                if (f[i+d-1] > f[i] ||s[i+d-1] < f[i] + d -1) r = d-1;
                else l = d;
            }
            mx = max(mx, l);
        } else {
            int r=min(s[i]-f[i]+1,i+1), l = 1;
            while (r > l) {
                d = (r+l+1)/2;
                if (f[i-d+1] > f[i] ||s[i-d+1] < f[i] + d -1) r = d-1;
                else l = d;
            }
            mx = max(mx, l);
        }
    }
    cout << mx << '\n';
}