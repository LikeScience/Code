#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n; string s;
    cin >> t;
    F(z,0,t) {
        cin >> n >> s; int x=-1, y;
        F(i,0,n) if (s[i] == 'B') {
            if (x == -1) {x = y = i;}
            else y = i;
        }
        cout << ((x == -1) ? 0 : y-x+1) << '\n';
    }
}