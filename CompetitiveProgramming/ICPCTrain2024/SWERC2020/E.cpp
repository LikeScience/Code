#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N; cin >> N;
    int res = 1000000;
    int u, v;
    for(int i = 0; i < N; i++)
    {
        cin >> u >> v;
        res = min(res, v / u);
    }
    cout << res << '\n';
}