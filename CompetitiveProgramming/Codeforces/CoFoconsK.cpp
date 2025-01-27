#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main( ) {
    ios::sync_with_stdio(0); cin.tie(0);
    int q, a, y, k; cin >> q;
    set<pair<int, int> > s;
    F(z,0,q) {
        cin >> a;
        if (a == 1) {
            cin >> k; s.insert({k,z+1});

        } else {
            cin >> y >> k;
            auto it = s.lower_bound(make_pair(y,0));
            vector<int> o;
            while (it != s.end()) {
                o.push_back(it->second);
                it++;
            }
            sort(o.begin(), o.end());
            cout << min((int)o.size(),k) << '\n';
            int i = o.size()-1;
            for (; i > max(0,(int)o.size()-k); i--) cout << o[i] << " ";
            if (i>=0) cout << o[ max(0,(int)o.size()-k)];
            cout << '\n';
        }
    }
    
}