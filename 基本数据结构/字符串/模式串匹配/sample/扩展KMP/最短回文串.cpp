// https://leetcode.cn/problems/shortest-palindrome/submissions/
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        string shortestPalindrome(string s) {
            // 扩展KMP算法
            string str = s;
            int n = s.length();
            if (n <= 1) {
                return s;
            }
            int nxt[n];
            nxt[0] = n;
            // 保存的应该是已经匹配的最大闭区间[l,r]
            int l = 1, r = 0;
            // 扩展KMP算法的思想依然是动态规划。
            // 与求解最长回文子串的马拉车算法相似。
            for (int i = 1; i < n; i++) {
                if (i + nxt[i - l] < r + 1) {
                    nxt[i] = nxt[i - l];
                } else {
                    nxt[i] = max(0, r - i + 1);
                    // 尝试暴力扩展
                    for (; i + nxt[i] < n && s[i + nxt[i]] == s[nxt[i]];) {
                        nxt[i]++;
                    }
                    // 此时右端点已经扩展了，将l更新为i，r更新为nxt[i]+i;
                    l = i;
                    r = nxt[i] + i - 1;
                }
            }
            reverse(str.begin(), str.end());
            // 开始匹配，同样的逻辑
            l = 0, r = 0;
            int ans[n];
            for (int i = 0; i < n; i++) {
                if (i + nxt[i - l] < r + 1) {
                    ans[i] = nxt[i - l];
                } else {
                    ans[i] = max(0, r - i + 1);
                    for (; ans[i] + i < n && ans[i] <= n && str[i + ans[i]] == s[ans[i]];) {
                        ans[i]++;
                    }
                    l = i;
                    r = i + ans[i] - 1;
                }
            }
            for (int i = 0; i < n; i++) {
                if (ans[i] + i == n) {
                    return str.substr(0, i) + s;
                }
            }
            return "";
        }
};