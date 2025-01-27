#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i < e; i++)
using namespace std;

int main() {
    int n; cin >> n; vector<pair<double, double> > v; 
    F(i,0,n) {
        double x, y; cin >> x >> y;
        v.push_back({x,y});
    }sort(v.begin(), v.end());
    cout << n << '\n';
    F(i,0,n) cout << v[i].first << " " << (long long)v[i].second << '\n';
}