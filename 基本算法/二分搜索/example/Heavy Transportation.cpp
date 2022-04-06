#include<iostream>
#include<queue>
#include<string.h>
#include<memory>
using namespace std;

// http://poj.org/status

const int N = 1000010;
int edge[N];
int nest[N];
int val[N];
int last[N];
int cnt = 1;

void add(int u,int v,int w){
    edge[cnt] = v;
    val[cnt] = w;
    nest[cnt] = last[u];
    last[u] = cnt;
    cnt++;
    return;
}

int main(){
    int t;
    cin >> t;
    for (int d = 1; d <= t; d++){
        // 初始化邻接链表
        cnt = 1;
        memset(last, 0, sizeof(last));

        // 对单个样例求解最优值
        int n, m;
        cin >> n >> m;
        int u, v, w;
        for (int i = 0; i < m;i++){
            cin >> u >> v >> w;
            add(u, v, w);
            add(v, u, w);
        }
        // bfs遍历
        int l = 1;
        int r = 1000000;
        for (;l<=r;){
            int mi = (l + r) / 2;
            queue<int> que;
            que.push(1);
            bool *vise=new bool[n+1];
            memset(vise, false, (n + 1) * sizeof(bool));
            vise[1] = true;
            for (;!que.empty();){
                int k = que.front();
                que.pop();
                for (int i = last[k]; i;i=nest[i]){
                    if(!vise[edge[i]]&&val[i]>=mi){
                        vise[edge[i]] = true;
                        que.push(edge[i]);
                    }
                }
            }
            if(vise[n]){
                l = mi + 1;
            }else{
                r = mi - 1;
            }
        }
        cout << "Scenario #" << d << ":" << endl;
        cout << l - 1 << endl;
        cout << endl;
    }
    return 0;
}