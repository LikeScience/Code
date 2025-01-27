#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, f, c;
    cin >> t;
    F(z,0,t) {
        cin >> n;
        int br=0, f0, mn, mx;
        cin >> f0 >> mn; mx = mn;
        F(i,1,n) {
            cin >> f >> c;
            if (f != f0) br=1;
            if (c%2) {
                if (!(mn%2) || c>mn) mn=c;
                else if((mx%2) && c<mx) mx=c;
            } else {
                if ((mx%2) || c>mx) mx=c;
                else if(!(mn%2) && c<mn) mn=c;
            }
        }
        if ((mn%2) && (mx%2)) {
            if (n < (mn-mx)/2 +1) br = 1;
        } else if (mn%2) {
            if (n < mn/2 + 1 + mx/2) br = 1;
        } else {
            if (n < (mx-mn)/2 +1) br = 1;
        }
        if(br) {cout << "NO" << '\n';}
        else cout << "SI" << '\n';
    }
}