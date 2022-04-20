#include<bits/stdc++.h>
using namespace std;

// https://leetcode-cn.com/problems/QO5KpG/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> num;
    void visit(TreeNode* root){
        if(root!=nullptr){
            num.push_back(root->val);
            visit(root->left);
            visit(root->right);
        }
        return;

    }
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        // 排序
        int n=ops.size();
        // 新建立数组，按照区间开始点排序
        vector<vector<int>> op(n+1);
        for(int i=0;i<n;i++){
            op[i].push_back(i);
            op[i].push_back(ops[i][1]);
        }
        // 加哨兵，避免边界条件判断
        op[n].push_back(n);
        op[n].push_back(1e9+1);
        // 排序
        sort(op.begin(),op.end(),[](vector<int>&a,vector<int>&b){
           return a[1]<b[1]; 
        });
        
        n=op.size();
    
        // 首先获得节点编号值
        visit(root);
        // 将所有元素排序
        sort(num.begin(),num.end());
        int len=num.size();
        // 开始遍历
        int ans=0;
        priority_queue<int> que;
        
        int pre=0;
        for(int i=0;i<n;i++){
            if(que.empty()){
                que.emplace(op[i][0]);
                // 将pre和op[i][0]之间的元素未变色，所以直接统计
                for(;pre<len&&num[pre]<op[i][1];pre++){
                    // 如果是染成蓝色，则统计数目加一
                    ans+=1;
                }
            }else{
                for(;pre<len&&num[pre]<op[i][1]&&!que.empty();){
                    int k=que.top();
                    for(;pre<len&&num[pre]<=ops[k][2]&&num[pre]<op[i][1];pre++){
                        if(ops[k][0]==0){
                            // 如果是染成蓝色，则统计数目加一
                            ans++;
                        }
                    }
                    // 对于全部遍历结束的区间，从优先级队列弹出
                    if(pre<len&&num[pre]>ops[k][2]){
                        que.pop();
                    }
                }
                // 遍历到新加入区间的左端点附近后，将该区间加入到优先级队列中
                // 如果que为空，则需要考虑将这一部分点统计进去
                if(que.empty()){
                    for(;pre<len&&num[pre]<op[i][1];pre++){
                        // 如果是染成蓝色，则统计数目加一
                        ans+=1;
                    }                    
                }
                que.push(op[i][0]);
            }
        }
        return len-ans;
    }
};

// 思路：
// 从题意可以看出，对于一个节点的修改，只有最后一次是有用的，所以直观的想法是我们将所有的区间按照左端点从小到大排序，
// 然后通过扫描区间的方式将一个有一个区间加入到优先级队列中，同时在扫描的过程中，每更新一个区间，就要统计这个区间内节点最终的颜色
// 当所有区间扫描结束后，就可以统计出红色节点的数目