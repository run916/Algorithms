class Solution {
public:
    int *arr;
    int lowbit(int x){
        return x&(-x);
    }
    void update(int x,int v,int n){
        for(int i=x;i<=n;i+=lowbit(i)){//牢记树状数组的模板。怎么没过几天就忘了
            arr[i]+=v;
        }
        return ;
    }
    int search(int x){//查询的是以[1,x]区间和。牢记树状数组查询区间
        int ans=0;
        for(int i=x;i>0;i-=lowbit(i)){
            ans+=arr[i];
        }
        return ans;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        //前缀和
        long long sum[n+1];
        sum[0]=0;
        for(int i=0;i<n;i++)sum[i+1]=sum[i]+nums[i];
        //离散化
        //这里我们用到的值处理前缀和以外还需要sum[i]-upper,以及sum[i]-lower的值，所以都需要进行离散化
        set<long long> mset;
        for(int i=0;i<=n;i++){
            mset.insert(sum[i]);
            mset.insert(sum[i]-upper);
            mset.insert(sum[i]-lower);
        }
        unordered_map<long long,int> hash;
        int id=1;//注意树状数组的存储下标从1开始，其访问方式通过函数访问，存储方式实际上是数组方式
        for(auto x:mset){
            hash[x]=id;
            id++;
        }
        int ans=0;
        int m=id-1;//由于此时我们使用的是离散化后的数组，所以元素数目为所有可能值的数目
        arr=new int[id];
        memset(arr,0,sizeof(int)*id);
        for(int i=0;i<=n;i++){
            ans+=search(hash[sum[i]-lower])-search(hash[sum[i]-upper]-1);//查询区间内的值
            update(hash[sum[i]],1,m);//更新新插入的值
        }
        return ans;

    }
};