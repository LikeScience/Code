#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i < e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k;
    ll t=0, x=0;
    char c;
    cin >> n >> k;
    vector<bool> v(n);
    F(i,0, n) {
        cin >> c;
        v[i] = (c == 'M');
    }
    F(i,0,k) {
        if (v[i]) {x++;}
        else t +=x;
    }
    F(i,k,n) {
        if (v[i]) {x++;}
        else t +=x;
        if (v[i-k]) x--;
    }
    cout << t << '\n';
}