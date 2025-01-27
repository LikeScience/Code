#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i < e; i++)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t, n, k, a, b, c, o;
    cin >> t;
    F(Z,0,t) {
    cin >> n >> k;
    vector<vector<int> > v(n);
    vector<int> l(n,-2), u(n);
    queue<int> q;
    o = n;
    F(i,0,n-1) {
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    if (n <= 2) {
        cout << "0\n";
        continue;
    }
    F(i,0,n) {
        u[i] = (int)v[i].size();
        if (u[i] == 1) {
            q.push(i);
        }
    }
    
    
    while(!q.empty()) {
        a = q.front(); q.pop();
        
        if (v[a].size()==1) {
            l[a] = 1;
            o--;
            u[v[a][0]]--;
            if (l[v[a][0]] == -2 && u[v[a][0]] < 2) {
                q.push(v[a][0]);
                l[v[a][0]] = -1;
                
            }
            continue;
        }

        c= 0; b = 0;
        F(i,0,v[a].size()) {
            if (l[v[a][i]] > c) {
                if (l[v[a][i]] > b) {
                    c = b; b = l[v[a][i]];
                } else c = l[v[a][i]];
            }
        }

        l[a] = (u[a] ? b+1 : c+1);
        if (l[a] <= k) o--;
        F(i,0,v[a].size()) {
            u[v[a][i]]--;
            if (l[v[a][i]] == -2 && u[v[a][i]] < 2){
                q.push(v[a][i]);
                l[v[a][i]] = -1;
            }
        }
    }
    cout << o << '\n';
    }
}