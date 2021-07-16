#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int trie[N][26];//每个节点有26分叉，因为只考虑小写字母 
//字典树中编号为1的是根节点，所以实际上新插入的点是从2开始编号的。 
int cnt=2;
//这个数组是记录字典树中信息的，也是字典树真正起作用的地方。 
int over[N];

//插入
void insert(string s){
	int n=s.length();
	int p=1;//从根节点开始向下搜索类似于记录了路径的路径搜索。 
	for(int i=0;i<n;i++){
		char ch=s[i]-'a';
		//对于原来树中不存在的边，我们新插入一个节点。 
		if(trie[p][ch]==0){
			trie[p][ch]=cnt;
			cnt++;
		} 
		//继续向下搜索 
		p=trie[p][ch];
	}
	//记录信息 
	over[p]++;
	return ; 
} 

bool serarch(string s){
	int n=s.length();
	int p=1;
	for(int i=0;i<n;i++){
		char ch=s[i]-'a';
		if(trie[p][ch]==0)return false;
		p=trie[p][ch];
	}
	if(over[p])return true;
	return false;
}
