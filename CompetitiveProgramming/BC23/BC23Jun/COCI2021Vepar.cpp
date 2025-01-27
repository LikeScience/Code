#include <bits/stdc++.h>
#define F(i,s,e) for (int i =s; i<e; i++)
#define ll long long
using namespace std;

vector<int> p; int pc=0;

vector<int> ep(int x) {
    if (x <= 1) return vector<int>(pc, 0);
    vector<int> v(pc, 0);
    F(i,0,pc) {
        if (p[i] > x) break;
        ll r = p[i];
        while (r <= x) {
            v[i] += x/r;
            r*= (ll)p[i];
        }
    }
    return v;
} 

int main() {
    int t, a, b, c, d;
    cin >> t;
    vector<bool> ip(10000001,1);
    F(i,2,1e7+1) if (ip[i]) {
        p.push_back(i); pc++;
        for (ll j = (ll)i*((ll)i); j <= 10000000; j += i) ip[j] = 0;
    }
    F(z,0,t) {
        cin >> a >> b >> c >> d;
        vector<int> va = ep(a-1), vb = ep(b), vc = ep(c-1), vd = ep(d);
        bool l=1;
        F(i,0,pc) {
            if (vd[i] - vc[i] < vb[i] - va[i]) {l=0; break;}
        }
        cout << (l ? "DA" : "NE") << '\n';
    }
}