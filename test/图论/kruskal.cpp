#include<bits/stdc++.h>
using namespace std;

// 先写并查集
const int N = 100010;
int fa[N];

// 并查集的路径压缩
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
// 当需要时，还可以进行秩优化
void merge(int x,int y){
    x = find(x);
    y = find(y);
    fa[x] = y;
    return;
}


int main(){
    // 初始化并查集
    for (int i = 0; i < N;i++){
        fa[i] = i;
    }
    int n, m;
    cin >> n >> m;
    int u[m], v[m], w;
    // 建立优先级队列
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;

    for (int i = 0; i < m; i++){
        cin >> u[i] >> v[i] >> w;
        que.emplace(w, i);
    }
    // 开始算法
    int cnt = 0;
    long long ans = 0;
    for (; !que.empty();que.pop()){
        int k = que.top().second;
        // 寻找安全边
        if(find(u[k])!=find(v[k])){
            merge(u[k], v[k]);
            cnt++;
            ans += que.top().first;
            if(cnt==n-1){
                break;
            }
        }
    }
    if(cnt==n-1){
        cout << ans << endl;
    }else{
        cout << "orz" << endl;
    }
    return 0;
}