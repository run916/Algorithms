#include<bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/fair-distribution-of-cookies/

class Solution {
    public:
        // 获取数的二进制表示中，最低位的1对应整数
        int lowbit(int x) {
            return x & (-x);
        }
    int distributeCookies(vector < int > & cook, int k) {
        // 状态压缩动态规划
        int n = cook.size();
        int dp[k + 1][1 << n];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][(1 << n) - 1] = 0;
        // 预处理出每一种状态下的饼干数量
        int num[1 << n];
        num[0] = 0;
        for (int i = 1; i < (1 << n); i++) {
            num[i] = num[i - lowbit(i)] + cook[log2(lowbit(i))];
        }
        int m = (1 << n) - 1;
        for (int i = 1; i < k + 1; i++) {
            for (int j = 0; j < (1 << n); j++) {
                // 第i个人没有发任何零食
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                // 子集枚举第i个人发的零食数量
                int state = m ^ j;
                // 子集枚举
                for (int d = state; d; d = state & (d - 1)) {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][d | j], num[d]));
                }
            }
        }

        return dp[k][0];
    }
};