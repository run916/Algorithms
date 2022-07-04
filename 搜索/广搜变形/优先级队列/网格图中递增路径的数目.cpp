#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/number-of-increasing-paths-in-a-grid/

class Solution
{
public:
    int countPaths(vector<vector<int>> &grid)
    {
        // 优先级队列扩展BFS
        int mod = 1e9 + 7;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        long long dp[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i][j] = 1;
                bool tag = true;
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                    {
                        if (grid[nx][ny] < grid[i][j])
                        {
                            tag = false;
                            break;
                        }
                    }
                }
                if (tag)
                {
                    que.push({grid[i][j], i * m + j});
                }
            }
        }
        // 类似于Dijkstra和最小生成树算法
        bool vise[n][m];
        memset(vise, false, sizeof(vise));
        while (!que.empty())
        {
            int x = que.top().second / m;
            int y = que.top().second % m;
            que.pop();
            if (vise[x][y])
            {
                continue;
            }
            vise[x][y] = true;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    if (grid[x][y] < grid[nx][ny])
                    {
                        que.push({grid[nx][ny], nx * m + ny});
                        dp[nx][ny] += dp[x][y];
                        dp[nx][ny] %= mod;
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans += dp[i][j];
                ans %= mod;
            }
        }
        return ans;
    }
};