#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i < e; i++)
#define f first
#define s second
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int c, n, d, p;
    ll t;
    map<int, ll>::iterator it, it0;
    cin >> c;
    F(z,0,c) {
        map<int, ll> m;
        t=0;
        cin >> n >> d;
        F(i,0,n) {
            cin >> p;
            it = m.find(p); 
            //cout << *it << p<< '\n';
            if (it != m.end()) {
                t+=(it->s)++;
            } else {
                m[p]=1;
            }
            //cout << i << '\n';
            it = m.upper_bound(p+d);
            if (it != m.end()) {
                m.erase(it, m.end());
            }
            it = m.lower_bound(p-d);
            if (it != m.begin()) {
                m.erase(m.begin(), it);
            }
        }
        cout << t << '\n';
    }
}