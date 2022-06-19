#include<bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/selling-pieces-of-wood/

class Solution {
    public:
        long long sellingWood(int m, int n, vector < vector < int >> & price) {
            // 动态规划
            long long dp[m + 1][n + 1];
            memset(dp, 0, sizeof(dp));
            for (int i = 0; i < price.size(); i++) {
                dp[price[i][0]][price[i][1]] = max(dp[price[i][0]][price[i][1]], (long long) price[i][2]);
            }
            // 开始做dp
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    for (int k = 1; k <= i; k++) {
                        dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);
                    }
                    for (int k = 1; k <= j; k++) {
                        dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);
                    }
                }
            }
            return dp[m][n];

        }
};