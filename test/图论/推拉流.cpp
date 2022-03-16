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

int n, m, s, t;
int h[N];// 高度函数
long long cap[N];// 容量函数
// 实现两个局部优化的操作即可
// 推送流
void push(int k){
    // 只能将高度高的推向高度低的节点
    if(h[edge[k^1]] == h[edge[k]]+1){
        // 可以push的值是节点超额流与边k容量限制下的最大值
        long long up = min(cap[edge[k ^ 1]], (long long)val[k]);
        // 更新节点超额流
        cap[edge[k]] += up;
        cap[edge[k^1]]-=up;
        // 更新边容量
        val[k] -= up;
        val[k ^ 1] += up;
    }
    return;
}

// 重贴标签
void relabel(int k){
    // 只要节点有超额流，并且不能push，则一定能调整高度
    int high = INT_MAX;
    for (int i = last[k]; i;i=nest[i]){
        if(val[i]){
            high = min(high, h[edge[i]]);
        }
    }
    // 将当前节点的高度设置为可以push节点的最小值
    h[k] = high + 1;
    return;
}

// 推拉流算法
void hlpp(){
    // 首先初始化
    h[s] = n;
    for (int i = last[s]; i;i=nest[i]){
        int up = val[i];
        cap[edge[i]] += up;
        cap[edge[i ^ 1]] -= up;
        val[i] -= up;
        val[i ^ 1] += up;
    }

    // 主要的算法框架，通过局部优化，来优化到最优解
    bool tag = true;
    while(tag){
        tag = false;
        for (int k = 1; k <= n; k ++){
            if(k==s||k==t){
                continue;
            }
            while (cap[k]){
                // 除了源点和汇点，只要有节点有超额流，则还可以继续局部优化
                tag = true;
                for (int i = last[k]; i;i=nest[i]){
                    if(val[i]&&h[k]==h[edge[i]]+1){
                        push(i);
                    }
                }
                // 如果push后还有超额流，则说明要回退流量
                if(cap[k]){
                    relabel(k); 
                }
            }
        }
    }
    return;
}

// 主函数
int main(){
    cin >> n >> m >> s >> t;
    int u, v, w;
    for (int i = 0;i<m;i++){
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }
    hlpp();
    cout << cap[t] << endl;
    return 0;
}