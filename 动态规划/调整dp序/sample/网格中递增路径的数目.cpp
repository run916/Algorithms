#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/number-of-increasing-paths-in-a-grid/

class Solution
{
public:
    int countPaths(vector<vector<int>> &grid)
    {
        int mod = 1e9 + 7;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        // 最多是nlogn的
        int n = grid.size();
        int m = grid[0].size(); // 单纯的BFS可以做
        // 单纯的BFS可以做
        vector<vector<int>> num(n * m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                num[i * m + j] = {grid[i][j], i, j};
            }
        }
        // 建立拓扑序
        sort(num.begin(), num.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });
        // 建立坐标与拓扑序中位置的关系
        int hash[n][m];
        for (int i = 0; i < n * m; i++)
        {
            hash[num[i][1]][num[i][2]] = i;
        }
        long long dp[n * m];
        dp[0] = 1;
        int nx, ny;
        for (int i = 1; i < n * m; i++)
        {
            dp[i] = 1;
            for (int j = 0; j < 4; j++)
            {
                nx = num[i][1] + dx[j];
                ny = num[i][2] + dy[j];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] < num[i][0])
                {
                    dp[i] += dp[hash[nx][ny]];
                    dp[i] %= mod;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < n * m; i++)
        {
            ans += dp[i];
            ans %= mod;
        }
        return ans;
    }
};