#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        // 相对而言是个easy题
        int n=num.length();
        int m=n-k;
        stack<char> stack;
        for(int i=0;i<n;i++){
            // 保证元素数量不少于要求
            for(;!stack.empty()&&stack.size() + n - i >m&&stack.top()>num[i];stack.pop());
            // 保证元素数量不超出要求
            if(stack.size()<m){
                stack.push(num[i]);
            }
        }
        string ans="";
        for(;!stack.empty();stack.pop()){
            ans+=stack.top();
        }
        for(int i=m-1;i>=0;i--){
            if(ans[i]=='0')ans.pop_back();
            else break;
        }
        if(ans.length()==0)return "0";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};