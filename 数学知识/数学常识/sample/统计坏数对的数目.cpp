#include<bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/count-number-of-bad-pairs/

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // 遇到多个变量的问题，一定要先将同一个未知量移动到同一边再处理
        unordered_map<int,int> hash;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            hash[nums[i]-i]++;
        }
        long long ans=0;
        for(auto x:hash){
            ans+=(n-x.second)*x.second;
        }
        return ans/2;
        
    }
};