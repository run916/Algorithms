#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        // BFS+标记解法
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        queue<pair<int, int>> que;
        int dis[n][m];
        memset(dis, 0x3f, sizeof(dis));
        dis[0][0] = 0;
        que.push({0, 0});
        int x, y;
        while (!que.empty())
        {
            x = que.front().first / m;
            y = que.front().first % m;
            int k = que.front().second;
            que.pop();
            // 关键点在于这一步的剪枝操作
            if (dis[x][y] != k)
            {
                continue;
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                {
                    if (grid[nx][ny] == 0 && dis[nx][ny] > k)
                    {
                        dis[nx][ny] = k;
                        que.push({nx * m + ny, k});
                    }
                    if (grid[nx][ny] == 1 && dis[nx][ny] > k + 1)
                    {
                        dis[nx][ny] = k + 1;
                        que.push({nx * m + ny, k + 1});
                    }
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};