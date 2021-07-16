class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        //用两个优先级队列模拟。
        //按照时间进行模拟
        priority_queue<pair<int,int>> que;//空闲服务器队列
        int n=servers.size();
        for(int i=0;i<n;i++)que.emplace(-servers[i],-i);
        int m=tasks.size();
        vector<int> ans(m);
        queue<int> user;
        priority_queue<pair<int,int>> pro;//处理任务的优先级队列
        for(int i=0;i<m;i++){
            //先将本时隙结束的任务加入到空闲服务器优先级队列中
            for(;!pro.empty();){
                if(i==-pro.top().first){
                    que.emplace(-servers[-pro.top().second],pro.top().second);
                    pro.pop();
                }else break;
            }
            if(i<m){
                //前m个时隙，我们每到一个时隙加入一个任务。
                user.push(i);
            }else{
                if(user.empty())break;
            }
            for(;!user.empty();){//安排需要处理的用户任务
                int k=user.front();
                if(!que.empty()){//当有空闲服务器时，可以安排。
                    ans[k]=-que.top().second;//将权重最小，下标最小的服务器安排给队头的用户。
                    pro.emplace(-(i+tasks[k]),que.top().second);
                    que.pop();
                    user.pop();
                }else break;
            }
        }
        while(!user.empty()){
            //先将本时隙结束的任务加入到空闲服务器优先级队列中
            int tmp=pro.top().first;
            for(;!pro.empty();){
                if(tmp==pro.top().first){
                    que.emplace(-servers[-pro.top().second],pro.top().second);
                    pro.pop();
                }else break;
            }
            for(;!user.empty();){//安排需要处理的用户任务
                int k=user.front();
                if(!que.empty()){//当有空闲服务器时，可以安排。
                    ans[k]=-que.top().second;//将权重最小，下标最小的服务器安排给队头的用户。
                    pro.emplace(-(-tmp+tasks[k]),que.top().second);
                    que.pop();
                    user.pop();
                }else break;
            }
        }
        return ans;
    }
};
