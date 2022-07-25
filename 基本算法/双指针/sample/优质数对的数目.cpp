#include<bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/number-of-excellent-pairs/

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        // 统计所有的1即可
        unordered_map<int,int> hash;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(hash.count(nums[i]))continue;
            for(int k=nums[i];k;k>>=1){
                if(k&1){
                    hash[nums[i]]++;
                }
            }
        }
        // 排序
        sort(nums.begin(),nums.end());
        vector<int> num;
        num.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            num.push_back(nums[i]);
        }
        // 去重后用双指针
        // 先按照hash值大小排序
        sort(num.begin(),num.end(),[&hash](int& a,int& b){
            return hash[a]<hash[b];
        });
        n=num.size();
        int l=0;
        int r=n-1;
        long long ans=0;
        for(;l<n;l++){
            // 先将可以扩充的最大范围计算出来
            while(r>=0&&hash[num[l]]+hash[num[r]]>=k)r--;
            ans+=n-r-1;
        }
        return ans;

    }
};