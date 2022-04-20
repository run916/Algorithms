#include<bits/stdc++.h>
using namespace std;

const int N = 400010;
int edge[N];
int nest[N];
long long val[N];
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



int h[N];
long long cap[N];
int s,t;
int n;

// push对含有超额流的顶点推送流

void push(int k){// 参数k指的是邻接链表中这条边对应的编号
    // 计算可以推送的最大流量，取超额流和边剩余容量的较小值
    long long flow = min(cap[edge[k ^ 1]], val[k]);
    // 更新
    val[k] -= flow;
    val[k ^ 1] += flow;
    cap[edge[k]] += flow;
    cap[edge[k ^ 1]] -= flow;
    return;
}

// 没有可以推动的顶点时，如果该点还存在超额流，则重贴标签
void relabel(int k,int d){
    // 寻找到最低的val大于0的可以推动流的节点，将k的标号设置为该值加一
    h[k] = d + 1;
    return;
}

// 重贴标签算法

void hlpp(){
    // 首先初始化h
    memset(h, 0, sizeof(h));
    h[s] = n;
    // 初始化cap
    memset(cap, 0, sizeof(cap));
    for (int i = last[s]; i;i=nest[i]){
        cap[s] -= val[i];
        cap[edge[i]] += val[i];
        val[i ^ 1] = val[i];
        val[i] = 0;
    }

    // 算法主要流程，也就是局部优化
    bool tag = true;
    while(tag){
        tag = false;
        for (int k = 1; k <= n; k++){
            if(k==t||k==s){
                continue;
            }
            int d;
            while(cap[k]){
                tag = true;
                d = INT_MAX;
                for (int i = last[k]; i; i = nest[i]){
                    if(h[edge[i]]+1 == h[k]&&val[i]){
                        push(i);
                    }
                    if(val[i]>0){
                        d = min(d, h[edge[i]]);
                    }
                }
                if(cap[k]){
                    relabel(k, d);
                }
            }
        }
    }
    return;
}

int main(){
    int m;
    cin >> n >> m >> s >> t;
    int u, v, w;
    for (int i = 0; i < m;i++){
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
        add(v, u, 0);
    }
    hlpp();
    cout << cap[t] << endl;
    return 0;
}