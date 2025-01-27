#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i < e; i++)

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int> > v(n);
    
    F(i,0,m) {
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    vector<int> vi(n,0), d(n,-1);
    queue<int> q;
    q.push(0);
    d[0] = 0;
    vi[0] = 1; b = -2; bool x = 0;
    while((int)q.size() > 0) {
        a = q.front(); q.pop();

        F(i,0,v[a].size()) if (!vi[v[a][i]]){
            if (v[a][i] == n-1) {
                b = d[a]+1; x = 1;
                break;
            }
            d[v[a][i]] = d[a]+1;
            q.push(v[a][i]);
            vi[v[a][i]] = 1;
        }
        if (x) break;
    }
    cout << (n == 1 ? 1 : b+1) << '\n';
}