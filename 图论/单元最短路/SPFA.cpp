#include<bits/stdc++.h>
using namespace std;

// 邻接链表
const int N = 1000010;
int edge[N];
int nest[N];// 命名冲突
int val[N];
int last[N];
int cnt = 1;

void add(int u,int v,int w){
    edge[cnt] = v;
    nest[cnt] = last[u];
    val[cnt] = w;
    last[u] = cnt;
    cnt++;
    return;
}

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    int u, v, w;
    for (int i = 0; i < m; i++){
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
    }
    queue<int> que;
    que.push(s);
    long long dis[n + 1];
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    // 建立vise数组，用来标记当前在队列中的元素
    bool vise[n + 1];
    memset(vise, false, sizeof(vise));
    for (; !que.empty();){
        int k = que.front();
        que.pop();
        vise[k] = false;
        for (int i = last[k]; i; i = nest[i]){
            if (dis[edge[i]] > dis[k] + val[i]){
                dis[edge[i]] = dis[k] + val[i];
                // 对于不在队列中的元素，则加入队列
                if(!vise[edge[i]]){
                    vise[edge[i]] = true;
                    que.push(edge[i]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if(dis[i]>10000000){
            cout << INT_MAX << " ";
        }else{
            cout << dis[i] << " ";
        }
    }
    return 0;
}