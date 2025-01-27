#include <iostream>
#include <vector>

using namespace std;

vector<int> vis;
int r;

void fr(int x) {
    if (!vis[x]) {
        int num = 0;
        if ()
    }
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<int> c(n+1);
    vector<vector <int> > al(n+1);
    vis.assign(n+1,0)
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }

}