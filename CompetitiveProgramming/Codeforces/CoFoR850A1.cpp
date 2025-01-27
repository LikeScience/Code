#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
#define f first
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int t, n, s = 6, a, b, x, y=0;
    cin >> t;
    vector<int> v;
    while(s <= 1e6) {
        v.push_back(s);
        y++;
        s+= 16*y + 6;
    }
    F(z,0,t) {
        cin >> n; a= 0; b = 0;
        vector<int>::iterator it = upper_bound(v.begin(), v.end(), n);
        x = it - v.begin();
        //cout << x-1 << " "<< v[x-1] << '\n';
        if (it != v.begin()) {
            a += 4*(x-1)*x + x;
            b += v[x-1] - a;
            n -= v[x-1];
        } 
        F (i,0,2) {
            if (n== 0) break;
            if (x*4 + i < n) {a += x*4 + i; n -= x*4 + i;}
            else {a += n; n=0;}
        }
         F (i,2,4) {
            if (n== 0) break;
            if (x*4 + i < n) {b += x*4 + i; n -= x*4 + i;}
            else {b += n; n=0;}
        }
        cout << a << " " <<  b << '\n';
    }
}