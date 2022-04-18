#include <bits/stdc++.h>

#include "c:\Users\windows\Desktop\Algorithm\Algorithms\std\input.h"

using namespace std;

// https://leetcode-cn.com/problems/calculate-digit-sum-of-a-string/
// 这道题包含了很多模块化处理的东西，所以这里做一个记录

class Solution {
    public:
        // 字符串转数字
        int to_int(string s) {
            int n = s.length();
            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans += s[i] - '0';
            }
            return ans;
        }
    // 数字转字符串
    string to_string(int x) {
        if (x == 0) {
            return "0";
        }
        string s = "";
        for (; x; x /= 10) {
            int d = x % 10;
            s = (char)('0' + d) + s;
        }
        return s;
    }
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string str = "";
            string tmp = "";
            for (int i = 0; i < s.length(); i++) {
                if (i % k == 0 && i != 0) {
                    tmp += to_string(to_int(str));
                    str = "";
                    str += s[i];
                } else {
                    str += s[i];
                }
            }
            tmp += to_string(to_int(str));
            s = tmp;
        }
        return s;
    }
};

int main() {
    string s;
    cin >> s;
    s = del_quote(s);
    int k;
    cin >> k;
    Solution solve;
    string ans = solve.digitSum(s, k);
    cout << ans;
    return 0;
}