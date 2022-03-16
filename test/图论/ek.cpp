#include<bits/stdc++.h>
using namespace std;

const int N=100010;
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

int s,t;
int in[N];
int pre[N];
bool vise[N];
queue<int> que;

// bfs寻找增广路
bool bfs(){
    // 初始化
    while(!que.empty()){
        que.pop();
    }
    memset(vise, false, sizeof(vise));
    in[s] = 1 << 30;
    que.push(s);
    vise[s] = true;

    while(!que.empty()){
        int k = que.front();
        que.pop();
        for (int i = last[k]; i;i=nest[i]){
            if(!vise[edge[i]]&&val[i]){
                vise[edge[i]] = true;
                pre[edge[i]] = i;
                in[edge[i]] = min(val[i], in[k]);
                que.push(edge[i]);
                if(edge[i]==t){
                    return true;
                }
            }
        }
    }
    return false;
}

long long update(){
    int x = t;
    while(x!=s){
        int i = pre[x];
        val[i] -= in[t];
        val[i ^ 1] += in[t];
        x = edge[i ^ 1];
    }
    return in[t];
}

int main(){
    int n, m;
    cin >> n >> m >> s >> t;
    int u, v, w;
    // 构建邻接链表
    for (int i = 0;i<m;i++){
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }
    long long ans = 0;
    while(bfs()){
        ans += update();
    }
    cout << ans;
    return 0;
}