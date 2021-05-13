class Solution {
public:
    long long  transfer(string s){
        int n=s.length();
        long long ans=0;
        for(int i=0;i<n;i++){
            ans=ans*10+s[i]-'0';
            if(ans>=1e17)break;
        }
        return ans;
    }
    //预处理出所有字串对应的数字
    long long num[20][20];
    string s;
    int n;
    void init(){
        memset(num,0x3f,sizeof(num));
        n=s.length();
        for(int i=0;i<n;i++){
            string str="";
            for(int j=i;j<n;j++){
                str+=s[j];
                num[i][j]=transfer(str);
            }
        }
        return;
    }
    //深度优先搜索
    bool dfs(int k,long long pre){
        if(k==n)return true;
        bool tag=false;
        for(int i=k;i<n;i++){
            if(num[k][i]+1==pre){
                tag|=dfs(i+1,num[k][i]);
            }
            if(tag)break;
        }
        return tag;
    }
    bool splitString(string s) {
        //搜索问题，要注意剪枝的技巧
        this->s=s;
        init();
        //注意一点是至少要分成两段
        for(int i=0;i<n-1;i++){
            if(dfs(i+1,num[0][i]))return true;
        }
        return false;

    }
};
