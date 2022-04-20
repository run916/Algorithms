#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
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

// bfs构建分层图
int s, t;
queue<int> que;
int d[N];

bool bfs(){
    // 初始化
    while(!que.empty()){
        que.pop();
    }
    memset(d, 0, sizeof(d));
    que.push(s);
    d[s] = 1;
    for (; !que.empty();que.pop()){
        int k = que.front();
        for (int i = last[k]; i;i=nest[i]){
            if(val[i]&&!d[edge[i]]){
                que.push(edge[i]);
                d[edge[i]] = d[k] + 1;
                if(edge[i]==t){
                    return true;
                }
            }
        }
    }
    return false;
}

// dinic更新最大流

int dinic(int k,int flow){
    if(k==t){
        return flow;
    }
    int rest = flow;
    for (int i = last[k]; i && rest;i=nest[i]){
        if(d[edge[i]]==d[k]+1&&val[i]){
            int up = dinic(edge[i], min(rest, val[i]));
            if(!up){
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
    long long ans = 0;
    while(bfs()){
        ans += dinic(s, 1 << 30);
    }
    cout << ans;
    return 0;
}