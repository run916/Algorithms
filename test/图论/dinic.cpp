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
    val[cnt] = w;
    nest[cnt] = last[u];
    last[u] = cnt;
    cnt++;
    return;
}

int s,t;
int d[N];
int in[N];
queue<int> que;

// bfs构建分层图
bool bfs(){
    while(!que.empty()){
        que.pop();
    }
    memset(d, 0, sizeof(d));
    d[s] = 1;
    que.push(s);
    while(!que.empty()){
        int k = que.front();
        que.pop();
        for (int i = last[k]; i; i=nest[i]){
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

int  dinic(int k,int flow){
    // dinic递归寻找可行流
    if(k==t){
        return flow;
    }
    int rest = flow;
    for (int i = last[k]; i && rest; i = nest[i]){
        if(val[i]&&d[edge[i]]==d[k]+1){
            int up = dinic(edge[i], min(val[i],rest));
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
    int n, m;
    cin >> n >> m >> s >> t;
    int u, v, w;
    for (int i = 0; i < m;i++){
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }
    long long ans = 0;
    long long flow = 0;
    while(bfs()){
        while(flow=dinic(s,1<<30)){
            ans += flow;
        }
    }
    cout << ans;
    return 0;
}

