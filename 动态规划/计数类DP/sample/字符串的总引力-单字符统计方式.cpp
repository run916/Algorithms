#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long appealSum(string & s) {
            int n = s.length();
            long long ans = 0;
            // 单个元素统计
            long long sum = 0;
            int vise[26];
            memset(vise, -1, sizeof(vise));
            for (int i = 0; i < n; i++) {
                int c = s[i] - 'a';
                // 对于从第i个开始向前遍历的字符串来说，如果一个字符在首先在第j个位置出现了，那么它总共会被统计j+1次，
                // 而且只要当前遍历的元素不是该字符，那么该字符增加的引力始终是j+1。
                // 如果第i个位置是该字符，那么我们统计的区间变成i了，假设之前所有字符可以增加的总的引力值都在sum中，
                // 当第i个元素时该字符时，sum增加(i-j)的引力值，我们只需要统计进去就可以了。
                sum += i - vise[c];
                vise[c] = i;
                ans += sum;
            }
            return ans;
        }
};