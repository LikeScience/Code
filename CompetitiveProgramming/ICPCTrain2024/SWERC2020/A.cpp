#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K; cin >> N >> K;
    string s;
    getline(cin, s);
    unordered_map<string, pair<int, int>> occurences;
    for(int i = 0; i < 3*N; i++)
    {
        getline(cin, s);
        occurences[s].first++;
        occurences[s].second = i;
    }
    vector<pair<pair<int, int>, string>> vec;
    for(auto i : occurences)
        vec.push_back({i.second, i.first});

    sort(vec.begin(), vec.end());
    int limit = min(K, (int) vec.size());
    for(int i = 0; i < limit; i++)
        cout << vec[vec.size() - i - 1].second << '\n';
}