#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        // 如何做呢？
        int n=s.length();
        // 用来记录一个字符的最后一个出现的位置
        unordered_map<char,int> hash;
        for(int i=0;i<n;i++){
            hash[s[i]]=i;
        }
        // 做单调栈
        stack<char> stack;
        // 标记当前元素是否已经出现在栈中
        bool vise[26];
        memset(vise,false,sizeof(vise));
        // 记录单调栈中的元素
        for(int i=0;i<n;i++){
            if(vise[s[i]-'a'])continue;
            for(;!stack.empty()&&stack.top()>s[i];stack.pop()){
                // 如果当前要删除的元素是最后一个，则不删除
                if(hash[stack.top()]<i)break;
                vise[stack.top()-'a']=false;
            }
            stack.push(s[i]);
            vise[s[i]-'a']=true;
        }
        string ans="";
        for(;!stack.empty();stack.pop()){
            ans+=stack.top();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};