#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int edge[N];
int nest[N];
int val[N];
int last[N];
int cnt=2; // 注意这里的编号应该从2开始，因为需要用到成对变换的技巧 

// 将一条边抽象为一个点，然后将同一个顶点衍生出的边拉链 
void add(int u, int v, int w){
	edge[cnt]=v;// 这条边对应的另一个端点的坐标 
	val[cnt]=w; // 这条边对应的权值 
	nest[cnt]=last[u]; // 这条边对应的编号的下一条边的编号 
	last[u]=cnt; // 端点u衍生出的最近的一条边的编号 
	cnt++;
	return;
}

queue<int> que;
int s,t;
int in[N];
int pre[N];// bfs不能回溯，所以需要一个单独的记录前驱节点的数组，用来记录增广路
bool vise[N];

// bfs寻找增广路
bool bfs(){
	while(!que.empty()){
		que.pop();
	}
	memset(vise,false,sizeof(vise));
	vise[s]=true;
	que.push(s);
	in[s]=1<<30;// 初始化可以更新的最大流，初始化为一个较大值即可
    vise[s] = true;
    // bfs寻找增光路，这里只需要寻找一条路径即可，所以这里使用vise标记数组 
	for(;!que.empty();){
		int k=que.front();
		que.pop();
		// 遍历对应点的邻边，需要注意的是，只有边权大于0，同时该点没有被遍历过时才可以更新。
		// 更新时有3件主要的事：
		//一是更新流入某个点的最大流，
		//而是将遍历的点加入到队列中，
		//三是记录增广路。

        // 实际上这里就是利用了DP的思想。
		for(int i=last[k];i;i=nest[i]){
			if(!vise[edge[i]]&&val[i]){
                vise[edge[i]] = true;
                in[edge[i]]=min(in[k],val[i]);
				que.push(edge[i]);
				pre[edge[i]]=i;
				if(edge[i]==t){
					// 找到增广路，则返回true 
					return true;
				}
			}
		}
	}
	// 否则返回false
	return false; 
}

// 更新最大流 
int update(){
	int x=t;
	while(x!=s){
        int k = pre[x];
        val[k]-=in[t];
		val[k^1]+=in[t];
		x=edge[k^1];
	}
	return in[t];
}

int main(){
	int n,m;
	cin>>n>>m>>s>>t;
	int u,v,w;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
		add(v,u,0);
	}
	// 不断尝试寻找增广路，直到不能找到增广路为止。
    long long ans = 0;
    while(bfs()){
		ans+=update();
	}
	cout<<ans;
	return 0;
	
}
