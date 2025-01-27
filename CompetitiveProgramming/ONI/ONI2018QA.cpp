#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, z, t=0, v=0;
    cin >> n >> z;
    vector<int> p(n);
    F(i,0,n) cin >> p[i];
    sort(p.begin(), p.end());
    F(i,0,n) {
        v+=p[i]; t++;
        if (v >= z) break;
    }
    cout << t << '\n';
}