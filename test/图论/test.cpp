#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int edge[N];
int nest[N];
int val[N];
int last[N];
int cnt = 2;

void add(int u,int v, int w){
    edge[cnt] = v;
    val[cnt] = w;
    nest[cnt] = last[u];
    last[u] = cnt;
    cnt++;
    return;
}

int s,t;
int d[N];
queue<int> que;

// bfs构建分层图
bool bfs(){
    while(!que.empty()){
        que.pop();
    }
    // 构建分层图，需要先初始化
    memset(d, 0, sizeof(d));
    d[s] = 1;
    que.push(s);
    while(!que.empty()){
        int k = que.front();
        que.pop();
        for (int i = last[k]; i;i=nest[i]){
            if(!d[edge[i]]&&val[i]){
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

// 递归搜索所有可能的流，按照节点处流量守恒的原理
int dinic(int k,int flow){
    if(k==t){
        return flow;
    }
    int rest = flow;
    for (int i = last[k]; i && rest;i=nest[i]){
        if(d[edge[i]]==d[k]+1&&val[i]){
            int up = dinic(edge[i], min(val[i], rest));
            if(up==0){
                // 如果从边i出去没有搜索到可行流，那么及时剪枝
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
    int flow = 0;
    while(bfs()){
        while(flow=dinic(s,1<<30)){
            ans += flow;
        }
    }
    cout << ans << endl;
    return 0;
}
