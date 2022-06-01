#include<bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/apply-discount-to-prices/

class Solution {
    public:
        string discountPrices(string s, int discount) {
            // 字符串处理
            // C++如何四舍五入保留两位有效数字
            int n = s.length();
            string ans = "";
            string str = "";
            long long num = 0;
            bool tag = false;
            for (int i = 0; i < n; i++) {
                if (s[i] == ' ') {
                    if (tag && num > 0) {
                        str += to_string((double)(100 - discount) / 100 * num + 0.005);
                        str = str.substr(0, str.find('.') + 2 + 1);
                        num = 0;
                    }
                    ans += str + " ";
                    str = "";
                    num = 0;
                    tag = false;
                } else if ((s[i] == '$' && i == 0) || (s[i] == '$' && i > 0 && s[i - 1] == ' ')) {
                    str += "$";
                    tag = true;
                } else {
                    if (tag) {
                        if (s[i] > '9' || s[i] < '0') {
                            tag = false;
                            if (num > 0) str += to_string(num);
                            str += s[i];
                            num = 0;
                        } else {
                            num = num * 10 + s[i] - '0';
                        }
                    } else {
                        str += s[i];
                    }
                }
            }
            if (tag && num > 0) {
                str += to_string((double)(100 - discount) / 100 * num + 0.005);
                str = str.substr(0, str.find('.') + 2 + 1);
                num = 0;
                tag = false;
            }
            ans += str;
            return ans;
        }
};