#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
int edge[N];
int nest[N];
int val[N];
int last[N];
int cnt = 2;

void add(int u,int v,int w){
    edge[cnt] = v;
    val[cnt] = w;
    nest[cnt] = last[u];
    last[u] = cnt;
    cnt++;
    return;
}

// bfs寻找增广路
int s, t;
int in[N];
bool vise[N];
// 前驱数组，记录节点的前驱边
int pre[N];
queue<int> que;

bool bfs(){
    // 初始化
    while(!que.empty()){
        que.pop();
    }
    memset(vise, false, sizeof(vise));
    in[s] = 1 << 30;
    que.push(s);
    vise[s] = true;
    for (;!que.empty();que.pop()){
        int k = que.front();
        for (int i = last[k]; i;i=nest[i]){
            if(!vise[edge[i]]&&val[i]){
                que.push(edge[i]);
                vise[edge[i]] = true;
                // 记录这条增广路上流入这个节点的最大流是多少
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

// 更新最大流的值
int update(){
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
	int n,m;
	cin>>n>>m>>s>>t;
	int u,v,w;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
		add(v,u,0);
	}
	// 不断尝试寻找增广路，直到不能找到增广路为止。
    long long ans = 0;
    while(bfs()){
		ans+=update();
	}
	cout<<ans;
	return 0;
	
}