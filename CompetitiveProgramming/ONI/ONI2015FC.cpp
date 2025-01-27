#include <bits/stdc++.h>
#define F(i,x,e) for (int i=x; i<e; i++)
#define f first
#define s second
using namespace std;

vector<vector<int> > al;
vector<int> pa, h, ss;

void dfs(int x) {
    ss[x] = 1;
    if ((int)al[x].size() == 0) {
        h[x] = 1;
        return;
    }
    F(i,0,(int)al[x].size()) dfs(al[x][i]);
    int m = 0;
    F(i,0,(int)al[x].size()) {
        ss[x] += ss[al[x][i]];
        m = max(m, h[al[x][i]]);
    }
    h[x] = m+1;
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a, b, p, ci, si;
    cin >> n;
    al.resize(n); pa.assign(n,-1); h.resize(n); ss.resize(n);   
    F(i,0,n-1) {
        cin >> a >> b;
        al[a].push_back(b);
        pa[b]=a;
    }
    dfs(0);
    vector<vector<int> > v(n, vector<int>(n+1, 0)); //(Root; number of cs);
    vector<pair<int, int> > q;
    F(i,0,n) {
        q.push_back({h[i], i});
    } 
    sort(q.begin(), q.end());
    F(i,0,n) {
        int x = q[i].s;
        if (ss[x] == 1) {continue;} //In this case v[x][j] = 0
        vector<vector<int> > k((int)al[x].size(), vector<int>(ss[x], 0)); //(last analysed subtree; number of cs); 
        F(j,0,ss[al[x][0]]+1) {
            k[0][j] = v[al[x][0]][j];
        } int t = ss[al[x][0]];
        F(y,1,(int)al[x].size()) {
            
            F(j,0,t+ss[al[x][y]]) F(z,0,min(t+1,j+1)) {
                k[y][j] = max(k[y][j], v[al[x][y]][j-z] + k[y-1][z]);
            }
            t += ss[al[x][y]];
        }
        // v [x][0] = 0;
        F(j,1,ss[x]) {
            v[x][j] = max(k[(int)al[x].size()-1][j] + j, k[(int)al[x].size()-1][j-1] + ss[x]-j);
        }
        //v[x][ss[x]] = 0;
        //if (x==0) F(j,0,(int)al[x].size()) {F(y,0,ss[x]) cout << k[j][y] << " "; cout << '\n';}
    }
    //F(i,0,n) {F(j,0,n+1) cout << v[i][j] << " "; cout << '\n';}
    cin >> p;
    F(i,0,p) {
        cin >> ci >> si;
        cout << v[0][ci] << '\n';
    }
}