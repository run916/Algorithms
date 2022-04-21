#include<bits/stdc++.h>

#include "c:\Users\windows\Desktop\Algorithm\Algorithms\std\input.h"

using namespace std;

class Solution {
    public:
        int defendSpaceCity(vector < int > & time, vector < int > & position) {
            int n = time.size();
            int pos[102];
            memset(pos, 0, sizeof(pos));
            for (int i = 0; i < n; i++) {
                pos[position[i]] += 1 << (time[i] - 1);
            }
            int one[1 << 5];
            int two[1 << 5];
            memset(one, 0, sizeof(one));
            memset(two, 0, sizeof(two));
            // 预处理出每一个状态开启单个防护罩的最小开销，以及开启关联防护罩的最小开销
            for (int i = 1; i < (1 << 5); i++) {
                for (int j = 0; j < 5; j++) {
                    if (i & (1 << j)) {
                        if (j > 0 && (i & (1 << (j - 1)))) {
                            one[i] += 1;
                            two[i] += 1;
                        } else {
                            one[i] += 2;
                            if (j > 1 && ((i & (1 << (j - 2))))) {
                                two[i] += 2;
                            } else {
                                two[i] += 3;
                            }
                        }
                    }
                }
            }
            // 定义dp数组，状态表示开启关联防护罩的时刻
            int dp[103][1 << 5];
            memset(dp, 0x3f, sizeof(dp));
            dp[0][0] = 0;
            int m = (1 << 5) - 1;
            for (int i = 0; i < 102; i++) {
                // 枚举所有可能的dp[i+1][j]
                for (int j = 0; j < (1 << 5); j++) {
                    int state = m ^ j;
                    // 枚举k，k=0的情况单独处理
                    dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + one[state & pos[i]]);
                    for (int k = state; k; k = state & (k - 1)) {
                        // k表示开启关联防护罩
                        dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + one[(k ^ state) & pos[i]] + two[k]);
                    }
                }
            }
            // 返回最小值即可
            return dp[101][0];
        }
};

int main() {
    string s;
    cin >> s;
    vector < int > time = transfer(s);
    cin >> s;
    vector < int > pos = transfer(s);
    Solution solve;
    cout<<solve.defendSpaceCity(time, pos);
    return 0;
}