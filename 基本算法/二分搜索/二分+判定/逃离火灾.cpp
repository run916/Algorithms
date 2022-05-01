//
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maximumMinutes(vector < vector < int >> & grid) {
            // 二分+判定
            int n = grid.size();
            int m = grid[0].size();
            queue < int > fire;
            // 初始化dp数组，用来存储火焰燃烧到某个位置最少的时间
            int dp[n * m];
            memset(dp, 0x7f, sizeof(dp));
            // 初始化找到所有有火焰的格子
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 1) {
                        fire.push(i * m + j);
                        dp[i * m + j] = 0;
                    }
                }
            }
            // bfs扩展求解出每个草坪被点燃的时间，用于后面二分+判定
            int dx[4] = {1, -1, 0, 0};
            int dy[4] = {0, 0, 1, -1};
            while (!fire.empty()) {
                int x = fire.front() / m;
                int y = fire.front() % m;
                fire.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != 2 && dp[nx * m + ny] > 1000000000) {
                        fire.push(nx * m + ny);
                        dp[nx * m + ny] = min(dp[nx * m + ny], dp[x * m + y] + 1);
                    }
                }
            }

            // 二分+判定
            // 二分最大可以停留时间，然后将队列初始状态中的时间设置为该值，判断在这种状态下是否可以逃到终点。
            int ans = INT_MAX;
            int l = 0, r = 100000;
            queue < pair < int, int >> que;
            bool vise[n * m];
            while (l <= r) {
                int mi = (l + r) / 2;
                while (!que.empty()) que.pop();
                memset(vise, false, sizeof(vise));
                // 判断
                que.push({ 0, mi});
                vise[0] = true;
                while (!que.empty()) {
                    int k = que.front().first;
                    int t = que.front().second;
                    if (k == n * m - 1) {
                        break;
                    }
                    que.pop();
                    int x = k / m;
                    int y = k % m;
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != 2 && !vise[nx * m + ny]) {
                            if (nx * m + ny == n * m - 1 && t + 1 <= dp[nx * m + ny]) {
                                que.push({ nx * m + ny, t + 1});
                                vise[nx * m + ny] = true;
                                break;
                            }
                            if (t + 1 < dp[nx * m + ny]) {
                                // 只有到达该位置时，t的值小于火烧到该位置的值，才能添加到队列中
                                que.push({ nx * m + ny, t + 1});
                                vise[nx * m + ny] = true;
                            }
                        }
                    }
                }
                if (vise[n * m - 1]) {
                    l = mi + 1;
                } else {
                    r = mi - 1;
                }
            }
            if (l >= 100000) {
                return 1000000000;
            } else {
                return l - 1;
            }

        }
};