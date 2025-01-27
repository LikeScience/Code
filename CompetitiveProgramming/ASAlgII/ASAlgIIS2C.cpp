#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i < e; i++)

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, a, b;
    //bool x;
    cin >> n;
    vector<int> v[n];
    bool p[n], vi[n] = {};
    
    F(i,0,n-1) {
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }

    //queue<pair<int, bool > > q;
    //q.push({0, 0});
    queue<int> q;
    q.push(0); p[0] = 0;
    vi[0] = 1; b=0;
    while(!q.empty()) {
        a=q.front(); q.pop();
        //a = q.front().first; x = q.front().second; q.pop();
        //p[a]=x; if(x) b++;
        F(i,0,v[a].size()) if (!vi[v[a][i]]){
            //q.push({v[a][i], !x});
            q.push(v[a][i]);
            p[v[a][i]]=!p[a]; if(!p[a]) b++;
            vi[v[a][i]] = 1;
        }
    }

    long long t = 0;
    F(i,0,n) {
        if (!p[i]) t += (b-(int)v[i].size());
    }
    cout << t << '\n';
}