#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
using namespace std;

vector<int> dec(int x) {
    vector<int> o;
    while (x) {
        o.push_back(x%10);
        x/=10;
    }
    return o;
}

int main () {
    int a, n;
    cin >> a >> n;
    vector<int> v = dec(a); int vs = (int)v.size();
    int t = 0;
    F(i,1,n+1) {
        vector<int> x = dec(i); int xs = (int)x.size();
        if (vs > xs) {t++;continue;}
        bool k = 1;
        F(j,0,xs-vs+1) {
            bool b = 1;
            F(y,j,j+vs) if (x[y] != v[y-j]) b = 0;
            if (b) k = 0;
        }
        if (k) t++;
    }
    cout << t << '\n';
}