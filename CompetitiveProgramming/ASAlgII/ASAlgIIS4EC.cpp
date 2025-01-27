#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
#define f first
#define s second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, t=0, r;
    bool b;
    long double d, e, x, y;
    while (cin >> n >> d) {
        if (n == 0 && d == 0) break;
        t++;
        b=1; r=1;
        vector<pair<long double, long double > > v;
        F(i,0,n) {
            cin >> x >> y;
            if (y > d) b=0;
            e = sqrt(d*d-y*y);
            v.push_back({x-e, x+e});
        }
        sort(v.begin(), v.end());
        e=v[0].s;
        F(i,1,n) {
            if (v[i].f > e) {
                r++;
                e = v[i].s;
            } else if (v[i].s<e) e = v[i].s;
        }
        cout << "Case " << t << ": " << (b ? r : -1) << '\n'; 
    }
}