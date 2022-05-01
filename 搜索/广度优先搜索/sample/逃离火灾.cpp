// https://leetcode-cn.com/problems/escape-the-spreading-fire/
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maximumMinutes(vector < vector < int >> & grid) {
            // 不通过二分+判定的思想求解
            int n = grid.size();
            int m = grid[0].size();
            // 着火时间
            int fire[n][m];
            memset(fire, 0x7f, sizeof(fire));
            queue < int > que;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 1) {
                        fire[i][j] = 0;
                        que.push(i * m + j);
                    }
                }
            }
            int dx[4] = {
                1,
                -1,
                0,
                0
            };
            int dy[4] = {
                0,
                0,
                1,
                -1
            };
            // 求解fire数组
            while (!que.empty()) {
                int x = que.front() / m;
                int y = que.front() % m;
                que.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != 2 && fire[nx][ny] > 100000000) {
                        que.push(nx * m + ny);
                        fire[nx][ny] = fire[x][y] + 1;
                    }
                }
            }

            // 然后求解出，人到达终点的最小值。
            int vise[n][m];
            memset(vise, -1, sizeof(vise));
            que.push(0);
            vise[0][0] = 0;
            while (!que.empty()) {
                int x = que.front() / m;
                int y = que.front() % m;
                que.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != 2 && vise[nx][ny] == -1) {
                        que.push(nx * m + ny);
                        vise[nx][ny] = vise[x][y] + 1;
                    }
                }
            }
            // 目标位置根本不可达，那么输出-1
            if (vise[n - 1][m - 1] == -1) {
                return -1;
            }
            // 然后判断人到达最后一个位置的时间，与火到达目标点之间的差值即可。
            // 需要考虑火烧屁股这一情况，我们只需要将这种情况单独讨论即可。
            int t = fire[n - 1][m - 1] - vise[n - 1][m - 1];
            memset(vise, 0, sizeof(vise));
            if (t >= 0 && t < 10000000) {
                // 在判断一次
                queue < pair < int, int >> q;
                q.push({
                    0,
                    t
                });
                while (!q.empty()) {
                    int x = q.front().first / m;
                    int y = q.front().first % m;
                    int k = q.front().second;
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != 2 && !vise[nx][ny]) {
                            if (nx * m + ny == n * m - 1 && k + 1 == fire[nx][ny]) {
                                vise[nx][ny] = true;
                            }
                            if (k + 1 < fire[nx][ny]) {
                                q.push({
                                    nx * m + ny,
                                    k + 1
                                });
                                vise[nx][ny] = 1;
                            }

                        }
                    }
                }
                if (vise[n - 1][m - 1]) {
                    return t;
                } else {
                    return t - 1;
                }
            } else {
                if (t > 10000000) {
                    return 1000000000;
                } else {
                    return -1;
                }
            }
        }
};