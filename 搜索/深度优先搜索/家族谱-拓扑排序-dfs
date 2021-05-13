#include<bits/stdc++.h>
using namespace std;

const int N=510;
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
	int n,m;
	while(cin>>n>>m){
		memset(last,0,sizeof(last));
		cnt=1;
		int u,v;
		int d[n+1];
		memset(d,0,sizeof(d));
		for(int i=0;i<m;i++){
			scanf("%d %d",&u,&v);
			add(u,v);
			d[v]++;
		}
		priority_queue<int> que;
		for(int i=1;i<=n;i++){
			if(d[i]==0){
				que.push(-i);
			}
		}
		int topology[n];
		int now=-1;
		for(;!que.empty();){
			int k=-que.top();
			que.pop();
			topology[++now]=k;
			for(int i=last[k];i;i=nest[i]){
				d[edge[i]]--;
				if(d[edge[i]]==0)que.push(-edge[i]); 
			}
		}
		for(int i=0;i<n;i++){
			printf("%d",topology[i]);
			if(i<n-1)printf(" ");
		}
		printf("\n");
	}
	return 0;
}
