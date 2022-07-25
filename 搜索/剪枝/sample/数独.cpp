#include<bits/stdc++.h>
using namespace std;

char s[101];
int m=1<<9;
int row[9];
int col[9];
int nin[9];
unordered_map<int,char> has;
int lowbit(int x){
	return x&(-x);
} 
int num[1<<9]; 
bool tag=false;
bool dfs(){
	//排除冗余 
	if(tag)return true;
	//优化搜索顺序 
	int state=0;
	bool tip=false;
	int k;
	for(int i=0;i<81;i++){
		if(s[i]=='.'){
			tip=true;
			int d=row[i/9]|col[i%9]|nin[(i/27)*3+(i%9)/3];
			//记录可以填充位置最少的位置 
			if(num[state]<num[d]){
				state=d;
				k=i;
			}
			if(num[state]==9)return false;
			if(num[state]==8)break;
		}
	}
	if(!tip)return true;
	state^=m;
	for(int i=state;i;i-=lowbit(i)){
		int a=lowbit(i);
		row[k/9]^=a;
		col[k%9]^=a;
		nin[(k/27)*3+(k%9)/3]^=a;
		s[k]=has[a];
		if(dfs()){
			tag=true;
			return true;
		}
		s[k]='.';
		row[k/9]^=a;
		col[k%9]^=a;
		nin[(k/27)*3+(k%9)/3]^=a;
	}	
	return false;
}

int main(){
	//使用状态压缩来保存每一个位置被填充的元素
	//建立数字与二进制为的映射 
	for(int i=0;i<9;i++){
		has[1<<i]=i+'1';
	}
	for(int i=1;i<(1<<9);i++){
		num[i]=num[i-lowbit(i)]+1;
	}
	m-=1;
	while(true){
		tag=false;
		scanf("%s",&s);
		if(s[0]=='e')break;
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		memset(nin,0,sizeof(nin));
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(s[i*9+j]=='.')continue;
				int k=s[i*9+j]-'1';
				row[i]|=(1<<k);
				col[j]|=(1<<k);
				nin[i/3*3+j/3]|=(1<<k);
			}
		}
		//深度优先搜素
		dfs(); 
		printf("%s\n",s);		
	} 

	return 0;
}
