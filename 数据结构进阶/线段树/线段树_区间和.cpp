#include<bits/stdc++.h>
using namespace std;

// ���ͨ�õ��߶���ģ�壬�������������

// ��ʼ���߶����Ĵ�С���߶�����С���ڵ��ڴ��洢Ԫ�ص��ı����ɱ�֤�洢����Ԫ��
// ��Ҫע������߶����ĸ��ڵ���Ϊ1��������Ϊ����ʹ����rt<<1��ʾ���ӣ�rt<<1|1��ʾ�Һ���
// ������ڵ�Ϊ0����ô��Ҫ�������Ƚϸ��ӵķ�ʽ�������Һ��ӣ�ʱ�临�Ӷ�΢�ߡ�
const int  N=400010;
long long duan[N];// �߶�������
long long lazy[N];// �������飬����洢����������µ�ֵ��Ҳ���߶���ʵ��nlognʱ�临�ӶȵĹؼ�
long long arr[N];

// ���º�������Ϊ���º�������ʹ�ã�Ϊ�˱���������ĸ��ʣ����ｫ�÷��������һ��ģ�庯����
// ������;���߶�����Ҳ����ͨ���޸�������ֶ�ʵ�֡�
void up(int rt){
    duan[rt]=duan[rt<<1]+duan[rt<<1|1];
    return;
}

// ��ʼ�������߶���
// �������߶����õݹ�ķ�ʽʵ�֣���Լ��������
// �����߶���ʱͨ���������䣬���ϵݹ�ķ�ʽʵ��
void build(int l,int r,int rt){
    if(l==r){
        duan[rt]=arr[l];
        return;
    }
    int m=(l+r)/2;
    // �ݹ齫��벿�ֽ����߶���
    build(l,m,rt<<1);
    // �ݹ齫�Ұ벿�ֽ����߶���
    build(m+1,r,rt<<1|1);
    // ֻ�����ҵݹ�����������߶����ڵ��ֵ������ȷ�ģ���ʱ�����ϴ��ݣ�������ǰ�߶����ڵ��ֵ
    up(rt);
    return ;
}

// �����޸ģ�ʵ���߶�����nlognʱ�临�Ӷ����޸�����Ͳ�������͵�Ŀ��
void down(int ln, int rn, int rt){
    // �����µ�ֵ��Ϊ0����Ϊ�߶������ǴӸ��ڵ㵽�ӽڵ㲻���³����µ�
    // ����������³�������ʵҲ�ǴӸ��ڵ����ӽڵ������
    if(lazy[rt]){
        // ����ʱҪ���Խڵ��ϵ��������������ֵ���߶�������������Ҫ��д
        duan[rt<<1]+=lazy[rt]*ln;
        duan[rt<<1|1]+=lazy[rt]*rn;
        // ��ϸ��������
        lazy[rt<<1]+=lazy[rt];
        lazy[rt<<1|1]+=lazy[rt];
        lazy[rt]=0;
    }
    return;
}

// �޸�Ԫ�أ��߶�����֧����ɾԪ�أ�ֻ֧���޸�Ԫ��
// �����޸�
void update(int x, int v, int l, int r, int rt){
    if(l==r){
        // �Ѿ���ѯ��Ԫ�أ���ֱ������ϸ
        duan[rt]+=v;
        return;

    }
    int m=(l+r)/2;
    // �����¸���ǰ���ȶ��Ը���
    down(m-l+1,r-m,rt);
    // �ݹ�����߶��������Һ��ӽڵ�
    if(x<=m)update(x,v,l,m,rt<<1);
    else update(x,v,m+1,r,rt<<1|1);
    up(rt);
    return;
}

// ������£�����
void update(int x,int y, int v, int l, int r, int rt){
    // �����ǰ�߶����ڵ��Ӧ������[l,r]����������������ڲ�[x,y]���������µݹ飬ֱ�Ӹ���
    if(x<=l&&y>=r){
        duan[rt]+=(long long)(r-l+1)*v;
        // ����û�м������¸��£�����Ҫ���¶������������ֵ
        lazy[rt]+=v;
        return ;
    }
    int m=(l+r)/2;
    // ���³������Ը���
    down(m-l+1,r-m,rt);
    // ��Ҫ�жϴ����������Ƿ��ڶ��ֺ���������ĸ��Ƿ�Χ��
    if(x<=m)update(x,y,v,l,m,rt<<1);
    if(y>m)update(x,y,v,m+1,r,rt<<1|1);
    up(rt);
    return;
}

// ��ѯ
long long query(int x,int y, int l,int r,int rt){
    // ��ǰ�ڵ��Ӧ�����䣬��Ҫ��ѯ����ķ�Χ�ڣ�ֱ�ӷ��ظ�ֵ
    if(x<=l&&y>=r){
        return duan[rt];
    }
    long long ans=0;
    int m=(l+r)/2;
    // ���³������Ը���
    down(m-l+1,r-m,rt);
    if(x<=m)ans+=query(x,y,l,m,rt<<1);
    if(y>m)ans+=query(x,y,m+1,r,rt<<1|1);
    // ���ﲻ��Ҫ�ٸ����߶����ڵ��ϵ�ֵ�ˣ�ֻ��Ҫֱ�ӷ��ؼ���
    return ans;
}

// ���Ե�ַ��https://www.luogu.com.cn/problem/P3372
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // ��ʼ�������߶�������
    build(0,n-1,1);
    // �߶�����̬���²���
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

