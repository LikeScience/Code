#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
#define f first
#define s second

using namespace std;

int dr[8] = {0, 1, 1,  1,  0, -1, -1, -1}; 
int dc[8] = {1, 1, 0, -1, -1, -1,  0,  1};

int main() {
    int n, t, r, c;
    cin >> n >> t;
    vector<vector<pair<int, int> > > al(n+1);
    vector<pair<int, int> > b;
    vector<int> rs, cs;
    F(i,0,n) {
        cin >> r >> c;
        b.push_back({r,c});
        rs.push_back(r);
        cs.push_back(c);
    }
    F(i,0,n) F(j,0,8){
        if (rs[i]+ >)
    }
}
