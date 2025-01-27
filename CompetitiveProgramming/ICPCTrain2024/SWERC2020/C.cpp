#include <bits/stdc++.h>

using namespace std;

vector<int> parents;
vector<vector<int>> paredes;

float calc_dist(pair<float, float> v1, pair<float, float> v2)
{
    float dh = v1.first - v2.first, dv = v1.second - v2.second;
    return (float) sqrt(dh * dh + dv * dv);
}


int find(int v)
{
    if (parents[v] == v) return v;
    return parents[v] = find(parents[v]);
}


int main()
{
    int W, H; cin >> W >> H;
    int N; cin >> N;


    vector<pair<float, float>> people (N);
    float new_x, new_y;
    for(int i = 0; i < N; i++)
    {
        cin >> new_x >> new_y;
        people[i] = {new_x, new_y};
    }

    priority_queue<pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>, greater<pair<float, pair<int, int>>>> dists;
    for(int i = 0; i < N; i++)
    {
        auto p = people[i];
        dists.push({calc_dist(p, {p.first, 0}), {i, N}});
        dists.push({calc_dist(p, {W, p.second}), {i, N+1}});
        dists.push({calc_dist(p, {p.first, H}), {i, N+2}});
        dists.push({calc_dist(p, {0, p.second}), {i, N+3}});

        for(int j = i+1; j < N; j++)
        {
            dists.push({calc_dist(people[i], people[j]) / 2, {i, j}});
        }
    }

    parents.resize(N+4);
    for(int i = 0; i < N+4; i++)
        parents[i] = i;
    paredes.resize(N+4);
    paredes[N].push_back(0);
    paredes[N+1].push_back(1);
    paredes[N+2].push_back(2);
    paredes[N+3].push_back(3);

    float dist = 0;
    bool possible = true;
 
    while(!dists.empty() && possible)
    {
        auto dist_tuple = dists.top();
        dists.pop();
        dist = dist_tuple.first;
        int v1 = dist_tuple.second.first, v2 = dist_tuple.second.second;
        int p1 = find(v1), p2 = find(v2);
        parents[p2] = p1;
        vector<int> plist = paredes[p1];

        for(int parede: paredes[p2])
            if(find(plist.begin(), plist.end(), parede) == plist.end())
                paredes[p1].push_back(parede);

        plist = paredes[p1];
        if(plist.size() > 2)
            possible = false;
        else if(plist.size() == 2)
        {
            sort(plist.begin(), plist.end());
            if(!(plist[0] == 0 && plist[1] == 1) && !(plist[0] == 2 && plist[1] == 3))
                possible = false;
        }
    }

    cout << dist << '\n';
}