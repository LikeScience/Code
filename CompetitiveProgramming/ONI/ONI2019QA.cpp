#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, k, t, c=0, o=0;
    cin >> n >> k >> t;
    int v[n];
    F(i,0,k) {
        cin >> v[i];
        if (v[i] >= t) c++;
    }
    if (c>(k-1)/2) o++;
    F(i,k,n) {
        cin >> v[i];
        if (v[i] >= t) c++;
        if (v[i-k] >= t) c--;
        if (c>(k-1)/2) o++;
    }
    cout << o << '\n';
}