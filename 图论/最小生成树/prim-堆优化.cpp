#include<bits/stdc++.h>
using namespace std;

//prim算法
const int N=400010;
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
    int n,m;
    cin>>n>>m;
    int u,v,w;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
    que.emplace(0,1);
    bool vise[n+1];
    memset(vise,false,sizeof(vise));
    int d[n+1];
    memset(d,0x3f,sizeof(d));
    d[1]=0;
    long long ans=0;
    for(;!que.empty();){
        int k=que.top().second;
        que.pop();//一定要提前出栈
        if(vise[k])continue;//如果已经加入到了生成树中，则跳过
        ans+=d[k];
        vise[k]=true;
        for(int i=last[k];i;i=nest[i]){
            if(!vise[edge[i]]&&d[edge[i]]>val[i]){//注意这里的优化判断有两重
                d[edge[i]]=val[i];
                que.emplace(d[edge[i]],edge[i]);
            }
        }
    }
    cout<<ans;
    return 0;

}
