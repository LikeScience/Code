#include "tickets.h"
#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int md(int a, int b) {
    return ((a < b) ? (b - a) : (a - b));
}

ll find_maximum(int k, vector<vector<int> > x) {
    int n = (int)x.size(), m = (int)x[0].size();
    if (m == 1) {
        allocate_tickets(vector<vector<int> >(n,vector<int>(1 ,0)));
        vector<int> v;
        for (int i = 0; i < n; i++) {v.push_back(x[i][0]);}
        ll s = 0;
        sort(v.begin(), v.end());
        int b = (n+1)/2 - 1;
        for (int i = 0; i < n; i++) {s += md(v[i], v[b]);}
        return s;
    } else if (k == 1) {
        vector<pair<int, pair<int, int> > > vp; vector<int> ac(n,1); int nu = n; //active colour; non-used colour count
        vector<vector<int> > all(n, vector<int>(m,-1)); // allocate tickets
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vp.push_back(make_pair(x[i][j], make_pair(i,j)));
            }
        }
        sort(vp.begin(), vp.end());
        vector<int> v;
        vector<pair<int, pair<int, int> > >::iterator bt = vp.begin(), et = vp.end(), ab, ae; et--;
        while(nu > 1) {
            if(!ac[bt->second.first]) {bt++;}
            else if(!ac[et->second.first]) {et--;}
            int btn = bt->second.first, btm = bt->second.second, etn = et->second.first, etm = et->second.second;
            if (btn != etn) {
                nu-=2;
                all[btn][etn]=0;all[etn][etm]=0;
                ac[btn] = 0; ac[etn] = 0;
                v.push_back(bt->first); v.push_back(et->first);
                bt++; et--;
            } else {
                ab = bt; ae = et;
                while(ab->second.first == etn || !ac[ab->second.first]) {ab++;}
                while(ae->second.first == btn || !ac[ae->second.first]) {ae++;}
                if (et->first - ab->first > ae->first - bt->first) {bt = ab;}
                else {et = ae;}
                nu-=2;
                btn = bt->second.first; btm = bt->second.second; etn = et->second.first; etm = et->second.second;
                all[btn][btm]=0;all[etn][etm]=0;
                ac[btn] = 0; ac[etn] = 0;
                v.push_back(bt->first); v.push_back(et->first);
                bt++; et--;
            }
            

        }
        if (nu == 1) {int k=0; for (int i = 0; i < n; i++) {if (ac[i]) {k = i; break;}} v.push_back(x[k][0]); all[k][0] = 0;}
        ll s = 0;
        sort(v.begin(), v.end());
        int b = (n+1)/2 - 1;
        for (int i = 0; i < n; i++) {s += md(v[i], v[b]);}
        allocate_tickets(all);
        return s;
    }
    return 0;
}