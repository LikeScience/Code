#include <bits/stdc++.h>

using namespace std;
#define vv vector<int>
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> nums(N);
    for (int &i : nums)
        cin >> i;

    vector<vector<int>> nums_pos(M + 1);
    for (int i = 0; i < N; i++)
        nums_pos[nums[i]].push_back(i);

    for (int x = 1; x <= M; x++)
    {
        int res = -1;
        if (nums_pos[x].size() != 0)
        {
            res = N - nums_pos[x].size() + 1;
            for (int pos : nums_pos[x])
            {
                int l1 = (pos - 1) % N;///5 5 7 -1 6
                int l2 = (pos - 2) % N;
                int r1 = (pos + 1) % N;
                int r2 = (pos + 2) % N;
                if (x >= max(nums[l1], nums[l2]) || x <= min(nums[l1], nums[l2]) || x >= max(nums[r1], nums[r2]) || x <= min(nums[r1], nums[r2]))
                {
                    res--;
                    break;
                }
            }
        }
        cout << res << " \n"[x == M];
    }
}