#include<bits/stdc++.h>
using namespace std;

const int N=200010;
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
void dfs(int k){
	vise[k]=true;
	for(int i=last[k];i;i=nest[i]){
		if(!vise[edge[i]]){
			dfs(edge[i]);
		}
	}
	return ;
}

int main(){
	while(true){
		int n,m;
		cin>>n;
		if(n==0)break;
		cin>>m;
		int u,v;
		//重构图
		memset(last,0,sizeof(last));
		cnt=1; 
		for(int i=0;i<m;i++){
			scanf("%d %d",&u,&v);
			add(u,v);
			add(v,u);
		}
		int ans=0;
		memset(vise,false,sizeof(vise));
		for(int i=1;i<=n;i++){
			if(!vise[i]){
				dfs(i);
				ans++;
			}
		}
		cout<<ans-1<<endl;	
	}

	return 0;
}
