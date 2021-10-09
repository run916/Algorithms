#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        // 考虑后效性的单调队列问题
        int n=s.length();
        stack<char> stack;
        int sum=0;
        for(int i=0;i<n;i++){
            if(s[i]==letter)sum++;
        }
        int now=0;// 记录当前栈中letter的数目
        for(int i=0;i<n;i++){
            // 考虑三个因素
            for(;!stack.empty() && stack.top()>s[i] && stack.size()+n-i>k;){
                if(stack.top()==letter){
                    if(now+sum>repetition){
                        stack.pop();
                        now--;
                    }else{
                        break;
                    }
                }else{
                    stack.pop();
                }
            }
            // 添加元素,但是由于要维持letter的数量，所以这里要保证留给后续letter的位置充足
            // 维持字符数目不超过k，这里要保证now的值不是负数
            if(stack.size()-min(now,repetition)+repetition>=k){
                // 普通元素的数量已经达到了标准，那么此时不应该在往单调队列中加入普通元素
                if(s[i]==letter){
                    // 如果待加入的元素是letter
                    if(now<repetition){
                        stack.push(s[i]);
                        // 更新now的值
                        now++;
                    }
                }

            }else{
                // 元素数量还不够时，那么直接插入即可
                stack.push(s[i]);
                // 更新now的值
                if(s[i]==letter){
                    now++;
                }
            }
            if(s[i]==letter){
                // 不管这个字符有没有添加到最终的结果中，sum记录的是后续的字符数目。
                sum--;
            }
        }
        string ans="";
        for(;!stack.empty();stack.pop()){
            ans+=stack.top();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};