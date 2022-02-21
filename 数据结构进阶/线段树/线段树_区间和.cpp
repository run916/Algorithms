#include<bits/stdc++.h>
using namespace std;

// 最简单通用的线段树模板，这里仅做回忆用

// 初始化线段树的大小，线段树大小大于等于待存储元素的四倍即可保证存储所有元素
// 需要注意的是线段树的根节点编号为1，这是因为我们使用了rt<<1标示左孩子，rt<<1|1标示右孩子
// 如果根节点为0，那么需要用其他比较复杂的方式计算左右孩子，时间复杂多微高。
const int  N=400010;
long long duan[N];// 线段树数组
long long lazy[N];// 惰性数组，里面存储的是区间更新的值，也是线段树实现nlogn时间复杂度的关键
long long arr[N];

// 更新函数，因为更新函数会多次使用，为了避免代码出错的概率，这里将该方法抽象出一个模板函数。
// 其他用途的线段树，也可以通过修改这个部分而实现。
void up(int rt){
    duan[rt]=duan[rt<<1]+duan[rt<<1|1];
    return;
}

// 初始化建立线段树
// 本例中线段树用递归的方式实现，相对简单容易理解
// 建立线段树时通过二分区间，不断递归的方式实现
void build(int l,int r,int rt){
    if(l==r){
        duan[rt]=arr[l];
        return;
    }
    int m=(l+r)/2;
    // 递归将左半部分建立线段树
    build(l,m,rt<<1);
    // 递归将右半部分建立线段树
    build(m+1,r,rt<<1|1);
    // 只有左右递归结束后，左右线段树节点的值才是正确的，此时再向上传递，建立当前线段树节点的值
    up(rt);
    return ;
}

// 惰性修改，实现线段树在nlogn时间复杂度内修改区间和查找区间和的目标
void down(int ln, int rn, int rt){
    // 待更新的值不为0，因为线段树都是从根节点到子节点不断下沉更新的
    // 所以这里的下沉操作其实也是从父节点向子节点扩充的
    if(lazy[rt]){
        // 更新时要乘以节点的系数，如果是求最大值的线段树，这里则需要另写
        duan[rt<<1]+=lazy[rt]*ln;
        duan[rt<<1|1]+=lazy[rt]*rn;
        // 更细惰性数组
        lazy[rt<<1]+=lazy[rt];
        lazy[rt<<1|1]+=lazy[rt];
        lazy[rt]=0;
    }
    return;
}

// 修改元素，线段树不支持增删元素，只支持修改元素
// 单点修改
void update(int x, int v, int l, int r, int rt){
    if(l==r){
        // 已经查询到元素，则直接做更细
        duan[rt]+=v;
        return;

    }
    int m=(l+r)/2;
    // 在向下更新前，先惰性更新
    down(m-l+1,r-m,rt);
    // 递归更新线段树的左右孩子节点
    if(x<=m)update(x,v,l,m,rt<<1);
    else update(x,v,m+1,r,rt<<1|1);
    up(rt);
    return;
}

// 区间更新，重载
void update(int x,int y, int v, int l, int r, int rt){
    // 如果当前线段树节点对应的区间[l,r]，在欲更新区间的内部[x,y]，则不再向下递归，直接更新
    if(x<=l&&y>=r){
        duan[rt]+=(long long)(r-l+1)*v;
        // 由于没有继续向下更新，这里要更新惰性数组里面的值
        lazy[rt]+=v;
        return ;
    }
    int m=(l+r)/2;
    // 先下沉，惰性更新
    down(m-l+1,r-m,rt);
    // 需要判断待更新区间是否在二分后两个区间的覆盖范围内
    if(x<=m)update(x,y,v,l,m,rt<<1);
    if(y>m)update(x,y,v,m+1,r,rt<<1|1);
    up(rt);
    return;
}

// 查询
long long query(int x,int y, int l,int r,int rt){
    // 当前节点对应的区间，在要查询区间的范围内，直接返回该值
    if(x<=l&&y>=r){
        return duan[rt];
    }
    long long ans=0;
    int m=(l+r)/2;
    // 先下沉，惰性更新
    down(m-l+1,r-m,rt);
    if(x<=m)ans+=query(x,y,l,m,rt<<1);
    if(y>m)ans+=query(x,y,m+1,r,rt<<1|1);
    // 这里不需要再更新线段树节点上的值了，只需要直接返回即可
    return ans;
}

// 测试地址：https://www.luogu.com.cn/problem/P3372
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // 初始化建立线段树测试
    build(0,n-1,1);
    // 线段树动态更新测试
    long long s,x,y,k;
    for(int i=0; i<m; i++){
        scanf("%d",&s);
        if(s == 1){
            scanf("%d %d %lld",&x,&y,&k);
            update(x-1,y-1,k,0,n-1,1);
        }else{
            scanf("%d %d",&x,&y);
            cout<<query(x-1,y-1,0,n-1,1)<<endl;
        }
    }
    return 0; 
}

