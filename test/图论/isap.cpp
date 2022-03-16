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
    val[cnt] = w;
    nest[cnt] = last[u];
    last[u] = cnt;
    cnt++;
    return;
}

int s,t;
int d[N];
int gap[N];
queue<int> que;




int main(){

}