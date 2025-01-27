#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i < e; i++)

using namespace std;

int main() {
    int n, m, a, b, t=0;
    cin >> n >> m;
    vector<vector<int> > v(n);
    
    F(i,0,m) {
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    vector<int> vi(n,0), p(n,0);
    queue<int> q;
    F(x,0,n) if (!vi[x]) {
    q.push(x);
    bool c=0, d=1;
    vi[x] = 1; p[x] = -1;
    while((int)q.size() > 0) {
        a = q.front(); q.pop();
        if ((int)v[a].size() != 2) d = 0;
        F(i,0,v[a].size()) {
            if (!vi[v[a][i]]){
            p[v[a][i]] = a;
            q.push(v[a][i]);
            vi[v[a][i]] = 1;
            } else if (v[a][i]!= p[a]) {
                c=1;
            }
        
        }
        
    }
    if((c && d) && (int)v[x].size()) t++;
    }
    cout << t << '\n';
}