#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i=a; i<b;i++)
#define mp map<int, vv> 
#define vv vector<int>
#define INF 1e9
#define pr pair<int,int>

mp m;
vv dist;
void dfs(int u, int k){
    dist[u]=k;
    k++;
    for (int y: m[u]){
        if (dist[y]>k){
            dfs(y,k);
        }
    }
}


int main(){
    int n,M;
    cin>>n>>M;
    int a,b;

    FOR(i,0,M){
        cin>>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    int u=1;
    set<int> visited;
    int best=0;

    FOR(j,0,10){
        
        visited.insert(u);
        dist=vv(n+1, INF);
        dfs(u,0);
        vector<pr> temp(n);
        FOR(i,0,n)temp[i]=make_pair(dist[i], i);
        sort(temp.rbegin(), temp.rend());
        //FOR(e,0,n+1)cout<<temp[e].first<<" "<<temp[e].second<<endl;

        int qwe=1;
        while(qwe < n+1 ){
            
            //cout<<qwe<<endl;
            if (!visited.count(temp[qwe].second))break;
            qwe++;
        }
        if (qwe==n)break;
        best=max(best, temp[qwe].first);
        u=temp[qwe].second;

    }

    cout<<(((int)log2(best))+1)<<endl;

}