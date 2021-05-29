#include<bits/stdc++.h>
using namespace std;

const int N=150010;
//以端点u关联的边为例： 
int edge[N]; //存储(u,v)这条边的另一个端点v 
int nest[N];//数组模拟链表，用来将所有抽象出来的边对应的节点拉到一个链表中 
int val[N];//存储(u,v)的权值 
int last[N];//保存nest对应的链表的头部节点。 
int cnt=1; //cnt不能为0，否则所有last最后都会链接到第一条边。 

//兄弟链表法存储邻接链表的思想是将边抽象为节点，然后将同一个节点的所有边抽象的节点存在一个链表中
//我们在遍历的时候，只需要按照链表顺序不断取出每一条边即可。
 

void add(int u,int v,int w){ 
	edge[cnt]=v;
	nest[cnt]=last[u];
	val[cnt]=w;
	last[u]=cnt;
	cnt++;
	return;
}
bool vise[N];
int dis[N];

int main(){
	int n;
	int m;
	cin>>n>>m;
	int u,v,w;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
	}
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pair<int,int>> que;
	dis[1]=0;
	que.emplace(0,1);
	for(;!que.empty();){
		int k=que.top().second;
		que.pop();
		if(vise[k])continue;
		vise[k]=true;
		if(k==n)break;
		for(int i=last[k];i;i=nest[i]){
			if(dis[edge[i]]>dis[k]+val[i]){
				dis[edge[i]]=dis[k]+val[i];
				que.emplace(-dis[edge[i]],edge[i]);
			}
		}
	}
	if(dis[n]>100000000)cout<<-1;
	else cout<<dis[n];
	return 0;
} 
