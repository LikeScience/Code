#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void caso()
{
    int n, k; cin >> n >> k;
    
    vector<int> adj [n+1];
    int num_adj[n+1] {};
    int v1, v2;
    for(int i = 0; i < n-1; i++)
    {
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        num_adj[v1]++;
        adj[v2].push_back(v1);
        num_adj[v2]++;
    }

    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        // BFS
        queue<int> fila; fila.push(i);
        bool visited[n+1] {};
        int dist[n+1];
        dist[i] = 0;

        if(num_adj[i] == 1){
            if (dist[i] >= k) res++; 
            //cout << i << " CARALHO!!!" << '\n';
            continue;
        }

        bool encontrado;
        int v; 
        while(!fila.empty())
        {
            encontrado = false;
            v = fila.front(); fila.pop();

            for (int u : adj[v])
            {
                if (!visited[u]){

                    fila.push(u);
                    visited[u] = true;
                    dist[u] = dist[v] + 1;

                    if(num_adj[u] == 1){
                        if (dist[u] >= k) res++;
                        encontrado = true;
                        break;
                    }
                }
            }

            if (encontrado) break;
        }
        // fim BFS
    }

    cout << res << '\n';
}

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int t; cin >> t;
    for (int i = 0; i < t; i++)
        caso();
}