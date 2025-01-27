#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)

using namespace std;

int main() {
    int n, m, a, b, idx; cin >> n >> m;
    vector<vector<bool> > v(n, vector<bool>(n, 0));
    vector<int> cnt(n, 0);
    F(i,0,m) {
        cin >> a >> b;
        if (!v[a][b]) {
            cnt[a]++; cnt[b]++;
            v[a][b] = 1; v[b][a] = 1;
        } 
    }
    cin >> idx; cout << cnt[idx] << '\n';
}