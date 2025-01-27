#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++)
#define pr pair<int, int>

int main() {
    int n, m;
    cin >> n>> m;
    vector<pr> v;
    F(i,0,n) {
        int x;
        cin >> x; 
        v.push_back(make_pair(x, i));
    } v;
    set<pr> q;
    F(i,0,n) q.insert({v[i]});
    while (!q.empty()) {
        auto it = q.end(); it--;
        pr a = *it;
        q.erase(it);
        if (a.second>0) if (v[a.second-1].first<a.first-m) {
            q.erase({v[a.second-1]});
            v[a.second-1].first=a.first-m;
            q.insert({v[a.second-1]});
        }
        if (a.second<n-1) if (v[a.second+1].first<a.first-m) {
            q.erase({v[a.second+1]});
            v[a.second+1].first=a.first-m;
            q.insert({v[a.second+1]});
        }
    }
    F(i,0,n) cout << v[i].first << " \n"[i==n-1];

}
    
