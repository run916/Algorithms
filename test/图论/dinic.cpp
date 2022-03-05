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

// 核心思想是构建分层图，然后在分层图上利用递归搜索的方式，来寻找所有可行流。
// 不同于EK按照边的形式来找最大流，dinic算法时按照点流量守恒来寻找最大流的
// 那么就可以在一次搜索中，找到尽可能多的流

int s, t;
int d[N];// bfs统计每个节点的深度，主要是用于剪枝
queue<int> que;

bool bfs(){
    // 初始化
    while(!que.empty()){
        que.pop();
    }
    memset(d, 0, sizeof(d));
    d[s] = 1;
    que.push(s);
    while(!que.empty()){
        int k = que.front();
        que.pop();
        // 构建分层图
        for (int i = last[k]; i; i=nest[i]){
            if(!d[edge[i]]&&val[i]){
                // 构建深度bfs深度图
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

int dinic(int k,int flow){
    if(k == t){
        return flow;
    }
    int rest = flow;
    for (int i = last[k]; i && rest;i=nest[i]){
        if(d[edge[i]] == d[k]+1&&val[i]){
            // 递归搜索，汇总
            // 满足流守恒定理
            int up = dinic(edge[i], min(rest,val[i]));
            if(up == 0){
                // 从这条边出去递归后没有搜索到可行流，那么就重置这条边出去的节点对应的高度
                d[edge[i]] = 0;
            }
            val[i] -= up;
            val[i ^ 1] += up;
            // 更新剩余流
            rest -= up;
        }
    }
    // flow和rest之间的差值，就是从节点k流经的流量
    return flow - rest;
}

int main(){
    int n, m;
    cin >> n >> m >> s >> t;
    int u, v, w;
    for (int i = 0; i < m;i++){
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
        add(v, u, 0);
    }
    long long ans = 0;
    int flow;
    while(bfs()){
        while(flow=dinic(s,1<<29)){
            ans += flow;
        }
    }
    cout << ans << endl;
    return 0;
}

