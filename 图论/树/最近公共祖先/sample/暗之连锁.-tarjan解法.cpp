//树上差分的模板题目
#include<bits/stdc++.h>
using namespace std;
//这里以tarjan算法辅助求解

const int N=100010;
//并查集
int arr[N];
int find(int x){
    return x==arr[x]?x:arr[x]=find(arr[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    arr[x]=y;
    return ;
}
//领接链表
int edge[N*2];
int nest[N*2];
int last[N];
int cnt=1;
void add(int u,int v){
    edge[cnt]=v;
    nest[cnt]=last[u];
    last[u]=cnt;
    cnt++;
    return;
}
//查询
vector<int> q[N*2];
int vise[N];
int val[N];
void DFS(int k){
    vise[k]=1;
    for(int i=last[k];i;i=nest[i]){
        if(vise[edge[i]])continue;
        DFS(edge[i]);
        //搜索完后合并
        merge(edge[i],k);
    }
    //实际求解LCA的地点
    for(int i=0;i<q[k].size();i++){
        if(vise[q[k][i]]==2){
            val[find(q[k][i])]-=2;
        }
    }
    vise[k]=2;
    return;
}
int n,m;
int ans=0;
int dfs(int k){
	int sum=val[k];
    for(int i=last[k];i;i=nest[i]){
    	if(vise[edge[i]])continue;
    	vise[edge[i]]=1;
    	int num=dfs(edge[i]);
    	if(num==0)ans+=m;
    	if(num==1)ans++;
    	sum+=num;
	}
	return sum;
}
int main(){
    cin>>n>>m;
    //初始化并查集
    for(int i=0;i<=n;i++)arr[i]=i;
    int u,v;
    for(int i=0;i<n-1;i++){
        scanf("%d %d",&u,&v);
        add(u,v);
        add(v,u);
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        if(u==v)continue;
        q[u].push_back(v);
        q[v].push_back(u);
        val[u]++;
        val[v]++;
    }
    DFS(1);
    memset(vise,0,sizeof(vise));
    vise[1]=1;
    dfs(1);
    cout<<ans;
    return 0;
}