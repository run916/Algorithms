class Solution {
public:
    int lowbit(int x){
        return x&(-x);
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        //阶乘枚举+记忆化
        int n=nums1.size();
        //状态压缩动态规划
        int m=1<<n;
        int dp[n+1][m];
        memset(dp,0x3f,sizeof(dp));
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<m;j++){
                for(int k=0;k<n;k++){
                    if(j&(1<<k)){
                        int state=(j^(1<<k));
                        dp[i][j]=min(dp[i-1][state]+(nums2[k]^nums1[i-1]),dp[i][j]);
                    }
                }
            }
        }
        return dp[n][m-1];

    }
};
