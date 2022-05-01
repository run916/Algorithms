#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int countDistinct(vector < int > & nums, int k, int p) {
            // 统计数目的
            // 暴力枚举？
            set < vector < int >> set;
            int vise = 0;
            vector < int > tmp;
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                vise = 0;
                for (int j = i; j < n; j++) {
                    if (nums[j] % p == 0) vise++;
                    if (vise > k) {
                        break;
                    }
                    tmp = vector < int > (nums.begin() + i, nums.begin() + j + 1);
                    set.insert(tmp);
                }
            }
            return set.size();
        }
};