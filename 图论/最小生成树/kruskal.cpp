#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int fa[N]; // 记录当前几点在并查集中的父节点
int depth[N];// 当前节点所在并查集对应的树的高度

// 查询时实现路径压缩
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

// 秩优化
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y){
        return;
    }
    if(depth[x]>depth[y]){
        fa[y] = x;
    }else{
        fa[x] = y;
        if (depth[x] == depth[y]) {
            depth[y]++;
        }
    }
    return;
}

int main(){
    // 初始化并查集数组
    for (int i = 0; i <= N; i++){
        fa[i] = i;
    }
    int n, m;
    cin >> n >> m;
    int u[m], v[m], w;
    // 优先级队列，默认是大根堆，这里要使用小根堆实现从小到大排序的功能
    // less大根堆，greater小根堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&u[i],&v[i],&w);
        que.emplace(w, i);
    }
    long long ans = 0;
    int cns = 0;
    // 开始最小生成树算法
    for (; !que.empty(); que.pop()){
        int k = que.top().second;
        if(find(u[k]) != find(v[k])){
            merge(u[k],v[k]);
            ans += que.top().first;
            cns++;
            if(cns == n-1) {
                break;
            }
        }
    }
    if(cns == n-1){
        cout << ans << endl;
    } else {
        cout << "orz" << endl;
    }
    return 0;
}