#include<bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/minimum-score-after-removals-on-a-tree/

class Solution {
    public:
        vector < vector < int >> g;
    vector < int > num;
    bool vise[1010];
    int dp[1010];
    // 还要有一个集合，用来判断是否包含
    vector < set < int >> mset;
    void dfs(int k) {
        vise[k] = true;
        dp[k] = num[k];
        mset[k].insert(k);
        for (int i = 0; i < g[k].size(); i++) {
            if (!vise[g[k][i]]) {
                dfs(g[k][i]);
                for (auto x: mset[g[k][i]]) {
                    mset[k].insert(x);
                }
                dp[k] ^= dp[g[k][i]];
            }
        }
        return;
    }
    int minimumScore(vector < int > & nums, vector < vector < int >> & edges) {
        // 所有结果是不重叠的，所以只要找到一种扩展方式即可
        int n = nums.size();
        num = nums;
        g = vector < vector < int >> (n);
        mset = vector < set < int >> (n);
        // 构图
        for (int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        memset(vise, false, sizeof(vise));
        // dfs，默认根节点为0
        dfs(0);
        // 枚举
        int ans = INT_MAX;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (mset[i].count(j)) {
                    ans = min(ans, max(dp[0] ^ dp[i], max(dp[i] ^ dp[j], dp[j])) - min(dp[0] ^ dp[i], min(dp[i] ^ dp[j], dp[j])));
                } else if (mset[j].count(i)) {
                    ans = min(ans, max(dp[0] ^ dp[j], max(dp[j] ^ dp[i], dp[i])) - min(dp[0] ^ dp[j], min(dp[j] ^ dp[i], dp[i])));
                } else {
                    ans = min(ans, max(dp[0] ^ dp[i] ^ dp[j], max(dp[i], dp[j])) - min(dp[0] ^ dp[i] ^ dp[j], min(dp[i], dp[j])));
                }
            }
        }
        return ans;
    }
};