#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n, m, a, b, c=0;
    bool k, x;
    cin >> n >> m;
    vector <int> v[n+1];

    bool visited[n+1]={};

    for (int i=0; i<m; i++){
        cin >> a >> b;
        if (count(v[a].begin(), v[a].end(), b)==0){
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }

    for(int i=1; i<=n; i++){
        k=false;
        x=true;
        queue <pair<int, int> > q;        
        if (!visited[i]){
            visited[i]=true;
            q.push({i, -1});
            while (!q.empty()) {
                int s = q.front().first;
                int r = q.front().second;
                //cout << s << " " << v[s].size() << '\n';
                if (2 != (int)v[s].size()){
                    x=false;
                    
                }
                q.pop();
                for (auto u : v[s]) {
                    if (!visited[u]){
                        visited[u] = true;
                        q.push({u, s});

                    }
                    if (visited[u] && u!=r){
                       k = true;
                    }
                }
            }
            
         if (k && x){
            c++;
         }
          //cout << c << '\n';
        }
    }

    cout << c << '\n';

    return 0;
}