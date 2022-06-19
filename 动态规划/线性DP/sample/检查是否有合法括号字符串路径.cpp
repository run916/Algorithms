#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int countTexts(string press) {
            int mod = 1e9 + 7;
            int n = press.length();
            long long dp[n + 1];
            memset(dp, 0, sizeof(dp));
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
                if (i >= 1 && press[i - 1] == press[i]) {
                    dp[i + 1] = (dp[i - 1] + dp[i + 1]) % mod;
                } else {
                    continue;
                }
                if (i >= 2 && press[i - 2] == press[i]) {
                    dp[i + 1] = (dp[i - 2] + dp[i + 1]) % mod;
                } else {
                    continue;
                }
                if (press[i] == '7' || press[i] == '9') {
                    if (i >= 3 && press[i - 3] == press[i]) {
                        dp[i + 1] = (dp[i + 1] + dp[i - 3]) % mod;
                    } else {
                        continue;
                    }
                }
            }
            return dp[n];
        }
};