// https://leetcode.cn/problems/check-if-there-is-a-valid-parentheses-string-path/
#include<bits/stdc++.h>

using namespace std;

// 利用状态压缩来存储中间集合，可以保存所有有效状态。

class Solution {
    public:
        bool hasValidPath(vector < vector < char >> & grid) {
            // 状态压缩动态规划？
            int n = grid.size();
            int m = grid[0].size();
            if ((n + m - 1) % 2 == 1 || grid[0][0] == ')') {
                return false;
            }
            bitset < 100 > dp[n][m];
            dp[0][0][1] = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (j > 0) {
                        if (grid[i][j] == '(') {
                            dp[i][j] |= (dp[i][j - 1] << 1);
                        } else {
                            dp[i][j] |= (dp[i][j - 1] >> 1);
                        }
                    }
                    if (i > 0) {
                        if (grid[i][j] == '(') {
                            dp[i][j] |= (dp[i - 1][j] << 1);
                        } else {
                            dp[i][j] |= (dp[i - 1][j] >> 1);
                        }
                    }
                }
            }
            // 判断
            if (dp[n - 1][m - 1][0] == 1) {
                return true;
            }
            return false;
        }
};