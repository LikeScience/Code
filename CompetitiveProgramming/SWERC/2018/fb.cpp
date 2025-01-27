#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e ; i++)
using namespace std;
#define ll long long
#define M double(1e9+1)
#define se second
#define fi first

int main() {
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    vector<long long> g(n);
    F(i,0,n) cin >> x[i] >> y[i] >> g[i];
    ll md=1e18;
    F(i,0,n) {
        int w = (i+1)%n, pw = w;
        ll U=0, D=0;
        vector<pair<double, int> > d;
        vector<bool> s(n);
        double m = ((x[w] == x[i]) ? M : (y[w] - y[i])/(x[w]-x[i]));
        double b = ((x[w] == x[i]) ? x[i] : y[w] - m*x[w]);
        s[w] = (x[w] > x[i]);
        if (x[w] == x[i]) s[w] = y[w] > y[i];
        if (x[i] != x[w]) { F(j,0,n) if (j != i && j != w) {
            d.push_back({((x[j] == x[i]) ? M : (y[j] - y[i])/(x[j]-x[i])), j});
            //cout << d[d.size()-1].fi << " " << d[d.size()-1].se <<  " \n"[j==n-1];
            if (y[j] > x[j]*m+b) {
                U+= g[j];
                s[j] = 1;
            } else {
                D += g[j];
                s[j] = 0;
            }
        } } else {
            F(j,0,n) if (j != i && j != w) {
            d.push_back({((x[j] == x[i]) ? M : (y[j] - y[i])/(x[j]-x[i])), j});
            if (x[j] < b) {
                U+= g[j];
                s[j] = 1;
            } else {
                D += g[j];
                s[j] = 0;
            }
            }
        }
        //if (i == 0) F(j,0,n-2) cout << d[j].fi << " " << d[j].se <<  " \n"[j==n-3];
        
        sort(d.begin(), d.end());
        if (abs(U-D) < md) md = abs(U-D);
        //cout << abs(U-D) << '\n';
        auto it = upper_bound(d.begin(), d.end(), make_pair(m,-1));
        if (it == d.end()) it = d.begin();
        F(j,0,n-2) {
            pw = w; w = it->se;
            if (s[w] == 1) U-= g[w];
            else if (s[w] == 0) D-= g[w];
            if (s[pw] == 0) U += g[pw];
            else if (s[pw] == 1) D += g[pw];
            s[pw] = 1 - s[pw];
            if (abs(U-D) < md) md = abs(U-D);
            it++; if (it == d.end()) it = d.begin();
            //cout << i << " " << w << " " << abs(U-D) << '\n';
        }
    }
    cout << md << '\n';
}