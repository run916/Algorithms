class Solution {
public:
    vector<int> sv;
    int sum[501];
    int len;
    int dp[500][500];
    //为什么记忆化dp的时间复杂度这么低？
    //观察后发现，记忆化搜索是需要了才计算，而自底向上则是不论用不用，将所有子问题的最优解都求出来，
    //比如说最终结果可能只需要[0,l]和[r,len-1]中所有满足条件的l,r即可，0和len-1时区间两个固定的点，
    //所以对于[1,l],[2,l]等等这些值根本不会用到，所以时间复杂度会降低很多，打表也可以发现，记忆化搜索的结果中
    //很多dp的记录值为0，也即没有被计算过。
    int DFS(int l,int r){
        if(l==r)return 0;
        if(dp[l][r])return dp[l][r];
        int num=sum[r+1]-sum[l];
        for(int i=l;i<=r;i++){
            if(num>=2*(sum[i+1]-sum[l]))dp[l][r]=max(dp[l][r],DFS(l,i)+sum[i+1]-sum[l]);
            if(num>=2*(sum[r+1]-sum[i]))dp[l][r]=max(dp[l][r],DFS(i,r)+sum[r+1]-sum[i]);
        }
        return dp[l][r];
    }
    int stoneGameV(vector<int>& stoneValue) {
        sv=stoneValue;
        len=sv.size();
        sum[0]=0;
        for(int i=1;i<len+1;i++)sum[i]=sum[i-1]+sv[i-1];
        memset(dp,0,sizeof(dp));
        DFS(0,len-1);
        return dp[0][len-1];
    }
};
