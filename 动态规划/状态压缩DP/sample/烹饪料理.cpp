#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowbit(int x){
        return x&(-x);
    }
    
    int perfectMenu(vector<int>& mat, vector<vector<int>>& cook, vector<vector<int>>& att, int l) {
        // 状态压缩+枚举？
        int n=cook.size();
        int m=mat.size();
        int dp[1<<n][m];
        memset(dp,0,sizeof(dp));
        // 初始化dp数组
        int ans=-1;

        // 建立二进制位数，与下标的映射关系
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++){
            hash[1<<i]=i;
        }
        // 状态压缩动态规划
        for(int i=1;i<(1<<n);i++){
            bool tag=true;
            int d=lowbit(i);
            for(int j=0;j<m;j++){
                dp[i][j]=cook[hash[d]][j]+dp[i-d][j];
                if(dp[i][j]>mat[j]){
                    tag=false;
                }
            }
            if(tag){
                // 当材料限制时，考虑饱腹度是否满足限制
                int a=0,b=0;
                for(int k=i;k;k-=lowbit(k)){
                    a+=att[hash[lowbit(k)]][0];
                    b+=att[hash[lowbit(k)]][1];
                }
                if(b>=l){
                    ans=max(ans,a);
                }
            }
        }
        return ans;

    }
};