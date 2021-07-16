#include<bits/stdc++.h>
using namespace std;

//非常典型的一道bfs变形问题。
struct node{
    int x;
    int y;
    node(){};
    node(int a,int b){
        //可以用this指针。
        this->x=a;
        this->y=b;
    };
};
int n,m;
bool vise[510][510];
int d[510][510];
char s[510][510];

int nx[4]={1,1,-1,-1};//四个遍历方向
int ny[4]={1,-1,-1,1};//四个遍历方向
int st[4]={1,0,1,0};//每个遍历方向期望的电线布置方式
int dx[4]={0,0,-1,-1};//遍历的电线在原始数组中坐标
int dy[4]={0,-1,-1,0};//遍历的电线在原始数组中的坐标。
bool check(int x,int y){//检查遍历的位置是否合法，注意可大的点要比电线数组多一维。
    return x>=0&&y>=0&&x<=n&&y<=m;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        //标记数组。
        memset(vise,false,sizeof(vise));
        memset(d,0x3f,sizeof(d));
        for(int i=0;i<n;i++){
            scanf("%s",s[i]);
        }
        deque<node> que;
        que.emplace_back(0,0);
        d[0][0]=0;
        for(;!que.empty();){
            node k=que.front();
            que.pop_front();
            
            if(vise[k.x][k.y])continue;
            vise[k.x][k.y]=true;
            if(k.x==n&&k.y==m)break;
            //cout<<k.x<<" "<<k.y<<" "<<d[k.x][k.y]<<endl;
            for(int i=0;i<4;i++){
                int x=k.x+nx[i];
                int y=k.y+ny[i];
                if(check(x,y)&&!vise[x][y]){//当前节点还没有遍历过。
                    int nx=k.x+dx[i];
                    int ny=k.y+dy[i];
                    int t=(s[nx][ny]=='/'?0:1);
                    if((t^st[i])==0){
                        d[x][y]=d[k.x][k.y];
                        //对于没有产生开销的操作，加入队头。
                        //要想使用emplace_front()必须要有配套的构造函数。
                        que.emplace_front(x,y);
                    }else{
                        if(d[k.x][k.y]+1>=d[x][y])continue;
                        else d[x][y]=d[k.x][k.y]+1;
                        //对于产生了开销的操作，加入队尾。
                        //这样做是维持双端队列里面的距离单调递增的性质。
                        que.emplace_back(x,y);
                    }
                }
            }
        }
        if(vise[n][m]==false)cout<<"NO SOLUTION"<<endl;
        else cout<<d[n][m]<<endl;
    }
    
    return 0;
}
