#include<bits/stdc++.h>
using namespace std;

// 总结：
// 本题涉及到的知识点主要有两个，最关键的就是维持定长单调栈了，这个单调栈有什么特性呢？
// 子序列维持了一个长度为k的字典序最大的子序列，对于此类问题我们可以用单调栈实现。
// 在维持单调栈的过程中，要保证两个边界，一个是剩余未处理元素加上当前栈中元素大于k，此时可以按照单调栈思想维持栈中元素的最大性。
// 另一个则是元素不能超过k个，所以在添加元素时，如果当前

class Solution {
public:
    // 比较两个数组的大小关系
    bool compare(vector<int>& arr1,int pre,vector<int>& arr2,int later){
        int i=pre,j=later;
        for(;i<arr1.size()&&j<arr2.size();i++,j++){
            if(arr1[i]==arr2[j])continue;
            if(arr1[i]>arr2[j])return true;
            if(arr1[i]<arr2[j])return false;
        }
        return false;
    }
    void maxSequence(vector<int>& num,int k){
        int n = num.size();
        stack<int> stack;
        // 取长度为k的最大子序列
        for (int i = 0; i < n; i++){
            for (; stack.size() + n - i > k && !stack.empty() && num[i] > stack.top(); stack.pop()){
            };
            // 添加元素时要考虑不超过k的约束
            if(stack.size() < k){
                stack.push(num[i]);
            }
        }
        num.clear();
        while(!stack.empty()){
            num.push_back(stack.top());
            stack.pop();
        }
        reverse(num.begin(), num.end());
        return;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        // 单调栈非常典型的一类题目
        // 实际上就是每个里面取一个子序列，然后合并子序列即可。
        int n = nums1.size();
        int m = nums2.size();
        vector<int> high;
        vector<int> bottom;
        vector<int> ans(k);
        vector<int> tmp;
        for (int i = 0; i <= n; i++){
            if(k - i > m || i > k){
                continue;
            }
            // 分别从两个数组中取最大的序列
            high = nums1;
            bottom = nums2;
            maxSequence(high, i);
            maxSequence(bottom, k - i); 
            // 合并两个子序列
            // 可以通过加哨兵的方式来优化判断条件和代码长度
            high.push_back(-1);
            bottom.push_back(-1);
            int cnt=0;
            tmp=ans;
            for (int l = 0, r = 0; l < i || r < k - i;){
                if(compare(high,l,bottom,r)){
                    tmp[cnt]=high[l];
                    l++;
                }else{
                    tmp[cnt]=bottom[r];
                    r++;
                }
                // 及时剪枝，如果当前的中间结果已经小于现有最优解，那么直接跳出循环。
                cnt++;
            }
            ans=max(ans,tmp);
        }
        return ans;
    }
};