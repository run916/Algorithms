#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int,vector<int>,greater<int>> que;
    int n;
    while(cin>>n){
        int p,d;
        vector<vector<int>> arr(n,vector<int>(2));
        for(int i=0;i<n;i++){
            scanf("%d %d",&p,&d);
            arr[i][0]=d;
            arr[i][1]=p;
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(que.size()<arr[i][0])que.push(arr[i][1]);
            else{
                if(arr[i][1]>que.top()){
                    que.pop();
                    que.push(arr[i][1]);
                }
            }
        }
        int ans=0;
        for(;!que.empty();que.pop()){
            ans+=que.top();
        }
        cout<<ans<<endl;
    }
}

//思路：
//第二种思想与第一种本质上是一样的，但是更容易证明其正确性。
//第二种思想是我们将所有的任务按照结束时间排序
//然后我们从结束时间从小到大扫描数组，并用一个优先级队列维持到目前为止选择执行的任务。 
//如果当前数组中的元素小于某个任务的截止时间，那么该任务一定可以被处理，我们直接把其加入到优先级队列中
//如果当前优先级队列中的元素大于当前扫描到元素的截止时将，那么如果该任务的收益大于优先级队列中的某个任务
//交换执行的两个任务一定更优，这样直到所有元素扫描完以后，优先级队列中维持的就是收益最大时应该执行的任务 
