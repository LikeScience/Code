#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

vector<vector<int> > ft;
int n, m;

void ftup(int x, int y, int u) {
    while (x <=n) {
        int dy = y;
        {
            ft[x][dy] += u;
            dy += (dy &-dy);
        }
        x += (x &-x);
    }
}

int ftev(int x, int y) {
    int ans = 0;
    while (idx <=n) {
        ans += ft[idx];
        idx-= (idx &-idx);
    }
}

int main() {
    cin >> n >> m; int q; cin >> q; ft.assign(n+1,vector<int> (m+1, 0));
    vector<int> v(n);
    F(i,0,n) cin >> v[i];
    F(i,0,n) {
        ftup(i+1,v[i]);
    } 

}