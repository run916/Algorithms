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

bool bfs(){
    while(!que.empty()){
        que.pop();
    }
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    que.push(s);
    for (; !que.empty();){
        int k = que.front();
        que.pop();
        // 构建分层图
        for (int i = last[k]; i;i=nest[i]){
            if(!val[i]&&d[edge[i]]>d[k]+1){
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
    // dinic实际上是个dfs不断寻找增广路的过程
    if(k==t){
        // 找到终点时，返回流大小
        return flow;
    }
    int rest = flow;
    for (int i = last[k];i&&rest;i=nest[i]){
        if(val[i]&&d[edge[i]]=d[k]+1){
            int up = dinic(edge[i], min(val[i], rest));
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

}