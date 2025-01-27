#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, a; 
    cin >> t;
    F(z,0,t) {
        string s = "";
        cin >> n; vector<int> cnt(26,0);
        F(i,0,n) {
            cin >> a;
            F(j,0,26) if (cnt[j] == a) {
                cnt[j]++;
                s += 'a' + j;
                break;
            } 
        }
        cout << s << '\n';
    }
}