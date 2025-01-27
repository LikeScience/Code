#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

#define ll long long
#define F(i,s,e) for(long long i = s; i < e; i++)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, pi, xi, mx = 0, daft, dbef, dx, g, xm;
    cin >> n >> m;
    vector<ll> p, s, x;
    vector<ll>::iterator it;
    F(i,0,n) {
        cin >> pi;
        p.push_back(pi);
        if (i == 0) {s.push_back(pi);} else {s.push_back(s[i-1] + pi);}
    }
    F(i,0,m) {
        cin >> xi;
        x.push_back(xi);
    } //cout << 0 << endl;
    sort(x.begin(), x.end());
    F(i,0,n) {
        it = lower_bound(x.begin(), x.end(), 100*i);
        //cout << it - x.begin() << endl;
        //cout << i << " " << *it << endl;
        if (*it == 100 * i) continue;
        if (it == x.begin()) {
            if (*it >= (100*n)) {
                g = s[n-1];
                if (g > mx) mx = g;
            }
            else {
            g = s[i];
            if (g > mx) mx = g;
            //cout << g << endl;
            }
        }
        else if (it == x.end()) {
            it--;
            g = s[n-1] - s[*it / 100];
            if (g > mx) mx = g;
        } else {
            daft = *it - 100 *i;
            it--;
            dbef = 100*i - *it;
            if(dbef <= daft) {
                g = s[i] - s[*it / 100];
                if (g > mx) mx = g;
            } else {
                dx = i*100 - daft;
                xm = (dx + *it) / 2 + 1;
                g = s[i] - s[(xm-1) / 100];
                if (g > mx) mx = g;
                //cout << dbef << " " << dx << endl;
            }
        }
    }
    cout << mx << '\n';
}