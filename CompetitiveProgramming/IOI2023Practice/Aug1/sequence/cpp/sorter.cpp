#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    F(i,0,n) cin >> v[i];
    sort(v.begin(), v.end());
    F(i,0,n) cout << v[i] << " ";
}