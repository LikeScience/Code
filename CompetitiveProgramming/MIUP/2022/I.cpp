#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int l, w, o;
    cin >> l >> w >> o;
    vector<vector<pair<int, int> > > v(w);
    F(i,0,o) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        F(i,y1,y2+1) {
            v[i].push_back({x1, 0});
            v[i].push_back({x2, 1});
        }
    }
    F(i,0,w) sort(v[i].begin(), v[i].end());
    int T=0;
    F(i,0,w) {
        int obs=0; int lastobst=-1;

        for (int j = 0; j < v[i].size(); j++) {
            if (obs == 0) {
                T += v[i][j].first -lastobst -1;
            }
            if (v[i][j].second == 0) obs++;
            else {
                obs--;
                lastobst = v[i][j].first;
            }
        }
        T += l - lastobst -1;
    }
    cout << T << '\n';
}