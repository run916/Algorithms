class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        //原理是什么呢？
        int n=a.size();
        vector<vector<int>> dis(n,vector<int>(2));
        for(int i=0;i<n;i++){
            dis[i][0]=a[i]+b[i];
            dis[i][1]=i;
        }
        sort(dis.begin(),dis.end(),[](vector<int>&a,vector<int>&b){//引用型传递参数效果更好。
            return a[0]<b[0];
        });
        int va=0;
        int vb=0;
        int k=0;
        for(int i=n-1;i>=0;i--){
            if(k==0){
                k=1;
                va+=a[dis[i][1]];
            }else{
                k=0;
                vb+=b[dis[i][1]];
            }
        }
        if(va==vb)return 0;
        return va>vb?1:-1;
    }
};
