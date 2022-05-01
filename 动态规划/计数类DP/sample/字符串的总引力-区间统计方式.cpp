// https://leetcode-cn.com/problems/total-appeal-of-a-string/
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long appealSum(string s) {
            int n = s.length();
            int vise[26][n + 1];
            memset(vise, -1, sizeof(vise));
            vise[s[0] - 'a'][0] = 0;
            for (int i = 1; i < n; i++) {
                int d = s[i] - 'a';
                for (int j = 0; j < 26; j++) {
                    if (d == j) {
                        vise[j][i] = i;
                    } else {
                        vise[j][i] = vise[j][i - 1];
                    }
                }
            }
            // 开始做dp
            long long dp[n + 1];
            memset(dp, 0, sizeof(dp));
            // 需要注意的是重复创建数组的时间复杂度，会明显超过使用同一个数组的时间复杂度。
            vector < int > seq;
            for (int i = 0; i < n; i++) {
                // 开始dp
                dp[i + 1] += dp[i];
                // 计算，这里用seq.clear()，会显著降低时间复杂度。
                seq.clear();
                for (int k = 0; k < 26; k++) {
                    if (vise[k][i] >= 0) {
                        seq.push_back(vise[k][i]);
                    }
                }
                sort(seq.begin(), seq.end(), [](int & a, int & b) {
                    return a > b;
                });
                seq.push_back(-1);
                // 开始计算
                for (int k = 1; k < seq.size(); k++) {
                    dp[i + 1] += (seq[k - 1] - seq[k]) * k;
                }
            }
            return dp[n];

        }
};