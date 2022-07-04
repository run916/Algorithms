#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int edge[N];
int nest[N];
int last[N];
int cnt=1;

void add(int u,int v){
	edge[cnt]=v;
	nest[cnt]=last[u];
	last[u]=cnt;
	cnt++;
	return;
}
bool vise[N];//标记数组 
int son[N];//以该节点为根节点的子树中节点的数目
int n;//节点总数 
int p; 
int ans=INT_MAX;//记录最大子树权值最小的值 
void dfs(int k){
	vise[k]=true;
	son[k]+=1;
	int num=0;
	for(int i=last[k];i;i=nest[i]){
		if(!vise[edge[i]]){
			dfs(edge[i]);
			son[k]+=son[edge[i]];
			num=max(son[edge[i]],num);
		}
	}
	num=max(num,n-son[k]);
	ans=min(ans,num);
	if(ans==num)p=k; 
	return ; 
}
