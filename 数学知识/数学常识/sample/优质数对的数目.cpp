#include<bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/number-of-excellent-pairs/

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        if(k>62)return 0;
        // 简单统计
        int n=nums.size();
        unordered_set<int> mset;
        for(int i=0;i<n;i++){
            mset.insert(nums[i]);
        }
        vector<int> num;
        for(auto x:mset){
            num.push_back(x);
        }
        n=num.size();
        int vise[32];
        memset(vise,0,sizeof(vise));
        int cnt=0;
        long long ans=0;
        int equal=0;
        for(int i=0;i<n;i++){
            cnt=0;
            vise[0]++;
            for(int k=num[i];k;k>>=1){
                if(k&1){
                    cnt++;
                    vise[cnt]++;
                }
            }
            if(cnt>k){
                ans+=vise[0];
            }else{
                if(k-cnt<=31){
                    ans+=vise[k-cnt];
                }
            }
            if(cnt*2>=k)equal++;
        }
        ans=ans*2-equal;
        return ans;
    }
};