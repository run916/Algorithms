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
bool d[N];//记录深度 
void dfs(int k){
	vise[k]=true;
	for(int i=last[k];i;i=nest[i]){
		if(!vise[edge[i]]){
			d[edge[i]]=d[k]+1;
			dfs(edge[i]);
		}
	}
	return ; 
}
