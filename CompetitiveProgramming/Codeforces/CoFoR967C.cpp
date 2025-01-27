#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    int t, n, x;
    cin >> t;
    F(z,0,t) {
        cin >> n;
        set<int> notin;
        F(i,2,n+1) notin.insert(i);
        vector<int> isin(n+1,0);
        vector<pair<int, int> > v;
        isin[1] = 1;
        while (!notin.empty()) {
            int b = *(notin.begin());
            int a = 1, x = -1;
            while (x!=-2) {
                cout << "? " << a << " " << b << '\n';
                cout.flush();
                cin >> x;
                if (x == a) break;
                if (isin[x]) a=x;
                else b=x;
            }
            v.push_back(make_pair(a, b));
            notin.erase(b);
            isin[b]=1;
        }
        cout << "!";
        F(i,0,n-1) cout << " " << v[i].first << " " << v[i].second;
        cout << '\n';
        cout.flush();
    }
}