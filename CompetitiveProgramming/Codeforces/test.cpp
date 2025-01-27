#include <bits/stdc++.h>

using namespace std;

bool cmp (pair<int, int> &l, pair<int, int> &r) {
    if (l.second < r.second) return 0;
    else if (l.second > r.second) return 1;
    return 1;

}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i<n; i++) {cin >> v[i];}
    vector<pair<int, int> > v;
    sort(v.begin(), v.end(), cmp);
}