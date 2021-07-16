class Solution {
public:
    int mod=1e9+7;
    int sumOfFlooredPairs(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        int n=nums.size();
        long long dp[n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            if(i>0){
                if(nums[i]==nums[i-1]){
                    dp[i]=dp[i-1];
                    ans+=dp[i];
                    continue;     
                }
            }
            int l=i,r;
            int now;
            for(;l<n;){
                //二分查找
                now=l;
                r=n-1;
                int k=nums[now]/nums[i];
                while(l<=r){
                    int m=(l+r)/2;
                    if(nums[m]/nums[i]>k){
                        r=m-1;
                    }else{
                        l=m+1;
                    }
                }
                dp[i]+=(long long)(l-now)*(k);
                dp[i]%=mod;
            }
            ans+=dp[i];
        }
        return ans%mod;
    }
};
