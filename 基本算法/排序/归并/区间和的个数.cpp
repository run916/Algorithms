class Solution {
public:
    long long *sum;
    int ans=0;
    int upper;
    int lower;
    void merge(int l,int r){
        if(l==r)return;
        int m=(l+r)/2;
        merge(l,m);
        merge(m+1,r);
        int pre=m+1;
        int later=m+1;
        for(int i=l;i<=m;i++){
            for(;later<=r&&sum[later]-sum[i]<=upper;later++);
            for(;pre<=r&&sum[pre]-sum[i]<lower;pre++);
            ans+=(later-pre);
        }
        comb(l,r);
        return;

    }
    void comb(int l,int r){
        int m=(l+r)/2;
        int i=l,j=m+1;
        long long tmp[r-l+1];
        int id=0;
        for(;i<=m&&j<=r;){
            if(sum[i]<sum[j]){
                tmp[id++]=sum[i];
                i++;
            }else{
                tmp[id++]=sum[j];
                j++;
            }
        }
        for(;i<=m;i++)tmp[id++]=sum[i];
        for(;j<=r;j++)tmp[id++]=sum[j];
        id=0;
        for(i=l;i<=r;i++)sum[i]=tmp[id++];
        return ;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->upper=upper;
        this->lower=lower;
        int n=nums.size();
        sum=new long long[n+1];
        sum[0]=0;
        for(int i=0;i<n;i++)sum[i+1]=sum[i]+nums[i];
        merge(0,n);
        return ans;

    }
};