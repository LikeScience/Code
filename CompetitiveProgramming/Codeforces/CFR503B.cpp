#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, x;
    cin >> n;
    int v[n+1];
    F(i,0,n) {
        cin >> v[i+1];
    }
    F(i,0,n) {
        bool b[n+1] = {};
        x = i+1;
        while(1) {
            b[x] = 1;
            if (b[v[x]]) {
                cout << v[x] << " ";
                break;
            } else x = v[x];
        }
    } cout << '\n';
}