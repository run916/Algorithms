//四种方法分别实现一次、
#include<bits/stdc++.h>
using namespace std;

int n;
//枚举法
long long dfs(int k,int m){//枚举时要注意只有当前栈中有剩余元素时才可以继续枚举
    long long ans=0;
    if(m==0){
        if(k==n)return 1;
        else ans+=dfs(k+1,1);
    }else{
        ans+=dfs(k,m-1);
        if(k<n)ans+=dfs(k+1,m+1);
    }
    return ans;
}
int main(){
    cin>>n;
    long long ans=dfs(0,0);
    cout<<ans;
    return 0;
}
