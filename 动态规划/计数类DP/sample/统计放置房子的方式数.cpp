#include<bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/count-number-of-ways-to-place-houses/

class Solution {
    public:
        int countHousePlacements(int n) {
            // 简单计数类dp，背包问题的变种
            // 当前位置可选状态只有4种，这四种状态只和前面的状态有关
            long long dp[n + 1][4];
            memset(dp, 0, sizeof(dp));
            int mod = 1e9 + 7;
            dp[0][0] = 1; // 初始化化
            for (int i = 1; i <= n; i++) {
                // 一共有四种状态
                // 0表示当前位置不放置房子
                dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][0] + dp[i - 1][3]) % mod;
                // 1表示当前位置只有上面的街道放置了房子
                dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
                // 2表示当前位置只有下面的街道放置了房子
                dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
                // 3表示上下两个位置都放置了房子
                dp[i][3] = (dp[i - 1][0]) % mod;
            }
            // 最后统计所有的结果即可
            long long ans = 0;
            ans = (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3]);
            ans %= mod;
            return ans;



        }
};