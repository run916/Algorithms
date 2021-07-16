#include<bits/stdc++.h>
using namespace std;

const int N=200010;
int edge[N];
int nest[N];
int val[N];
int last[N];
int cnt=1;
void add(int u,int v,int w){
    edge[cnt]=v;
    val[cnt]=w;
    nest[cnt]=last[u];
    last[u]=cnt;
    cnt++;
    return;
}
int main(){
    int n,m,s;
    cin>>n>>m>>s;
    int u,v,w;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
    }
    //有两个关键的技巧
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
    que.emplace(0,s);
    long long dis[n+1];
    memset(dis,0x3f,sizeof(dis));
    bool vise[n+1];
    memset(vise,false,sizeof(vise));
    dis[s]=0;
    for(;!que.empty();){
        int k=que.top().second;
        que.pop();
        if(vise[k])continue;//惰性删除，优化1
        vise[k]=true;
        for(int i=last[k];i;i=nest[i]){
            if(dis[edge[i]]>dis[k]+val[i]){//优化2
                dis[edge[i]]=dis[k]+val[i];
                que.emplace(dis[edge[i]],edge[i]);
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dis[i]<<" ";cout<<endl;
    return 0;
}
