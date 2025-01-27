#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    random_device rd;
    fstream f("o38.txt", fstream::out);
    int m, n, q, c, t, ai, bi; cin >> m >> n >> t >> q >> c;
    f << q << '\n';
    vector<pair<int, int> > v;
    vector<pair<int, int> >::iterator it;
    map<pair<int, int> , pbds > s;
    pbds::iterator at;
    int no = 0, x, y, ti;
    if (c == 4) {
        while(v.size()<n) {
            ai = 1 + (rd() % m); bi =  1 + (rd() % m);
            it = lower_bound(v.begin(), v.end(), make_pair(ai,bi));
            if ( it == v.end() || *it != make_pair(ai,bi)) v.push_back({ai,bi}); 
            //cout << v.size() << '\n';
        }
        F(i,0,q) {
        x = rd() % 5;
        pair<int, int> p = v[rd() % n]; y = s[p].size();
        if (x == 0 && y > 0) {
            at = s[p].find_by_order(rd()%y);
            f << 2 << " " << p.first << " " << p.second << " "<<*at << '\n';
            s[p].erase(at);
        } else if (x <= 2 && s[p].size() < t) {
            while(1) {
                x = 1 + (rd() % t);
                at = lower_bound(s[p].begin(), s[p].end(), x);
                if (at == s[p].end() || *at != x) {
                     f << 1 << " " << p.first << " " << p.second << " "<< x << '\n';
                    s[p].insert(x);
                    break;
                }
            }
        } else {
            f << 3 << " " << p.first << " " << p.second << " "<< (1 + (rd() % t)) << '\n';
        }
        }
    } else if (c==2) {
        while(v.size()<n) {
            ai = 1 + (rd() % m); bi =  1 + (rd() % m);
            it = lower_bound(v.begin(), v.end(), make_pair(ai,bi));
            if ( it == v.end() || *it != make_pair(ai,bi)) v.push_back({ai,bi}); 
            //cout << v.size() << '\n';
        }
        F(i,0,q) {
        x = rd() % 2;
        pair<int, int> p = v[rd() % n]; y = s[p].size();
        if (x == 0 && y > 0) {
            at = s[p].begin();
            f << 2 << " " << p.first << " " << p.second << " "<<*at << '\n';
            s[p].erase(at);
        } else if (x ==0) {
                x = 1 + (rd() % t);
                f << 1 << " " << p.first << " " << p.second << " "<< x << '\n';
                s[p].insert(x);
        } else {
            f << 3 << " " << p.first << " " << p.second << " "<< (1 + (rd() % t)) << '\n';
        }
        }
    }
}