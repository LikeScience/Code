#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

vector<int> ft;
int n;

void ftup(int idx, int u) {
    while (idx <=n) {
        ft[idx] += u;
        idx+= (idx &-idx);
    }
}

int ftev(int idx) {
    int ans = 0;
    while (idx <=n) {
        ans += ft[idx];
        idx-= (idx &-idx);
    }
    return ans;
}

int main() {
    cin >> n; int q; cin >> q; ft.assign(n+1,0);
    vector<int> v(n);
    F(i,0,n) cin >> v[i];
    F(i,0,n) {
        ftup(i+1,v[i]);
    } 

}