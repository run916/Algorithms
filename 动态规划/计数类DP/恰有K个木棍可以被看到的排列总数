class Solution {
public:
    int mod=1e9+7;
    int rearrangeSticks(int n, int k) {
        //计数类DP
        long long dp[n+1][k+1];
        memset(dp,0,sizeof(dp));
        //两种情况最后一个位置可以被看到，那么一定是最高的，此时有dp[i][j]+=dp[i-1][j-1];
        //最后一个位置看不到时，此时最后一个位置是一个数的取值范围是[0,i-1];
        //假设这个数为x，那么剩余i-1个数中，可以看到j个木棍的总数为dp[i-1][j];
        //我们只需要将单独拿出来的木棍放在着i-1木棍的后面，即可得到一个满足条件的排列
        //综上我们有dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*(i-1);
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*(i-1);
                dp[i][j]%=mod;
            }
        }
        return dp[n][k];

    }
};
