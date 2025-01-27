#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int n, w, pi, vi, m = 0;
vector<int> p, v;

void r(int t, int h, int a) {
    if (h>w) return;
    if (t > m) m = t;
    if (a==n-1) return;
    r(t,h,a+1);
    r(t+v[a+1],h+p[a+1],a+1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin >> n >> w;
    F(i,0,n) {
        cin >> pi >> vi;
        p.push_back(pi);
        v.push_back(vi);
    }
    r(0, 0, -1);
    cout << m << "\n";
}