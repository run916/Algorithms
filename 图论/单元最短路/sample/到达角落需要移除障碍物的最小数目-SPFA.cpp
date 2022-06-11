#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner/

class Solution
{
public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        // SPFA
        // 实际上就是BFS+剪枝的过程
        queue<int> que;
        int n = grid.size();
        int m = grid[0].size();
        bool vise[n][m];
        memset(vise, false, sizeof(vise));
        int dis[n][m];
        memset(dis, 0x3f, sizeof(dis));
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        que.push(0);
        dis[0][0] = 0;
        vise[0][0] = true;
        int x, y, nx, ny;
        while (!que.empty())
        {
            x = que.front() / m;
            y = que.front() % m;
            que.pop();
            vise[x][y] = false;
            for (int i = 0; i < 4; i++)
            {
                nx = x + dx[i];
                ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    int k = grid[nx][ny] == 1 ? 1 : 0;
                    // 剪枝2
                    if (dis[nx][ny] > dis[x][y] + k)
                    {
                        dis[nx][ny] = dis[x][y] + k;
                        if (!vise[nx][ny])
                        {
                            que.push(nx * m + ny);
                            // 剪枝1
                            vise[nx][ny] = true;
                        }
                    }
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};