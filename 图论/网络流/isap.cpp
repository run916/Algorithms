#include<bits/stdc++.h>
using namespace std;

const int N=20010;
int edge[N];
int nest[N];
int val[N];
int last[N];
int cnt=2;
void add(int u,int v,int w){
	edge[cnt]=v;
	val[cnt]=w;
	nest[cnt]=last[u];
	last[u]=cnt;
	cnt++;
	return ;
}
int s,t;
//bfs构建单元阻断路
int d[N];
int gap[N];
void bfs(){
	queue<int> que;
	que.push(t);
	d[t]=1;
	for(;!que.empty();){
		int k=que.front();
		que.pop();
		for(int i=last[k];i;i=nest[i]){
			if(!d[edge[i]]){
				d[edge[i]]=d[k]+1;
				que.push(edge[i]);
				gap[d[edge[i]]]++;
			}
		}
	}
	return ;
} 
int n,m;
long long ans=0;
int isap(int k,int flow){
	if(k==t)return flow;
	int rest=flow;
	int up;
	for(int i=last[k];i&&rest;i=nest[i]){
		if(val[i]>0&&d[edge[i]]+1==d[k]){
			up=isap(edge[i],min(rest,val[i]));
			val[i]-=up;
			val[i^1]+=up;
			rest-=up;
		}
	}
	if(rest==0)return flow-rest;
	//更新
	gap[d[k]]--;
	if(gap[d[k]]==0){
		d[s]=n+1;
		return flow-rest;
	}
	gap[++d[k]]++; 
	return flow-rest;
}

int main(){
	cin>>n>>m>>s>>t;
	int u,v,w;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
		add(v,u,0);
	}
	bfs();
	int flow;
	while(d[s]<=n){
		ans+=isap(s,1<<30);
	}
	cout<<ans<<endl;
	return 0;
} 