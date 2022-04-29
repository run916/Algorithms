#include<bits/stdc++.h>

using namespace std;

// https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
class Solution {
    public:
        int dp[201][201];
    vector < vector < int >> mat;
    int n, m;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    void dfs(int x, int y) {
        // 记忆化搜索的精髓，及时终止，dp[x][y]记录了这一状态下的最优值，所以这里只需要终止递归就可以了。
        if (dp[x][y] > 0) {
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] > mat[x][y]) {
                dfs(nx, ny);
                dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);
            }
        }
        dp[x][y] = max(dp[x][y], 1);
        return;
    }
    int longestIncreasingPath(vector < vector < int >> & matrix) {
        memset(dp, 0, sizeof(dp));
        mat = matrix;
        n = mat.size();
        m = mat[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == 0) {
                    dfs(i, j);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};