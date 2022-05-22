#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int subarraySum(vector < int > & nums, int k) {
            // 非常典型的一种技巧，可以用于很多问题的优化，要牢记
            // 求解何为K的最长子数组
            // 求解何为K的非空数组数目
            // 这两类问题都可以用前缀和+哈希的方式求解。
            int n = nums.size();
            unordered_map < int, int > hash;
            int sum = 0;
            hash[0] = 1;
            int ans = 0;
            for (int i = 0; i < n; i++) {
                sum += nums[i];
                hash[sum]++;
                ans += hash[sum - k];
            }
            if (k == 0) ans -= n;
            return ans;
        }
};