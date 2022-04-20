#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

// http://poj.org/problem?id=1797

const int N = 1010;
int fa[N];
int find(int x){
    return x == fa[x] ? x : fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x = find(x);
    y = find(y);
    fa[x] = y;
    return;
}

struct cmp{
    size_t operator ()(pair<int,int> &a,pair<int,int> &b)const{
        if(a.first>=b.first){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    int t;
    scanf("%d", &t);
    int all = t;
    while(t--){
        // 初始化并查集
        for (int i = 0; i < N;i++){
            fa[i] = i;
        }
        int n, m;
        scanf("%d %d", &n, &m);
        int *u,*v,*w;
        u = new int[m];
        v = new int[m];
        w = new int[m];
        // 默认的优先级队列是大根堆
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> que;
        for (int i = 0;i<m;i++){
            scanf("%d %d %d", &u[i], &v[i], &w[i]);
            que.push(make_pair(w[i], i));
        }
        int ans = INT_MAX;
        while(!que.empty()){
            pair<int, int> k = que.top();
            que.pop();
            if(find(u[k.second])!=find(v[k.second])){
                merge(u[k.second], v[k.second]);
                ans = k.first;
            }
            if(find(1)==find(n)){
                break;
            }
        }
        cout << "Scenario #" << (all - t) << ":" << endl;
        cout << ans << endl;
        cout << endl;
    }
    return 0;
}