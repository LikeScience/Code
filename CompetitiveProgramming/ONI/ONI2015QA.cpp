#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i < e; i++)
#define pis pair<int, string>
#define f first
#define s second
using namespace std;

bool cmp(pis &l, pis &r) {
    if (l.f != r.f) return l.f > r.f;
    return (l.s) < (r.s);
}

int main() {
    int n, p, z;
    string s;
    vector<pis> v;
    cin >> n >> p;
    F(i,0,n) {
        cin >> s;
        v.push_back({0,s});
        F(j,0,p) {
            cin >> z;
            v[i].f += z;
        }
    }
    sort(v.begin(), v.end(), cmp);
    F(i,0,n) cout << v[i].s << " " << v[i].f << '\n';
}