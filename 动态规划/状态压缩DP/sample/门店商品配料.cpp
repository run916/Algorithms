#include<bits/stdc++.h>

using namespace std;

// https://leetcode.cn/contest/zj-future2022/problems/NBCXIp/

class Solution {
    public:
        int lowbit(int & x) {
            return x & (-x);
        }
    int minTransfers(vector < vector < int >> & dis) {
        //  先统计出所有需要调整的位置
        int n = dis.size();
        int vise[12];
        memset(vise, 0, sizeof(vise));
        for (int i = 0; i < n; i++) {
            vise[dis[i][1]] += dis[i][2];
            vise[dis[i][0]] -= dis[i][2];
        }
        // 开始调配,子集枚举即可
        vector < int > u, v;
        for (int i = 0; i < 12; i++) {
            if (vise[i] > 0) {
                u.push_back(vise[i]);
            }
            if (vise[i] < 0) {
                v.push_back(-vise[i]);
            }
        }
        // 如果没有商店超出，那么直接返回0
        if (u.size() == 0) {
            return 0;
        }
        // 建立预处理数组
        int numu[1 << u.size()], numv[1 << v.size()], sumu[1 << u.size()], sumv[1 << v.size()];
        numu[0] = numv[0] = sumu[0] = sumv[0] = 0;
        for (int i = 1; i < (1 << u.size()); i++) {
            numu[i] = numu[i - lowbit(i)] + 1;
            sumu[i] = sumu[i - lowbit(i)] + u[log2(lowbit(i))];
        }
        for (int i = 1; i < (1 << v.size()); i++) {
            numv[i] = numv[i - lowbit(i)] + 1;
            sumv[i] = sumv[i - lowbit(i)] + v[log2(lowbit(i))];
        }
        // 状态压缩动态规划
        int dp[1 << u.size()][1 << v.size()];
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 1; i < (1 << u.size()); i++) {
            for (int j = 1; j < (1 << v.size()); j++) {
                if (sumu[i] != sumv[j]) {
                    continue;
                }
                dp[i][j] = numu[i] + numv[j] - 1;
                // 子集枚举
                bool tag = false;
                for (int k = i; k; k = i & (k - 1)) {
                    for (int d = j; d; d = j & (d - 1)) {
                        dp[i][j] = min(dp[i][j], dp[k][d] + dp[i ^ k][j ^ d]);
                    }
                }
            }
        }
        return dp[(1 << u.size()) - 1][(1 << v.size()) - 1];
    }
};