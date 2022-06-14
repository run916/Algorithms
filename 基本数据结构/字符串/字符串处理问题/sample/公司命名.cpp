#include<bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/naming-a-company/

class Solution {
    public:
        long long distinctNames(vector < string > & ideas) {
            // 思维题
            int n = ideas.size();
            unordered_set < string > set;
            for (int i = 0; i < n; i++) {
                set.insert(ideas[i]);
            }
            // 初始化
            int vise[26][26];
            memset(vise, 0, sizeof(vise));
            long long ans = 0;
            for (int i = 0; i < n; i++) {
                string s = ideas[i];
                for (char j = 'a'; j <= 'z'; j++) {
                    s[0] = j;
                    if (set.count(s) == 0) {
                        vise[ideas[i][0] - 'a'][j - 'a']++;
                    }
                }
            }
            for (int i = 0; i < 26; i++) {
                for (int j = i + 1; j < 26; j++) {
                    ans += vise[i][j] * vise[j][i];
                }
            }
            return ans * 2;

        }
};