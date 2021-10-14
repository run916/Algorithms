#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowbit(int x){
        return x&(-x);
    }
    int minimumDifference(vector<int>& nums) {
        // 折半搜索+状态压缩动态规划
        int n=nums.size();
        int m=n/2;
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++){
            hash[1<<i]=i;
        }
        int num[1<<m];
        memset(num,0,sizeof(num));
        for(int i=1;i<(1<<m);i++){
            num[i]=num[i-lowbit(i)]+1;
        }
        // 统计前一半数据所有的可能
        int dp[1<<m];
        memset(dp,0,sizeof(dp));
        // 统计后一半数据所有的可能
        int tp[1<<m];
        memset(tp,0,sizeof(tp));
        for(int i=1;i<(1<<m);i++){
            dp[i]=dp[i-lowbit(i)]+nums[hash[lowbit(i)]];
            tp[i]=tp[i-lowbit(i)]+nums[hash[lowbit(i)]+m];
        }
        // 记录某种组合下的最大值，排序后双指针
        vector<vector<int>> high(m+1);// 记录左侧
        vector<vector<int>> bottom(m+1);// 记录右侧
        for(int i=0;i<(1<<m);i++){
            high[num[i]].push_back(dp[i]);
            bottom[num[i]].push_back(tp[i]);
        }
        for(int i=0;i<=m;i++){
            sort(high[i].begin(),high[i].end());
            sort(bottom[i].begin(),bottom[i].end());
        }
        // 双指针计算最优值
        int ans=INT_MAX;
        for(int i=0;i<=m;i++){
            int l=0;
            int r=bottom[m-i].size()-1;
            for(;l<high[i].size()&&r>=0;){
                ans=min(ans,abs(sum-2*(high[i][l]+bottom[m-i][r])));
                if((high[i][l]+bottom[m-i][r])*2>sum){
                    r--;
                }else if((high[i][l]+bottom[m-i][r])*2<sum){
                    l++;
                }else{
                    return 0;
                }
            }
        }
        return ans;
    }
};