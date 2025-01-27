#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++) 
using namespace std;
#define fi first
#define se second

int main() {
    int is, s;
    cin >> is; 
    s = is/4 + 1;
    int l = 1, r = 40000; int dr;
    while (r-l>1) {
        int m = (l+r)/2;
        dr = m*m+1;
        int cnt = m;
        int y = m;
        F(x,2,m+1) {
            while (x*x + y*y > dr) y--;
            cnt += y;
        }
        if (cnt >= s) r = m;
        if (cnt <= s) l = m;
    }
    //cout << l <<  " "<< r << '\n';
    if (l == r) {
        cout << fixed << setprecision(10) << pow(double(dr),double(0.5)) << '\n';
        return 0;
    }
    multiset<pair<int, pair<int, int > > > q;
    dr = l*l+1;
    int cnt = l;
    int y = l;
    q.insert({r*r+1,{1,r}});q.insert({r*r+1,{r,1}});
    F(x,2,l+1) {
        while (x*x + y*y > dr) y--;
        cnt += y;
        q.insert({x*x+(y+1)*(y+1),{x,y+1}});
    }
    while (cnt < s) {
        pair<int, pair<int, int> > p = *q.begin(); q.erase(q.begin());
        dr = p.first;
        cnt++;
        if (p.se.fi*p.se.fi + (p.se.se+1)*(p.se.se+1) <= r*r+1) q.insert({p.se.fi*p.se.fi + (p.se.se+1)*(p.se.se+1), {p.se.fi, p.se.se+1}});
    }
    cout << fixed << setprecision(10) << pow(double(dr),double(0.5)) << '\n';
}