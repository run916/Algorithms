#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int edge[N];
int nest[N];
int val[N];
int last[N];
int cnt = 2;

void add(int u,int v,int w){
    edge[cnt] = v;
    nest[cnt] = last[u];
    val[cnt] = w;
    last[u] = cnt;
    cnt++;
    return;
}

int s, t;
queue<int> que;
int d[N];
int vise[N];

// 流守恒体现在两个方面，一个方面是边上的流守恒，另一个方面是点上的流守恒
// 在具体实现算法时，我们只需要关注点流守恒就可以了。
// 所以这里构建分层图的目的就是为了统计经过一个点的最大流量是多少。
bool bfs(){
    while(!que.empty()){
        que.pop();
    }
    memset(d, 0, sizeof(d));
    d[s] = 1;
    que.push(s);
    for (; !que.empty();){
        int k = que.front();
        que.pop();
        // 构建分层图
        for (int i = last[k]; i;i=nest[i]){
            if(val[i]&&!d[edge[i]]){
                d[edge[i]] = d[k] + 1;
                que.push(edge[i]);
                if(edge[i]==t){
                    return true;
                }
            }
        }
    }
    return false;
}

// 这里按照点的流守恒的约束来尽可能寻找增光路，当某一条边上的可行流量为0以后，就从分层图中，将该点剔除。
int dinic(int k,int flow){
    // dinic实际上是个dfs不断寻找增广路的过程
    if(k==t){
        // 找到终点时，返回流大小
        return flow;
    }
    int rest = flow;
    for (int i = last[k];i&&rest;i=nest[i]){
        if(val[i]&&d[edge[i]]==d[k]+1){
            int up = dinic(edge[i], min(val[i], rest));
            if(!up){
                // 当从该分支不能搜索到增光路时，就将这条边剪枝，这个剪枝通过分层图来标识。
                d[edge[i]] = 0;
            }
            val[i] -= up;
            val[i ^ 1] += up;
            rest -= up;
        }
    }
    return flow - rest;
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
	long long ans=0;
	int flow=INT_MAX;
	while(bfs()){
		while(flow=dinic(s,1<<29))ans+=flow;
	}
	cout<<ans;
	return 0;
}