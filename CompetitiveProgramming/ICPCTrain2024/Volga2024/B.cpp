#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++) 

using namespace std;

int main() {
    int t, n, xi; vector<int> a; cin >> t;
    F(z,0,t) {
        cin >> n;
        F(i,0,n) {cin >> xi; a.push_back(xi);}
        int mn=1e9+7, mx = 0; bool f = 0;
        F(i,0,n) {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
        while (mn < mx) {
            int m = (mn+mx)/2;
            int j = -1; vector<int> v = a;
            int c = 0; F(i,0,n) c += (v[i]>m); 
            while (j=((j+1)%n)) if (v[j]>m) {
                int x = v[j]-m +(v[j]-m)%2;
                if (v[(j+1)%n]>m) c--;
                v[j]-=x; v[(j+1)%n] += x/2;
                if (!c) break;
            }
            bool bx=1;
            F(i,0,n) if (v[i]!=m) {bx=0; break;}  
            if (bx) {
                f = 1;
                mn = m;
            } else mx = m-1;
        }
        cout << (f ? mx : -1) << '\n';
    }

}