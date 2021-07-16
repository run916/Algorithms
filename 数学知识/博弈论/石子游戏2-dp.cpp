class Solution {
public:
    //暴力转记忆化搜索。
    //中间态表示：A从第i个位置拿物品，当前M为j时剩余问题的最优解。
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        int sum[n+1];
        sum[0]=0;
        for(int i=0;i<n;i++)sum[i+1]=sum[i]+piles[i];
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=n;j++){
                for(int x=1;x<=2*j;x++){
                    if(i+x>n)break;
                    dp[i][j]=max(dp[i][j],sum[n]-sum[i]-dp[i+x][max(x,j)]);
                }
            }
        }
        return dp[0][1];
    }
};
