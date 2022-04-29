#include<bits/stdc++.h>

using namespace std;

// https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
    public:
        int longestIncreasingPath(vector < vector < int >> & matrix) {
            // 首先构建图，然后构建拓扑排序后dp即可
            int dx[2] = {
                0,
                1
            };
            int dy[2] = {
                1,
                0
            };
            int n = matrix.size();
            int m = matrix[0].size();
            vector < vector < int >> g(n * m);
            // 构图
            int degree[n * m];
            memset(degree, 0, sizeof(degree));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    for (int k = 0; k < 2; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x >= 0 && x < n && y >= 0 && y < m) {
                            if (matrix[x][y] > matrix[i][j]) {
                                g[i * m + j].push_back(x * m + y);
                                degree[x * m + y]++;
                            }
                            if (matrix[x][y] < matrix[i][j]) {
                                g[x * m + y].push_back(i * m + j);
                                degree[i * m + j]++;
                            }
                        }
                    }
                }
            }
            // 拓扑排序
            queue < int > que;
            int dp[n * m];
            memset(dp, 0, sizeof(dp));
            for (int i = 0; i < n * m; i++) {
                if (degree[i] == 0) {
                    que.push(i);
                    dp[i] = 1;
                }
            }
            while (!que.empty()) {
                int k = que.front();
                que.pop();
                for (int i = 0; i < g[k].size(); i++) {
                    degree[g[k][i]]--;
                    dp[g[k][i]] = max(dp[g[k][i]], dp[k] + 1);
                    if (degree[g[k][i]] == 0) {
                        que.push(g[k][i]);
                    }
                }
            }
            // 做dp
            int ans = 0;
            for (int i = 0; i < n * m; i++) {
                ans = max(ans, dp[i]);
            }
            return ans;
        }
};