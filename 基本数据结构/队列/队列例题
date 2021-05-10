#include<bits/stdc++.h>
using namespace std;

int main(){
	int k=0;
	while(true){
		int n;
		cin>>n;
		if(n==0)break;
		k++;
		cout<<"Scenario #"<<k<<endl;
		queue<int> q[n+1];
		unordered_map<int,int> hash;
		unordered_map<int,int> has;
		for(int i=1;i<=n;i++){
			int m;
			cin>>m;
			int a;
			for(int j=0;j<m;j++){
				scanf("%d",&a);
				hash[a]=i;
			}
		} 
		string s;
		int a;
		while(true){
			cin>>s;
			if(s[0]=='D'){
				cout<<q[q[0].front()].front()<<endl;
				q[q[0].front()].pop();
				has[q[0].front()]--;
				if(has[q[0].front()]==0)q[0].pop();
			}
			if(s[0]=='E'){
				scanf("%d",&a);
				if(has[hash[a]]==0){
					q[0].push(hash[a]);
				}
				q[hash[a]].push(a);
				has[hash[a]]++;
			}
			if(s=="STOP")break;
		}
		cout<<endl;
	}
	return 0;
}
