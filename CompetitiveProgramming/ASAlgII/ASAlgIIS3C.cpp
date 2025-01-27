#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, q, a;
    vector<int> p(51,0);
    cin >> n >> q;
    F(i,0,n) {
        cin >> a;
        if (!p[a]) p[a] = i+1;
    }
    F(z,0,q) {
        cin >> a;
        cout << p[a] << " ";
        F(i,1,51) {
            if (p[a] > p[i]) p[i]++;
        }
        p[a] = 1;
    }
    cout << '\n';
}