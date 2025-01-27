#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int n, t=2; vector<bool> v;

vector<vector<int> > a;

int dfs(int x, int p) {
    int lt=0, mx=0;
    F(i,0,int(a[x].size()))if (a[x][i] != p) {
        int y = dfs(a[x][i], x);
        lt += y;
        mx = max(y, mx);
    }
    //cout << x << " " << lt << '\n';
    if (!v[x]) {
        t = max(lt, t);
        return lt;
    } else {
        t = max(t, lt-1);
        t = max(t, mx+1);
        return max(lt-1, 1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int ai, bi; cin >> n;
    string s;
    a.resize(n);
    F(i,0,n-1) {
        cin >> ai >> bi;
        ai--; bi--;
        a[ai].push_back(bi);
        a[bi].push_back(ai);
    } cin >> s;
    int cnt=0;
    F(i,0,n) {
        v.push_back(s[i] == '1');
        if (v[i]) cnt++;
    }
    dfs(0, -1);
    if (cnt == 1) cout << "1\n";
    else cout << t << '\n';
    bool b1=1, b2=1;
    
}