#include <bits/stdc++.h>
#define F(i,s,e) for (long long i = s; i<e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, k;
    cin >> t;
    F(z,0,t) {
        cin >> n >> k;
        vector<ll> s(n), m(n), p(n);
        F(i,0,n) cin >> s[i];
        m[0] = s[0];
        F(i,1,n) m[i] = max(s[i], s[i] + m[i-1]);
        p[0] = ((s[0] < 0) ? -s[0] : s[0]);
        F(i,1,n) p[i] = ((s[i] < 0) ? -s[i]+p[i-1] : s[i]+p[i-1]);
        deque<int> q;
        int x = 0; ll t=0, mx=0;
        if (k == 0) {
            F(i,0,n) mx = max(mx, m[i]);
            cout << mx << '\n';
            continue;
        }
        while ((int)q.size() < k && x < n){
            if (s[x] >= 0) {t += s[x];}
            else {
                q.push_back(x);
                t += -s[x];
            }
            x++;
        } 
        while (x < n && s[x] >=0) {
            t+=s[x];
            x++;    
        } mx = t;
        while (x < n) {
            if (s[x] >= 0) {t += s[x]; mx = max(mx, t);}
            else {
                int qb = *q.begin();
                
                q.push_back(x);
                t = p[x] - p[qb] + max((ll)0,m[qb]);
                mx = max(mx, t);
                q.pop_front();
                //cout << x << " " << p[x] << " " << p[qb] << " " << m[qb] << '\n';
            }
            x++;
        }
        cout << mx << '\n';
    }
}