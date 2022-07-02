#include<bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/maximum-score-of-spliced-array/

// 本质上，这是一道利用贪心思想求解的题

class Solution {
    public:
        int maximumsSplicedArray(vector < int > & nums1, vector < int > & nums2) {
            // 最大区间差，由于是连续区间，所以只要判断是正数就可以操作
            int n = nums1.size();
            vector < int > a(n);
            vector < int > b(n);
            int sum1 = 0;
            int sum2 = 0;
            for (int i = 0; i < n; i++) {
                a[i] = nums1[i] - nums2[i];
                sum1 += nums1[i];
                b[i] = nums2[i] - nums1[i];
                sum2 += nums2[i];
            }
            int min_num = 0;
            int id = -1;
            int ans = sum1;
            int now = 0;
            for (int i = 0; i < n; i++) {
                now += b[i];
                ans = max(ans, sum1 + now - min_num);
                if (min_num > now) {
                    min_num = now;
                    id = i;
                }
            }
            now = 0;
            min_num = 0;
            int ans1 = sum2;
            id = -1;
            for (int i = 0; i < n; i++) {
                now += a[i];
                ans1 = max(ans1, sum2 + now - min_num);
                if (min_num > now) {
                    min_num = now;
                    id = i;
                }
            }
            return max(ans, ans1);
        }
};