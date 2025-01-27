#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int n, h, t=0;
char c;
vector<bool> v, b;
vector<vector<bool> > o;

void r(int i, int d) {
    if (d>h || i>=n) return;
    if (d==h) {
        o.push_back({});
        F(j,0,n) o[t].push_back((b[j] ? !v[j] : v[j])); 
        t++;
        return;
    }
    r(i+1,d);
    b[i+1]=1;
    r(i+1,d+1);
    b[i+1]=0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin >> n >> h;
    F(i,0,n) {
        cin >> c;
        v.push_back(c == '1');
    }
    b.assign(n,0);
    r(-1, 0);
    sort (o.begin(), o.end());
    F(i,0,t) {F(j,0,n) cout << o[i][j]; cout << '\n';}
}