#include<bits/stdc++.h>
using namespace std;

const int  N=100010;
int fa[N];//并查集
int find(int x){//路径压缩
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    fa[x]=y;
    return;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i;
    int u[m],v[m],w[m];
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&u[i],&v[i],&w[i]);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
    for(int i=0;i<m;i++){
        que.emplace(w[i],i);
    }
    long long ans=0;
    int cnt=0;
    for(;!que.empty();){
        int k=que.top().second;
        que.pop();
        if(find(u[k])==find(v[k]))continue;
        else{
            merge(u[k],v[k]);
            ans+=w[k];
            cnt++;
            if(cnt==n-1)break;
        }
    }
    cout<<ans;
    return 0;
}
