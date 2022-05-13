// https://leetcode.cn/problems/the-skyline-problem/submissions/
#include<bits/stdc++.h>
using namespace std;


// 线段树解法
const int N=100010;
int duan[N];
int lazy[N];
int num[N];

void up(int rt){
    duan[rt]=max(duan[rt<<1],duan[rt<<1|1]);
    return;
}

void build(int l,int r,int rt){
    if(l==r){
        duan[rt]=num[rt];
        return;
    }
    int m=(l+r)/2;
    // 递归建立左子树
    build(l,m,rt<<1);
    // 递归建立右子树
    build(m+1,r,rt<<1|1);
    // 左右子树值更新后，更新当前节点的值
    up(rt);
    return;
}

// 自顶向下更新，惰性修改
void down(int ln,int rn,int rt){
    if(lazy[rt]>0){
        // 先更新线段树节点值
        duan[rt<<1]=max(duan[rt<<1],lazy[rt]);
        duan[rt<<1|1]=max(duan[rt<<1|1],lazy[rt]);
        // 然后将子节点的惰性标记更新
        lazy[rt<<1]=max(lazy[rt<<1],lazy[rt]);
        lazy[rt<<1|1]=max(lazy[rt<<1|1],lazy[rt]);
        lazy[rt]=0;
    }
    return;
}

// 区间更新
void update(int x,int y,int v,int l,int r,int rt){
    if(x<=l&&r<=y){
        duan[rt]=max(duan[rt],v);
        lazy[rt]=max(v,lazy[rt]);
        return;
    }
    int m=(l+r)/2;
    down(m-l+1,r-m,rt);
    if(x<=m){
        update(x,y,v,l,m,rt<<1);
    }
    if(y>m){
        update(x,y,v,m+1,r,rt<<1|1);
    }
    up(rt);
    return;
}

int query(int x,int y,int l,int r,int rt){
    if(x<=l&&r<=y){
        return duan[rt];
    }
    int ans=-1;
    int m=(l+r)/2;
    down(m-l+1,r-m,rt);
    if(x<=m){
        ans=max(ans,query(x,y,l,m,rt<<1));
    }
    if(y>m){
        ans=max(ans,query(x,y,m+1,r,rt<<1|1));
    }
    return ans;
}

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& build) {
        // 离散化
        memset(duan,0,sizeof(duan));
        memset(lazy,0,sizeof(lazy));
        int n=build.size();
        set<int> set;
        for(int i=0;i<n;i++){
            set.insert(build[i][0]);
            set.insert(build[i][1]);
        }
        unordered_map<int,int> has;
        unordered_map<int,int> rehas;
        int cnt=0;
        for(auto &x:set){
            has[x]=cnt;
            rehas[cnt]=x;
            cnt++;
        }
        int m=set.size();
        // 插入元素
        for(int i=0;i<n;i++){
            // 线段树根节点序号为1，是为了便于使用rt<<1|1操作。
            // 更新时应该更新成为左闭右开的形式。
            update(has[build[i][0]],has[build[i][1]]-1,build[i][2],0,m-1,1);
        }
        // 查询每个分界点的最大值
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            int d=query(i,i,0,m-1,1);
            if(!ans.empty()&&d==ans[ans.size()-1][1]){
                continue;
            }
            ans.push_back({rehas[i],d});
        }
        return ans;
    }
};