class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        //还是一个零和博弈
        //A获得了一部分价值，一部分被抛弃，双方都选择自身最优的操作
        int n=stoneValue.size();
        if(n==1)return 0;
        int sum[n+1];
        sum[0]=0;
        for(int i=0;i<n;i++)sum[i+1]=sum[i]+stoneValue[i];
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j+i>=n)break;
                for(int k=0;k<i&&j+k+1<n;k++){
                    //分成了[j,j+k]和[j+k+1,j+i]两段，我们需要删掉和较大的那一段。
                    if(sum[i+j+1]-sum[j+k+1]>sum[j+k+1]-sum[j]){
                        dp[j][j+i]=max(dp[j][j+i],dp[j][j+k]+sum[j+k+1]-sum[j]);
                    }else if(sum[i+j+1]-sum[j+k+1]<sum[j+k+1]-sum[j]){
                        dp[j][j+i]=max(dp[j][j+i],dp[j+k+1][j+i]+sum[j+i+1]-sum[j+k+1]);
                    }else{
                        dp[j][j+i]=max(dp[j][j+i],
                        max(dp[j+k+1][j+i]+sum[j+i+1]-sum[j+k+1],dp[j][j+k]+sum[j+k+1]-sum[j]));
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
