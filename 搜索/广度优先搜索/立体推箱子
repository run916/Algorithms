#include<bits/stdc++.h>
using namespace std;

char s[510][510];//地图
struct state{
    int x;
    int y;
    int lie;
};
state st,t;//起点，终点
int n,m;
int vise[510][510][3];//标记数组
queue<state> que;
//与初始状态的设置有关。
const int dx[4]={0,0,-1,1};//用来实现二维矩阵中上下左右的遍历
const int dy[4]={-1,1,0,0};//y坐标的遍历数组

bool valid(int x,int y){
    return x>=0&&y>=0&&x<n&&y<m;
}

bool valid(state next){
    if(!valid(next.x,next.y))return false;
    if(s[next.x][next.y]=='#')return false;
    if(next.lie==0&&s[next.x][next.y]!='.')return false;
    if(next.lie==1&&s[next.x][next.y+1]=='#')return false;
    if(next.lie==2&&s[next.x+1][next.y]=='#')return false;
    return true;
}

void init(){
    //预处理出起点和终点
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='O'){
                t.x=i;
                t.y=j;
                t.lie=0;
                s[i][j]='.';
            }else if(s[i][j]=='X'){
                st.x=i;
                st.y=j;
                st.lie=0;
                for(int k=0;k<4;k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(valid(x,y)&&s[x][y]=='X'){
                        st.x=min(i,x);
                        st.y=min(j,y);
                        st.lie=k<2?1:2;
                        s[i][j]=s[x][y]='.';
                        break;
                    }
                }
            }
            
        }
    }
}

//使用三个转换数组，避免多个if-else繁琐编程。
const int nx[3][4]={{0,0,-2,1},{0,0,-1,1},{0,0,-1,2}};
const int ny[3][4]={{-2,1,0,0},{-1,2,0,0},{-1,1,0,0}};
const int ns[3][4]={{1,1,2,2},{0,0,1,1},{2,2,0,0}};

//bfs遍历
int bfs(){
    memset(vise,-1,sizeof(vise));
    while(que.size())que.pop();
    vise[st.x][st.y][st.lie]=0;
    que.push(st);
    for(;!que.empty();){
        state k=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            state tmp;
            tmp.x=k.x+nx[k.lie][i];
            tmp.y=k.y+ny[k.lie][i];
            tmp.lie=ns[k.lie][i];
            if(!valid(tmp))continue;
            if(vise[tmp.x][tmp.y][tmp.lie]==-1){//尚未访问
                vise[tmp.x][tmp.y][tmp.lie]=vise[k.x][k.y][k.lie]+1;
                que.push(tmp);
                if(tmp.x==t.x&&tmp.y==t.y&&tmp.lie==t.lie)
                    return vise[t.x][t.y][t.lie];
            }
        }
    }
    return -1;//所有可以遍历到的状态已经被遍历一次（vise数组的作用）。
}
int main(){
    while(true){
        cin>>n>>m;
        if(n==0)break;
        for(int i=0;i<n;i++){
            scanf("%s",s[i]);
        }
        init();
        int ans=bfs();
        if(ans==-1)puts("Impossible");
        else cout<<ans<<endl;
    }
    return 0;
}
