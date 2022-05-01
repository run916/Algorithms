#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int edge[N];
int nest[N];
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
    int n, m;
    cin >> n >> m;
    int u, v, w;
    for(int i=0;i<n;i++){
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
}