#include<bits/stdc++.h>
using namespace std;

//  https://www.luogu.com.cn/problem/P3379

const int N=5000005;
//兄弟链表法存储所有边 
int edge[2*N];
int nest[2*N];
int last[N];
int cnt=1;
inline void add(int u,int v){
	nest[cnt]=last[u];
	edge[cnt]=v;
	last[u]=cnt;
	cnt++;
	return;
}

int sq[2*N];
int d[N];
bool vise[N];
int has[N]; 
void DFS(int k){
	for(int i=last[k];i;i=nest[i]){
		if(vise[edge[i]])continue;
		vise[edge[i]]=true;
		d[edge[i]]=d[k]+1;
		DFS(edge[i]);
		sq[++cnt]=edge[i];
		has[edge[i]]=cnt;
		sq[++cnt]=k;
	}
	return;
}
int dp[2*N][20];

int lca(int l,int r){
	if(l>r)swap(l,r);
	int k=log2(r-l+1);
	if(d[dp[l][k]]<d[dp[r-(1<<k)+1][k]]){
		return dp[l][k];
	}else{
		return dp[r-(1<<k)+1][k];
	}
}
int main(){
	int n,m,s;
	cin>>n>>m>>s;
	int u,v;
	for(int i=0;i<n-1;i++){
		scanf("%d %d",&u,&v);
		add(u,v);
		add(v,u);
	}
	cnt=0;
	vise[s]=true;
	d[s]=1;
	DFS(s);
	for(int i=0;i<=cnt;i++)dp[i][0]=sq[i];
	for(int j=1;j<=20;j++){
		for(int i=0;i+(1<<j)<=cnt+1;i++){//这里一定要考虑区间的边界，要满足超出区间右侧一位 
			if(d[dp[i][j-1]]<d[dp[i+(1<<j-1)][j-1]]){
				dp[i][j]=dp[i][j-1];
			}else{
				dp[i][j]=dp[i+(1<<j-1)][j-1];
			}
		}
	}
	has[s]=cnt;
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		cout<<lca(has[u],has[v])<<endl;
	} 
	return 0;
} 