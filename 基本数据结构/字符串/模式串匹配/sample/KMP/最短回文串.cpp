// https://leetcode.cn/problems/shortest-palindrome/submissions/
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        string shortestPalindrome(string s) {
            // 也即意味这要找到最长回文串前缀
            // 马拉车？
            // KMP？
            int n = s.length();
            if (n <= 1) {
                return s;
            }
            string p = s;
            // 模式串求解pi数组
            int k = -1;
            int pi[n];
            pi[0] = -1;
            for (int i = 1; i < n; i++) {
                while (k != -1 && p[i] != p[k + 1]) k = pi[k];
                if (p[i] == p[k + 1]) k++;
                pi[i] = k;
            }
            //for(int i=0;i<n;i++)cout<<pi[i]<<" ";cout<<endl;
            // 将字符串反转
            reverse(s.begin(), s.end());
            // 求解最长匹配前缀
            k = -1;
            for (int i = 0; i < n; i++) {
                while (k != -1 && s[i] != p[k + 1]) k = pi[k];
                if (s[i] == p[k + 1]) k++;
            }
            string ans = "";
            ans += s.substr(0, n - k - 1);
            ans += p;
            return ans;
        }
};