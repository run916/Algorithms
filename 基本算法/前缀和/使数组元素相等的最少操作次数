class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        //排序
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int sub[n];
        sub[0]=0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])sub[i]=0;
            else sub[i]=1;
        }
        int sum[n+1];
        sum[0]=0;
        for(int i=0;i<n;i++)sum[i+1]=sum[i]+sub[i];
        int ans=0;
        for(int i=0;i<=n;i++)ans+=sum[i];
        return ans;

    }
};
