#include<bits/stdc++.h>
using namespace std;

const int N = 400010;
int edge[N];
int nest[N];
int last[N];
long long val[N];
int cnt = 2;

// 构建领接链表
void add(int u,int v,int w){
    edge[cnt] = v;
    val[cnt] = w;
    nest[cnt] = last[u];
    last[u] = cnt;
    cnt++;
    return;
}

int h[N];// 高度函数
long long cap[N];// 容量函数
int s, t;// 源点汇点
int n;

// 推送(u,v)这条边上的流量，在这个邻接链表中，(u,v)对应的边为k
void push(int k){
    // 计算可以更新的最大流值
    long long flow = min(cap[edge[k ^ 1]], val[k]);
    // 更新边的容量
    val[k] -= flow;
    val[k ^ 1] += flow;
    // 更新节点的的超额流
    cap[edge[k]] += flow;
    cap[edge[k ^ 1]] -= flow;
    return;
}

void relabel(int k){
    //  重贴标签
    int d = INT_MAX;
    for (int i = last[k]; i;i=nest[i]){
        // 只能向容量为正值的管道push流量，
        // 所以这里再重贴标签时，只对这些边指向的顶点进行考虑
        if(val[i]){
            d = min(d, h[edge[i]]);
        }
    }
    h[k] = d + 1;
    return;
}

// 重贴标签算法

void hlpp(){
    // 首先需要初始化
    memset(h, 0, sizeof(h));
    memset(cap, 0, sizeof(cap));
    h[s] = n;
    // 初始化数据
    for (int i = last[s]; i;i=nest[i]){
        cap[edge[i]] += val[i];
        cap[s] -= val[i];
        val[i ^ 1] = val[i];
        val[i] = 0;
    }

    // 主要算法框架，这里不考虑节点遍历顺序，实现一个通用的框架
    bool tag = true;
    while(tag){
        tag = false;
        for (int k = 1; k <= n; k++){
            if(k==t || k==s){
                continue;
            }
            // 判断需要push还是relabel
            // 需要注意的是，只有有超额流的节点才会push和relabel
            while(cap[k]){
                tag = true;
                for (int i = last[k]; i; i=nest[i]){
                    // 首先尝试是否可以push
                    if (h[k] == h[edge[i]] + 1 && val[i]) {
                        push(i);
                    }
                }
                // 如果所有可能push的点push后还有超额流，则执行重贴标签的工作。
                if(cap[k]){
                    relabel(k);
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
