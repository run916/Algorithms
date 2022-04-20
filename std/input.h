#include<bits/stdc++.h>
// #include<>查找的是标准库文件所在目录。 #include ""首先查找当前目录，查找到后会遮蔽include<>查找到的头文件，查找不到会去查标准库文件所在的目录
// #include "c:\Users\windows\Desktop\Algorithm\Algorithms\std\input.h"
using namespace std;

long long to_int(string s){
    int n = s.length();
    long long ans = 0;
    if(s[0]=='-'){
        for (int i = 1; i < s.length(); i ++){
            ans *= 10;
            ans += (s[i] - '0');
        }
        ans = -ans;
    }else{
        for (int i = 0; i < s.length(); i ++){
            ans *= 10;
            ans += (s[i] - '0');
        }
    }
    return ans;
}

vector<int> transfer(string s){
    vector<int> ans;
    int n = s.length();
    string str = "";
    for (int i = 0; i < n; i ++){
        if(s[i]==' '||s[i]=='['){
            continue;
        }
        if(s[i]==','||s[i]==']'){
            ans.push_back(to_int(str));
            str = "";
        }else{
            str += s[i];
        }
    }
    return ans;
}

vector<vector<int>> two_dimension(string s){
    vector<vector<int>> ans;
    vector<int> tmp;
    int n = s.length();
    string str = "";
    for (int i = 0;i < n;i ++){
        if(s[i]==' '||s[i]=='['){
            continue;
        }
        if(s[i]==','){
            if(str.size()>0){
                tmp.push_back(to_int(str));
            }
            str = "";
            continue;
        }
        if(s[i]==']'){
            if(str.size()>0){
                tmp.push_back(to_int(str));
            }
            str = "";
            if(tmp.size()>0){
                ans.push_back(tmp);
            }
            tmp.clear();
        }else{
            str += s[i];
        }
    }
    return ans;
}

string del_quote(string s){
    int n = s.length();
    return s.substr(1, n - 2);
}