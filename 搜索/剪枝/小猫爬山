#include<bits/stdc++.h>
using namespace std;

//另一种搜索方式
//利用回溯的原理，实际上我们可以使用全局数组进行统计，而在边界点更新最优解即可。
int ans=INT_MAX;
int cat[20],cab[20];
int n,w;

void dfs(int k,int cnt){
	//有两种可能，往已经开辟的小车添加猫
	if(k==n){
		ans=min(ans,cnt);
	}
	//最优性剪枝
	if(ans<=cnt)return;
	for(int i=1;i<=cnt;i++){
		if(cab[i]+cat[k]>w)continue; 
		cab[i]+=cat[k];
		dfs(k+1,cnt);
		cab[i]-=cat[k];
	}
	//第二种是新开辟一个缆车
	cab[++cnt]=cat[k];
	dfs(k+1,cnt);
	return; 
} 
int main(){
	cin>>n>>w;
	for(int i=0;i<n;i++)cin>>cat[i];
	//优化搜索顺序
	sort(cat+1,cat+n,[](int& a,int& b){
	    return a>b;
	}); 
	dfs(0,0);
	cout<<ans;
	return 0;
}
