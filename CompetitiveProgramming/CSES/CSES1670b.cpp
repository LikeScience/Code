#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;
 
vector<int> p10 = {1};
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //clock_t st, ch1, ch2;
    //st =clock();
    F(i,0,9) p10.push_back(10*p10[i]);
    vector<vector<int> > a(3, vector<int>(3));
    vector<bool> vis(/*429794606*/987654322); 
    F(i,0,3) F(j,0,3) cin >> a[i][j];
    int x = 0;
    F(i,0,3) F(j,0,3) {
        x += a[i][j]*p10[3*i+j];
    }
    //ch1 = clock();
    queue<pair<int, int > > q;
    q.push({x,0});
    while(!q.empty()) {
        int x = q.front().first, dist = q.front().second; q.pop();
        //cout << ix << '\n';
        if (!vis[x]) {
        if (x == 987654321) {
            cout << dist << '\n';
            break;
        }
        vis[x]=1;
        F(i,0,2) F(j,0,3) {
            x += (((x/p10[3*i+j])%10)*p10[3*(i+1)+j]) + (((x/p10[3*(i+1)+j])%10)*p10[3*(i)+j]) - (((x/p10[3*(i)+j])%10)*p10[3*(i)+j]) - (((x/p10[3*(i+1)+j])%10)*p10[3*(i+1)+j]);
            if (!vis[x]) q.push({x, dist+1});
            //swap(x[i][j], x[i+1][j]);
            x += (((x/p10[3*i+j])%10)*p10[3*(i+1)+j]) + (((x/p10[3*(i+1)+j])%10)*p10[3*(i)+j]) - (((x/p10[3*(i)+j])%10)*p10[3*(i)+j]) - (((x/p10[3*(i+1)+j])%10)*p10[3*(i+1)+j]);
        }
        F(i,0,3) F(j,0,2) {
            x += (((x/p10[3*i+j])%10)*p10[3*i+j+1]) + (((x/p10[3*i+1+j])%10)*p10[3*(i)+j]) - (((x/p10[3*(i)+j])%10)*p10[3*(i)+j]) - (((x/p10[3*i+1+j])%10)*p10[3*(i)+j+1]);
            //swap(x[i][j], x[i][j+1]);
            if (!vis[x]) q.push({x, dist+1});
            //swap(x[i][j], x[i][j+1]);
            x += (((x/p10[3*i+j])%10)*p10[3*i+j+1]) + (((x/p10[3*i+1+j])%10)*p10[3*(i)+j]) - (((x/p10[3*(i)+j])%10)*p10[3*(i)+j]) - (((x/p10[3*i+1+j])%10)*p10[3*(i)+j+1]);
        }
        }
    }
    //ch2 = clock();
    //cout << fixed << double(ch1-st)/double(CLOCKS_PER_SEC) << " " << double(ch2-st)/double(CLOCKS_PER_SEC) << setprecision(5) << '\n';
}