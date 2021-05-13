#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
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
	return ;
}

int main(){
	int n;
	cin>>n;
	int d[N];
	memset(d,0,sizeof(d));
	memset(last,0,sizeof(last));
	for(int i=1;i<=n;i++){
		int v;
		while(true){
			scanf("%d",&v);
			if(v==0)break;
			add(i,v);
			d[v]++;
		}
	} 
	queue<int> que;
	for(int i=1;i<=n;i++){
		if(d[i]==0){
			que.push(i);
		}
	}
	int ans[N];
	int now=0;
	for(;!que.empty();){
		int k=que.front();
		que.pop();
		ans[++now]=k;
		for(int i=last[k];i;i=nest[i]){
			d[edge[i]]--;
			if(d[edge[i]]==0)que.push(edge[i]);
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}
