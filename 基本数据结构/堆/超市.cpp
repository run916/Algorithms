#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		priority_queue<int> que;
		vector<vector<int>> arr(n,vector<int>(2));
		for(int i=0;i<n;i++){
			scanf("%d %d",&arr[i][0],&arr[i][1]);
		}
		sort(arr.begin(),arr.end(),[](vector<int>&a,vector<int>&b){
			return a[1]<b[1];	
		});
		int now=n-1;
		int ans=0;
		for(int i=10000;i>0;i--){
			for(;now>=0&&arr[now][1]==i;now--){
				que.push(arr[now][0]); 
			}
			if(!que.empty()){
				ans+=que.top();
				que.pop();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

//思路：
//思路就是先将所有的任务按照结束时间排序，然后倒序遍历每一天，每一天的操作如下：
//如果有截止日期是今天的，那么将该任务添加到优先级队列中。
//如果当前队列中没有任务，说明此时没有任务可以安排，我们直接跳过
//当优先级队列不为空，说明今天可以安排任务，按照贪心的原则，我们应当把价值高的任务先安排。
//贪心的正确性可以通过微扰或者反证的思想证明。 
