// https://leetcode-cn.com/problems/minimum-average-difference/
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int minimumAverageDifference(vector < int > & nums) {
            int n = nums.size();
            long long a[n];
            long long b[n];
            a[0] = nums[0];
            for (int i = 1; i < n; i++) {
                a[i] = a[i - 1] + nums[i];
            }
            b[n - 1] = nums[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                b[i] = nums[i] + b[i + 1];
            }

            int ans = INT_MAX;
            int index;
            for (int i = 0; i < n - 1; i++) {
                //cout<<abs(a[i]/(i+1)-b[i+1]/(n-i-1))<<endl;
                if (ans > abs(a[i] / (i + 1) - b[i + 1] / (n - i - 1))) {
                    ans = abs(a[i] / (i + 1) - b[i + 1] / (n - i - 1));
                    index = i;
                }
            }
            if (ans > abs(a[n - 1] / n)) {
                index = n - 1;
            }
            return index;

        }
};