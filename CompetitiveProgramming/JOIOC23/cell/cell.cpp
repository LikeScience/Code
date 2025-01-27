#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define pii pair<int, int>
#define x first
#define y second
#define mp make_pair
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace __gnu_pbds;
typedef  tree<pair<int, int>, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int cx[4] = {1, 0, -1, 0};
int cy[4] = {0, 1, 0, -1};

int main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q, maxt=0;
    cin >> n >> q;
    vector<pii> c(n); vector<int> p(q),ans; int iq[1001] = {};
    vector<pii> b, g;
    vector<vector<int> > m(4001, vector<int>(4001, 0));
    F(i,0,n) {
        cin >> c[i].x >> c[i].y;
        c[i].x += 2000;
        c[i].y += 2000;
        b.push_back(c[i]);
        m[c[i].x][c[i].y] = 2;
    }
    F(i,0,q) {
        cin >> p[i];
        maxt = max(maxt, p[i]);
        iq[p[i]] = 1;
    }
    
    
        if (iq[0]) ans.push_back((int)b.size());
    F(i,1,maxt+1) {
        vector<pii> tob(0), tog(0);
        for (auto it : b) {
            tog.push_back(it);
            m[it.x][it.y] = 1;
            //cout << it.x << it.y << '\n';
            F(j,0,4) {
                if (m[it.x+cx[j]][it.y+cy[j]] == 0) {
                    m[it.x+cx[j]][it.y+cy[j]] = 2;
                    tob.push_back(mp(it.x+cx[j],it.y+cy[j]));
                    //cout << it.x+cx[j] << " " << it.y+cy[j] << '\n';
                } 
            }
        }
        for (auto it : g) {
            m[it.x][it.y] = 0;
        }
        b.clear();
        g.clear();
        F(j,0,(int)tob.size()) {
            b.push_back(tob[j]);
            //cout << tob[j].x << ' ' << tob[j].y << '|';
        } //cout << '\n';
        F(j,0,(int)tog.size()) {
            g.push_back(tog[j]);
        }
        if (iq[i]) ans.push_back((int)b.size());
    }
    F(i,0,q) cout << ans[i] << '\n';

}