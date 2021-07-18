#include<bits/stdc++.h>
using namespace std;

//邻接链表存储图结构
const int N=100010;
int edge[N];
int nest[N];
int val[N];
int last[N];
int cnt=1;//cnt是边的编号，last数组中用0来标记兄弟链表的重点，所以cnt要从1开始编号

void add(int u,int v,int w){
    edge[cnt]=v;
    nest[cnt]=last[u];
    val[cnt]=w;
    last[u]=cnt;
    cnt++;
    return;
}

//根据K的取值范围，以及图中顶点和边的数目，我们知道需要使用A*算法求解
int main(){
    int n,m;
    cin>>n>>m;
    int u[m],v[m],w[m];
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&u[i],&v[i],&w[i]);
        add(v[i],u[i],w[i]);
    }
    int s,t,k;
    cin>>s>>t>>k;
    //先求出单元最短路，求解估价函数
    priority_queue<pair<int,int>> que;
    que.emplace(-0,t);
    bool vise[n+1];
    memset(vise,false,sizeof(vise));
    int dis[n+1];
    memset(dis,0x3f,sizeof(dis));
    dis[t]=0;
    for(;!que.empty();){
        int v=que.top().second;
        que.pop();
        if(vise[v])continue;
        vise[v]=true;
        for(int i=last[v];i;i=nest[i]){
            if(!vise[edge[i]]){
                if(dis[edge[i]]>dis[v]+val[i]){
                    dis[edge[i]]=dis[v]+val[i];
                    que.emplace(-dis[edge[i]],edge[i]);
                }
            }
        }
    }
    if(dis[s]>1e9){
        cout<<-1;
        return 0;
    }
    cnt=1;
    //构图
    memset(last,0,sizeof(last));
    for(int i=0;i<m;i++)add(u[i],v[i],w[i]);
    //然后按照求出的单元最短路的大小最为估价函数。从小到达扩展到第k条路径就是解。
    while(!que.empty())que.pop();
    que.emplace(0-dis[s],s);
    int count=0;
    if(s==t)count--;
    while(!que.empty()){
        int v=que.top().second;
        int d=-que.top().first-dis[v];
        que.pop();
        if(v==t){
            count++;
            if(count==k){
            	cout<<d;
            	return 0;
			}
        }
        //这里只需要直接遍历即可
        for(int i=last[v];i;i=nest[i]){
            que.emplace(-(d+val[i]+dis[edge[i]]),edge[i]);
        }
    }
    cout<<-1<<endl;
    return 0;
}
