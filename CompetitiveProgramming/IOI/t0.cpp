#include <bits/stdc++.h>

using namespace std;
typedef long long int lld;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define trav(a,v) for(auto a: v)

void DFS(int node){
    visited[node]=true;
    trav(a,nei[node]){
        if(!visited[a])DFS(a);
    }
}