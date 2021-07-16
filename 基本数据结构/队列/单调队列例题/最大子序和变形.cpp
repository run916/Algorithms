#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	long long num[n+1];
	num[0]=0;
	int a; 
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		num[i]=num[i-1]+a;
	}
	deque<int> que;
	//最大子序和的变形问题 
	//哪里出了问题呢？ 
	long long ans=INT_MIN;
	que.push_back(0);
	for(int i=1;i<=n;i++){
        if(!que.empty()&&que.front()<i-k)que.pop_front();
		ans=max(ans,num[i]-num[que.front()]);
		for(;!que.empty()&&num[que.back()]>=num[i];que.pop_back());
		que.push_back(i);
	}
	cout<<ans;
	return 0;
}
