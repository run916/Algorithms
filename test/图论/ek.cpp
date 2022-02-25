#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int edge[N];
int nest[N];
int last[N];
int val[N];
int cnt = 2;// 由于使用成对变换的技巧，所以邻接链表中的边要从序号2开始编号

void add(int u,int v,int w){
    edge[cnt] = v;
    val[cnt] = w;
    nest[cnt] = last[u];
    last[u] = cnt;
    cnt++;
    return;
}

int s,t;
int in[N];
int vise[N];
int pre[N];
queue<int> que;

bool bfs(){
    while(!que.empty()){
        que.pop();
    }
    memset(vise, false, sizeof(vise));
    in[s] = 1 << 30;
    vise[s] = true;
    que.push(s);
    while(!que.empty()){
        int k = que.front();
        que.pop();
        for (int i = last[k];i;i=nest[i]){
            if(!vise[edge[i]]&&val[i]){
                vise[edge[i]] = true;
                que.push(edge[i]);
                in[edge[i]] = min(in[k], val[i]);
                pre[edge[i]] = i;
                if(edge[i]==t){
                    return true;
                }
            }
        }
    }
    return false;
}

int_least64_t update(){
    int x = t;
    while(x!=s){
        int k = pre[x];
        val[k] -= in[t];
        val[k ^ 1] += in[t];
        x = edge[k ^ 1];
    }
    return in[t];
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
    while(bfs()){
        ans += update();
    }
    cout << ans << endl;
    return 0;
}