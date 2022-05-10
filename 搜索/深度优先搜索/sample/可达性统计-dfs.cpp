#include<bits/stdc++.h>
using namespace std;

const int N=30010 ;
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
bool first[N];
int finish[N];
int id=0;
int ind=0;
void dfs(int k){
	first[k]=++id;
	for(int i=last[k];i;i=nest[i]){
		if(!first[edge[i]]){
			dfs(edge[i]);
		}
	}
	finish[k]=++ind;
	return ; 
}

int main(){
	int n,m;
	cin>>n>>m;
	int u,v;
	//有重边，注意去掉重边
	set<pair<int,int>> set; 
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		if(set.count(make_pair(u,v)))continue;
		add(u,v);
	}
	for(int i=1;i<=n;i++){
		if(!first[i]){
			dfs(i);
		}
	}
	//finish逆序就是拓扑序列，也即finish序列是拓扑逆序 
	int ans[n+1];
	//finish序列就是拓扑逆序，我们递推时采用拓扑逆序。
	for(int i=1;i<=n;i++)ans[finish[i]]=i; 
	//输出答案 
	bitset<N> dp[n+1];
	for(int i=1;i<=n;i++){
		int k=ans[i];
		dp[k][k]=1;
		for(int j=last[k];j;j=nest[j]){
			dp[k]|=dp[edge[j]];
		}
	}
	for(int i=1;i<=n;i++){
		cout<<dp[i].count()<<endl;
	}
	return 0; 
	 
}
