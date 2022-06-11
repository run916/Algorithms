#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        // 双端队列BFS
        deque<pair<int, int>> deq;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int n = grid.size();
        int m = grid[0].size();
        int dis[n][m];
        bool vise[n][m];
        memset(dis, 0x3f, sizeof(dis));
        memset(vise, false, sizeof(vise));

        deq.push_back({0, 0});
        dis[0][0] = 0;
        vise[0][0] = true;
        int x, y;
        while (!deq.empty())
        {
            x = deq.front().first;
            y = deq.front().second;
            deq.pop_front();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    if (grid[nx][ny] == 0 && !vise[nx][ny])
                    {
                        dis[nx][ny] = dis[x][y];
                        vise[nx][ny] = true;
                        deq.push_front({nx, ny});
                    }
                    if (grid[nx][ny] == 1 && !vise[nx][ny])
                    {
                        dis[nx][ny] = dis[x][y] + 1;
                        vise[nx][ny] = true;
                        deq.push_back({nx, ny});
                    }
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};