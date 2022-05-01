#include<bits/stdc++.h>
using namespace std;

// https://www.acwing.com/problem/content/1646/

#define n 10001
int edge[2*n][2];
int last[n];
int id=0;
unordered_map<int,int> has;
inline void add(int u,int v){//添加边，一定要记住  
	edge[id][0]=last[u];
	edge[id][1]=v;
	last[u]=id;
	id++;
	edge[id][0]=last[v];
	edge[id][1]=u;
	last[v]=id;
	id++;
	return;
}
//由前序和中序遍历得到二叉树 
int ins[n];
int mid[n];
//注意变量的使用 
void dfs(int l,int r,int pre,int later,int k){
	if(k>0)add(k,ins[l]);
	if(l==r){
		return ; 
	}
	//获得中序遍历的中间点的下标 
	int index=has[ins[l]];
	int dis=index-pre;
	//千万注意根节点是哪个 
	if(dis>=1)dfs(l+1,l+dis,pre,index-1,ins[l]);
	if(l+dis+1<=r)dfs(l+dis+1,r,index+1,later,ins[l]);
	return; 
}
int dep[n];
int dp[n][20];
void DFS(int k){
	//预处理出每个节点的dp数组值
	//预处理要先于遍历 
	for(int i=1;(1<<i)<dep[k];i++){
		dp[k][i]=dp[dp[k][i-1]][i-1];
	}
	for(int i=last[k];i!=-1;i=edge[i][0]){
		if(dep[edge[i][1]]==0){
			dep[edge[i][1]]=dep[k]+1;
			dp[edge[i][1]][0]=k;
			DFS(edge[i][1]);
		}
	}
	return ;
}
int lowbit(int x){
	return x&(-x);
}
int lca(int u,int v){
	if(dep[u]<dep[v]){
		swap(u,v);
	}
//	while(dep[u]>dep[v]){//注意该写法，很妙 ,另一种方法是位操作，但不如该方法这么高效 
//	    u=dp[u][(int)log2(dep[u]-dep[v])]; 
//	}
	int dis=dep[u]-dep[v];
	for(int i=dis;i;i-=lowbit(i)){//实际上就是将二进制数中为1的跳即可。 
		u=dp[u][(int)log2(lowbit(i))];
	} 
	if(u==v)return u;
	//最大高度不会超过dep[u]的，所以以此为查询边界 
	for(int i=log2(dep[u]);i>=0;i--){
		if(dp[u][i]==dp[v][i])continue;
		u=dp[u][i];
		v=dp[v][i];
	} 
	return dp[u][0];
	
}
unordered_map<int,int> tran;
unordered_map<int,int> retran;
int main(){
	int N,m;
	cin>>m>>N;
	for(int i=0;i<N;i++)cin>>mid[i];
	for(int i=0;i<N;i++)cin>>ins[i];
	for(int i=0;i<N;i++){
		tran[ins[i]]=i+1;
		retran[i+1]=ins[i];
	}
	for(int i=0;i<N;i++)ins[i]=tran[ins[i]];
	for(int i=0;i<N;i++)mid[i]=tran[mid[i]];
	for(int i=0;i<N;i++)has[mid[i]]=i;
	memset(last,-1,sizeof(last));
	dfs(0,N-1,0,N-1,0);
	memset(dep,0,sizeof(dep));
	memset(dp,0,sizeof(dp)); 
	dep[ins[0]]=1;
	DFS(ins[0]);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		bool tag=false;
		if(tran[u]==0){
			cout<<"ERROR: "<<u;
			tag=true;
		}
		if(tran[v]==0){
			if(tag){
				cout<<" and "<<v<<" are not found."<<endl;
				continue;
			}else{
				cout<<"ERROR: "<<v<<" is not found."<<endl;
				continue;
			}
			
		} 
		if(tag){
			cout<<" is not found."<<endl;
			continue;	
		}
		int f=lca(tran[u],tran[v]);
		if(f==tran[u]){
			cout<<u<<" is an ancestor of "<<v<<"."<<endl;
			continue;	
		}
		if(f==tran[v]){
			cout<<v<<" is an ancestor of "<<u<<"."<<endl;
			continue;
		}
		cout<<"LCA of "<<u<<" and "<<v<<" is "<<retran[f]<<"."<<endl;
	}
	return 0;
}