#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

int v[5] = {1, 0, 0, 0, 1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    F(z,0,t) {
        int n; cin >> n; string s, o; cin >> s;
        int i = 0;
        while (i<n) {
            if (i == n-2) {
                o += s[n-2]; o += s[n-1];
                break;
            }
            if (i == n-3) {
                o += s[n-3]; o += s[n-2]; o += s[n-1];
                break;
            }
            if (v[s[i+3]-'a']) {
                o += s[i]; o += s[i+1]; o += '.'; i+=2;
            } else {
                 o += s[i]; o += s[i+1]; o += s[i+2]; o += '.'; i+=3;
            }
        }
        cout << o << '\n';
    }
}