#include<bits/stdc++.h>
using namespace std;

const int N=3200010;
int trie[N][2];
int cnt=2;
int over[N];

//注意要将所有的数字化为等长的字符串，我们使用STL的bitset来实现。 
void insert(bitset<32> a){
	int p=1;
	//需要注意的是bitset中的0对应的是整数二进制数的最低位。 
	for(int i=31;i>=0;i--){
		if(trie[p][a[i]]==0){
			trie[p][a[i]]=cnt;
			cnt++;
		}
		p=trie[p][a[i]];
	}
	over[p]++;
	return;
}
//可以进行隐式类型转换 
int search(bitset<32> a){
	int p=1;
	bitset<32> ans;
	for(int i=31;i>=0;i--){
		if(trie[p][a[i]]==0){
			ans[i]=a[i]^1;
			p=trie[p][ans[i]];
		}else{
			ans[i]=a[i];
			p=trie[p][a[i]];
		}
	}
	return ans.to_ulong();
}

int main(){
	int n;
	cin>>n;
	int k;
	int ans=0;
	//这里要注意避免整数溢出，所以我们先强制类型转化为long long类型，再隐式转化为int类型，注意这里有截断 
	int m=((long long)1<<32)-1;
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		insert(k);
		ans=max(ans,k^search(k^m));
	}
	cout<<ans;
	return 0;
}
