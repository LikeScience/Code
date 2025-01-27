#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (ll i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<double> p(n);
    F(i,0,n) cin >> p[i];
    F(i,0,n+1) {
        double l = 0.5, r = double(n) + 0.5, a =  double(i)+0.5;
        bool b = 0;
        int cnt = 0;
        F(j,0,n) {
            
            if (p[j] < l || p[j] > r) continue;
            if (p[j] > a) {
                b = 1;
                r = p[j]-0.5;
            } else {
                l = p[j]+0.5;
                if (b == 1) cnt++;
                b = 0;
            }
        }
        cout << cnt << '\n';

    }
}