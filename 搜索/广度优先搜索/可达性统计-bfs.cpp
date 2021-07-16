#include<bits/stdc++.h>
using namespace std;

const int N=30010;
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
	cin>>n>>m;
	int u,v;
	int d[n+1];
	memset(d,0,sizeof(d));
	set<pair<int,int>> set;
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		if(set.count(make_pair(u,v)))continue;
		add(u,v);
		d[v]++;
	}
	queue<int> que;
	for(int i=1;i<=n;i++){
		if(d[i]==0){
			que.push(i);
		}
	}
	int topology[n];
	int now=n;
	for(;!que.empty();){
		int k=que.front();
		que.pop();
		topology[--now]=k;
		for(int i=last[k];i;i=nest[i]){
			d[edge[i]]--;
			if(d[edge[i]]==0)que.push(edge[i]); 
		}
	}
	//dp求解答案。 
	bitset<N> dp[n+1];
	for(int i=0;i<n;i++){
		int k=topology[i];
		dp[k][k]=1;
		for(int j=last[k];j;j=nest[j]){
			dp[k]|=dp[edge[j]];
		}
	}
	//输出答案
	for(int i=1;i<=n;i++){
		cout<<dp[i].count()<<endl;
	}
	return 0;
} 
