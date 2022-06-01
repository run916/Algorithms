#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int totalSteps(vector < int > & nums) {
            // 倒序单调栈求解
            // 思路很简单，从后往前计算每一个位置向右看，可以在几个回合内删除所有可以删除的元素，我们将该值用vise存储
            // 每个位置的初始值为0.
            // 我们用单调栈维持当前未被删除的元素，显然，这些元素是单调递增的。
            // 当我们遍历到某一个元素时，我们从小到大判断单调栈中的元素是否需要删除
            // 显然，有两种情况
            // ①如果vise[stack.top()]<=vise[i]+1，显然，stack.top()的元素删除时，至少要vise[i]+1轮，此时vise[i]=vise[i]+1;
            // ②如果vise[stack.top()]>vise[i]+1，显然，stack.top()的元素有一部分是被num[i]删除的，此时vise[i]=vise[stack.top()];
            stack < int > s;
            int n = nums.size();
            int vise[n];
            memset(vise, 0, sizeof(vise));
            s.push(n - 1);
            int ans = 0;
            for (int i = n - 2; i >= 0; i--) {
                while (!s.empty() && nums[s.top()] < nums[i]) {
                    vise[i] = max(vise[s.top()], vise[i] + 1);
                    s.pop();
                }
                s.push(i);
                ans = max(vise[i], ans);
            }
            return ans;
        }
};