#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, t, d;
    vector<pair<int, int> > v;
    cin >> n;
    F(i,0,n) {
        cin >> t >> d;
        v.push_back({t+d,t});
    }
    sort(v.begin(), v.end());
    t=1; d = v[0].first;
    F(i,1,n) {
        if (v[i].second >= d) {
            d = v[i].first;
            t++;
        }
    }
    cout << t << '\n';
    return 0;
}