#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner/

class Solution
{
public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        // Dijkstra算法优化
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        // 优先级队列堆顶为当前未扩展点中与源点距离最短的点。
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        // 存储距离
        int dis[n][m];
        memset(dis, 0x3f, sizeof(dis));
        // 标记是否被遍历
        bool vise[n][m];
        memset(vise, false, sizeof(vise));

        int ans = 0;
        que.emplace(0, 0);
        int x, y, nx, ny;
        dis[0][0] = 0;
        while (!que.empty())
        {
            int k = que.top().first;
            x = que.top().second / m;
            y = que.top().second % m;
            que.pop();
            if (vise[x][y])
            {
                continue;
            }
            vise[x][y] = true;
            if (x == n - 1 && y == m - 1)
            {
                ans = k;
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                nx = x + dx[i];
                ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vise[nx][ny])
                {
                    if (grid[nx][ny] == 0 && dis[nx][ny] > k)
                    {
                        que.emplace(k, nx * m + ny);
                        dis[nx][ny] = k;
                    }
                    if (grid[nx][ny] == 1 && dis[nx][ny] > k + 1)
                    {
                        que.emplace(k + 1, nx * m + ny);
                        dis[nx][ny] = k + 1;
                    }
                }
            }
        }
        return ans;
    }
};