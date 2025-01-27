#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, k; cin >> t;
    F(z,0,t) {
        cin >> n >> k;
        vector<vector<int> > al(n);
        vector<int> vis(n,0), vn(n,0), l(n,0);
        queue<int> q;
        F(i,0,n-1) {
            int a, b; cin >> a >> b;
            al[a-1].push_back(b-1);
            al[b-1].push_back(a-1);
        }
        F(i,0,n) if (al[i].size() == 1) q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (!vis[x]) {
                vis[x] = 1;
                if ((int)al[x].size() == 1) {l[x] = 1;}
                if (vn[x] != (int)al[x].size()) { for (int i : al[x]) if (vis[i]) {
                    l[x] = max(l[x], l[i]+1);
                }} else {
                    int m1 = 0, m2 = 0;
                    for (int i : al[x]) {
                        if (l[i] >= m1) {
                            m2 = m1; m1 = l[i]; 
                        } else if (l[i] > m2) {
                            m2 = l[i];
                        }
                    } l[x] = m2+1;
                }
                for (int i : al[x]) if (!vis[i]) {
                    vn[i]++;
                    if (vn[i] >= (int)al[i].size()-1) q.push(i);
                }
            }
        }
        int t = 0;
        F(i,0,n) t += (l[i] > k);
        cout << t << '\n';
    }
} 